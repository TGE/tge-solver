#ifndef TGE_UTILS_H
#define TGE_UTILS_H

#include <vector>
#include <cstdlib>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template<typename T>
inline T sqr( const T& aX )
{
	return aX * aX;
}

template<typename T>
inline T clamp( T aValue, T aLower, T aUpper )
{
	return	( aValue < aLower ) ? aLower :
			( aValue > aUpper ) ? aUpper : aValue;
}

template<typename T>
inline T rand( const T min, const T max)
{
	return ( rand()/(T)RAND_MAX ) * (max-min) + min;
}

template<typename T>
void zero( std::vector<T>& aVector )
{
	aVector.assign( aVector.size(), 0 );
}

class Delete
{
	public :

		template <typename T>
		void operator()(T* aT)
		{
			delete aT;
		}
};

#endif
