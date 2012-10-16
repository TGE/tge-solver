#ifndef TGE_UTILS_H
#define TGE_UTILS_H

#include <vector>

// fix Microsoft VC++ oddities
#ifdef min // MS defines min as a macro, making it impossible to use the identifier for functions etc.
#undef min
#endif
#ifdef max // MS defines max as a macro, making it impossible to use the identifier for functions etc.
#undef max
#endif
#ifndef M_PI // MS fails to define M_PI in the standard math header file
#define M_PI 3.14159265358979323846
#endif

template<typename T>
inline T sqr( const T& aX )
{
	return aX * aX;
}

template<typename T>
inline T min( const T& a1, const T& a2, const T& a3 )
{
	return ( a1 < a2 ) ? min( a1, a3 ) : min( a2, a3 );
}

template<typename T>
inline T max( const T& a1, const T& a2, const T& a3 )
{
	return ( a1 > a2 ) ? max( a1, a3 ) : max( a2, a3 );
}

template<typename T>
inline T clamp( T aValue, T aLower, T aUpper )
{
	return	( aValue < aLower ) ? aLower :
			( aValue > aUpper ) ? aUpper : aValue;
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
