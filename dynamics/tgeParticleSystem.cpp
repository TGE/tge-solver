#include "tgeParticleSystem.h"

#include "dynamics/tgeEmitter.h"
#include "linearAlgebra/tgeVector3T.hpp"
#include "utils/tgeUtils.h"

#include <algorithm>

#include <boost/bind.hpp>

tgeParticleSystem::tgeParticleSystem() :
	m_time(0.f),
	m_viscosity(0.5f)
{}

tgeParticleSystem::~tgeParticleSystem()
{
	std::for_each(m_particles.begin(), m_particles.end(), Delete() );
	m_particles.clear();
}

size_t tgeParticleSystem::getDim() const
{
	return 6 * m_particles.size();
}

const std::vector<tgeParticle*>& tgeParticleSystem::getParticles() const
{
	return m_particles;
}

void tgeParticleSystem::getState(float* stateOut) const
{
	for (	tParts::const_iterator it = m_particles.begin();
			it != m_particles.end();
			++it )
	{
		const tgeVector3f& x = (*it)->getX();
		const tgeVector3f& v = (*it)->getV();

		*(stateOut++) = x[0];
		*(stateOut++) = x[1];
		*(stateOut++) = x[2];
		*(stateOut++) = v[0];
		*(stateOut++) = v[1];
		*(stateOut++) = v[2];
	}
}

void tgeParticleSystem::setState(const float* stateIn) const
{
	for (	tParts::const_iterator it = m_particles.begin();
			it != m_particles.end();
			++it )
	{
		float tmpx = *(stateIn++);
		float tmpy = *(stateIn++);
		float tmpz = *(stateIn++);

		const tgeVector3f x(tmpx, tmpy, tmpz);

		tmpx = *(stateIn++);
		tmpy = *(stateIn++);
		tmpz = *(stateIn++);

		const tgeVector3f v(tmpx, tmpy, tmpz);

		(*it)->setX(x);
		(*it)->setV(v);
	}
}

void tgeParticleSystem::clearForces() const
{
	std::for_each(	m_particles.begin(), m_particles.end(),
					std::mem_fun(&tgeParticle::clearForce) );
}

void tgeParticleSystem::computeForces() const
{
	const tgeVector3f& gravity = m_force.value();

	//--- GRAVITY
	for (	tParts::const_iterator it = m_particles.begin();
			it != m_particles.end();
			++it )
	{
		(*it)->addForce( (*it)->getMass() * gravity );
	}

	//--- VISCOSITY
	for (	tParts::const_iterator it = m_particles.begin();
			it != m_particles.end();
			++it )
	{
		(*it)->addForce( -m_viscosity * (*it)->getV() );
	}

//	std::for_each(	m_particles.begin(), m_particles.end(),
//					boost::bind(&tgeParticle::addForce, _1, boost::ref(gravity)) );
}

void tgeParticleSystem::getDerivative(float* derivOut) const
{
	for (	tParts::const_iterator it = m_particles.begin();
			it != m_particles.end();
			++it )
	{
		const tgeVector3f& v = (*it)->getV();

		// x' = v
		*(derivOut++) = v[0];
		*(derivOut++) = v[1];
		*(derivOut++) = v[2];

		const tgeVector3f& f = (*it)->getForce();
		const float m = (*it)->getMass();

		// v' = f/m
		*(derivOut++) = f[0]/m;
		*(derivOut++) = f[1]/m;
		*(derivOut++) = f[2]/m;
	}
}

void tgeParticleSystem::stepTo(const float dT)
{
	//FIXME
	m_particles.push_back(tgeEmitter::generate());

	clearForces();
	computeForces();
	eulerStep(dT);
	m_time+=dT;
}

void tgeParticleSystem::eulerStep(const float dT)
{
	const size_t dim = getDim();

	float* deriv = new float[dim];
	getDerivative(deriv);

	float* state = new float[dim];
	getState(state);

	for (size_t i = 0; i < dim; ++i)
	{
		state[i] += dT * deriv[i];
	}

	setState(state);

	delete [] deriv;
	delete [] state;
}
