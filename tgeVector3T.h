#ifndef TGE_VECTOR3_T_H
#define TGE_VECTOR3_T_H

#include <iostream>

template<typename T>
class tgeVector3T
{
	public :
		
		tgeVector3T();
		tgeVector3T( const T );
		tgeVector3T( const T, const T, const T );
		tgeVector3T( const tgeVector3T& );
		~tgeVector3T();
		
		const T*	data() const;

		T&				operator[]( const size_t );
		const T&		operator[]( const size_t ) const;
		tgeVector3T<T>	operator+=( const tgeVector3T<T>& );
		tgeVector3T<T>	operator-=( const tgeVector3T<T>& );
		tgeVector3T<T>	operator*=( const T& );
		tgeVector3T<T>	operator/=( const T& );

		T	mag2() const;
		T	mag() const;

	private :

		T			_data[3];
};

typedef tgeVector3T<float> tgeVector3f;
typedef tgeVector3T<double> tgeVector3d;

#endif
