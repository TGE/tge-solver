#ifndef TGE_VECTOR3_T_HPP
#define TGE_VECTOR3_T_HPP

#include "tgeVector3T.h"

#include <cmath>
//#include <iostream>
// #include "tgeUtils.h"

template<typename T>
tgeVector3T<T>::tgeVector3T()
{
	_data[0] = _data[1] = _data[2] = T(0);
}

template<typename T>
tgeVector3T<T>::tgeVector3T( const T aT )
{
	_data[0] = _data[1] = _data[1] = aT;
}

template<typename T>
tgeVector3T<T>::tgeVector3T( const tgeVector3T<T>& aVector )
{
	_data[0] = aVector[0];
	_data[1] = aVector[1];
	_data[2] = aVector[2];
}

template<typename T>
tgeVector3T<T>::tgeVector3T( const T aT0, const T aT1, const T aT2 )
{
	_data[0] = aT0;
	_data[1] = aT1;
	_data[2] = aT2;
}

template<typename T>
tgeVector3T<T>::~tgeVector3T()
{}

template<typename T>
const T*	tgeVector3T<T>::data() const
{
	return _data;
}

template<typename T>
T&	tgeVector3T<T>::operator[]( const size_t i )
{
	return _data[i];
}

template<typename T>
const T&	tgeVector3T<T>::operator[]( const size_t i ) const
{
	return _data[i];
}

template<typename T>
tgeVector3T<T>	tgeVector3T<T>::operator+=( const tgeVector3T<T>& aVector )
{
	_data[0] += aVector[0];
	_data[1] += aVector[1];
	_data[2] += aVector[2];
	return *this;
}

template<typename T>
tgeVector3T<T> tgeVector3T<T>::operator-=( const tgeVector3T<T>& aVector )
{
	_data[0] -= aVector[0];
	_data[1] -= aVector[1];
	_data[2] -= aVector[2];
	return *this;
}

template<typename T>
tgeVector3T<T>	tgeVector3T<T>::operator*=( const T& aT )
{
	_data[0] *= aT;
	_data[1] *= aT;
	_data[2] *= aT;
	return *this;
}

template<typename T>
tgeVector3T<T>	tgeVector3T<T>::operator/=( const T& aT )
{
	_data[0] /= aT;
	_data[1] /= aT;
	_data[2] /= aT;
	return *this;
}

template<typename T>
T	tgeVector3T<T>::mag2() const
{
	return	_data[0] * _data[0] +
			_data[1] * _data[1] +
			_data[2] * _data[2];
}

template<typename T>
T	tgeVector3T<T>::mag() const
{
	return std::sqrt( mag2() );
}

// STATIC

template<typename T>
inline	T	dist2( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return	sqr( aV1[0] - aV2[0] ) +
			sqr( aV1[1] - aV2[1] ) +
			sqr( aV1[2] - aV2[2] );
}

template<typename T>
inline T	dist( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return std::sqrt( dist2( aV1, aV2 ) );
}

template<typename T>
inline	bool	operator==( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return	aV1[0] == aV2[0] && aV1[1] == aV2[1] && aV1[2] == aV2[2];
}

template<typename T>
inline	bool	operator!=( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return	aV1[0] != aV2[0] || aV1[1] != aV2[1] || aV1[2] != aV2[2];
}

template<typename T>
inline	tgeVector3T<T>	operator-( const tgeVector3T<T>& aVector )
{
	return tgeVector3T<T>( -aVector[0], -aVector[1], -aVector[2] );
}

template<typename T>
inline	tgeVector3T<T>	operator+( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return tgeVector3T<T>( aV1[0] + aV2[0], aV1[1] + aV2[1], aV1[2] + aV2[2] );
}

template<typename T>
inline	tgeVector3T<T>	operator-( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return tgeVector3T<T>( aV1[0] - aV2[0], aV1[1] - aV2[1], aV1[2] - aV2[2] );
}

template<typename S, typename T>
inline	tgeVector3T<T>	operator*( const tgeVector3T<T>& aVector, const S aS )
{
	return tgeVector3T<T>(	aS * aVector[0], aS * aVector[1], aS * aVector[2] );
}

template<typename S, typename T>
inline	tgeVector3T<T>	operator*( const S aS, const tgeVector3T<T>& aVector )
{
	return tgeVector3T<T>(	aS * aVector[0], aS * aVector[1], aS * aVector[2] );
}

template<typename S, typename T>
inline	tgeVector3T<T>	operator/( const tgeVector3T<T>& aVector, const S aS )
{
	return tgeVector3T<T>( aVector[0] / aS, aVector[1] / aS, aVector[2] / aS );
}

template<typename T>
inline	T	dot( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return aV1[0] * aV2[0] + aV1[1] * aV2[1] + aV1[2] * aV2[2];
}

template<typename T>
inline	T	cross( const tgeVector3T<T>& aV1, const tgeVector3T<T>& aV2 )
{
	return tgeVector3T<T>(	aV1[1] * aV2[2] - aV1[2] * aV2[1],
							aV1[2] * aV2[0] - aV1[0] * aV2[2],
							aV1[0] * aV2[1] - aV1[1] * aV2[0] );
}

template<typename T>
inline void	normalize( tgeVector3T<T>& aVector )
{
	aVector /= aVector.mag();
}

template<typename T>
inline	tgeVector3T<T>	normalized( const tgeVector3T<T>& aVector )
{
	return aVector / aVector.mag();
}

template<typename T>
inline	std::ostream	&operator<<( std::ostream& aOut, const tgeVector3T<T>& aVector )
{
	return aOut << aVector[0] << ' ' << aVector[1] << ' ' << aVector[2];
}

template<typename T>
inline	std::istream	&operator>>( std::istream& aIn, tgeVector3T<T>& aVector )
{
	return aIn >> aVector[0] >> aVector[1] >> aVector[2];
}


#endif
