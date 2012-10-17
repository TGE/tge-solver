#include "tgeGravityForce.h"

#include "linearAlgebra/tgeVector3T.hpp"

tgeGravityForce::tgeGravityForce()
{}

const tgeVector3f& tgeGravityForce::value() const
{
	static const tgeVector3f _value(0.f, -9.8f, 0.f);
	return _value;
}
