#ifndef TGEPARTICLE_H
#define TGEPARTICLE_H

#include "linearAlgebra/tgeVector3T.h"

class tgeParticle
{
public:
    tgeParticle();
	~tgeParticle();

	const tgeVector3f&	getX() const;
	const tgeVector3f&	getV() const;
	const tgeVector3f&	getForce() const;
	float				getMass() const;

	void setX(const tgeVector3f&);
	void setV(const tgeVector3f&);

	void clearForce();
	void addForce(const tgeVector3f&);

private:
	tgeVector3f	m_x;
	tgeVector3f	m_v;
	tgeVector3f	m_force;
	float		m_mass;
};

#endif // TGEPARTICLE_H
