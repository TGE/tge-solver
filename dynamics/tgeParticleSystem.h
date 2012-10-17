#ifndef TGEPARTICLESYSTEM_H
#define TGEPARTICLESYSTEM_H

#include "tgeParticle.h"
#include "tgeGravityForce.h"

#include <vector>

class tgeParticleSystem
{
public:
    tgeParticleSystem();
	~tgeParticleSystem();

	size_t	getDim() const;

	void	stepTo(const float);

	const std::vector<tgeParticle*>& getParticles() const;

private:

	void	getState(float*) const;
	void	setState(const float*) const;
	void	getDerivative(float*) const;

	void	clearForces() const;
	void	computeForces() const;

	void	eulerStep(const float);

	typedef std::vector<tgeParticle*>	tParts;
	tParts	m_particles;

	tgeGravityForce	m_force;

	float	m_time;
	float	m_viscosity;
};

#endif // TGEPARTICLESYSTEM_H
