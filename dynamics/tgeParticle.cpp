#include "tgeParticle.h"

#include "linearAlgebra/tgeVector3T.hpp"

tgeParticle::tgeParticle() :
	m_x(0.f, 0.f, 0.f),
	m_v(0.f, 0.f, 0.f),
	m_force(0.f, 0.f, 0.f),
	m_mass(1.f)
{}

tgeParticle::~tgeParticle()
{}

const tgeVector3f& tgeParticle::getX() const
{
	return m_x;
}

const tgeVector3f& tgeParticle::getV() const
{
	return m_v;
}

const tgeVector3f& tgeParticle::getForce() const
{
	return m_force;
}

float tgeParticle::getMass() const
{
	return m_mass;
}

void tgeParticle::setX(const tgeVector3f& x)
{
	m_x = x;
}

void tgeParticle::setV(const tgeVector3f& v)
{
	m_v = v;
}

void tgeParticle::clearForce()
{
	m_force[0] = 0.f;
	m_force[1] = 0.f;
	m_force[2] = 0.f;
}

void tgeParticle::addForce(const tgeVector3f& force)
{
	m_force += force;
}
