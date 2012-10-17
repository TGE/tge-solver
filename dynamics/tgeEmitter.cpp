#include "tgeEmitter.h"

#include "tgeParticle.h"
#include "utils/tgeUtils.h"

tgeEmitter::tgeEmitter()
{
}

tgeParticle* tgeEmitter::generate()
{
	static const tgeVector3f __x(0.f, 10.f, 0.f);

	tgeParticle* particle = new tgeParticle();
	particle->setX(__x);

	const float mag = 5.f;

	const float vx = rand(-mag, mag);
	const float vy = rand(-mag, mag);
	const float vz = rand(-mag, mag);

	particle->setV(tgeVector3f(vx, vy, vz));

	return particle;
}
