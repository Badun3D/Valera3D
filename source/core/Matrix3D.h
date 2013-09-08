#ifndef _V3D_MATRIX_3D_H_
#define _V3D_MATRIX_3D_H_

#include "Vector2D.h"

namespace v3d
{
namespace core
{
	template <class T>
	class TMatrix3D
	{
	public:
		
		TMatrix3D();
		TMatrix3D( const TMatrix3D<T>& other );
		TMatrix3D( const T* matrix );
		TMatrix3D( const T& m0, const T& m1, const T& m2,  
				  const T& m3, const T& m4, const T& m5,  
				  const T& m6, const T& m7, const T& m8 );
		
		T&				operator () ( u32 row, u32 col );
		const T&		operator () ( u32 row, u32 col )				const; 
		T&				operator [] ( u32 index ); 
		const T&		operator [] ( u32 index )						const; 
		TMatrix3D<T>&	operator =  ( const T& scalar );
		bool			operator == ( const TMatrix3D<T>& other )		const;
		bool			operator != ( const TMatrix3D<T>& other )		const;
		TMatrix3D<T>	operator +  ( const TMatrix3D<T>& other )		const;
		TMatrix3D<T>&	operator += ( const TMatrix3D<T>& other );
		TMatrix3D<T>	operator -  ( const TMatrix3D<T>& other )		const;
		TMatrix3D<T>&	operator -= ( const TMatrix3D<T>& other );
		TMatrix3D<T>	operator *  ( const TMatrix3D<T>& other )		const;
		TMatrix3D<T>&	operator *= ( const TMatrix3D<T>& other );
		TMatrix3D<T>	operator *  ( const T& scalar )					const;
		TMatrix3D<T>&	operator *= ( const T& scalar );

		void			set( const T* matrix );

		const T*		getPtr()										const; 
		T*				getPtr(); 
		
		void			makeIdentity();
		bool			isIdentity()									const;

		bool			makeInverse();
		bool			getInverse( TMatrix3D<T>& outMatrix )			const;
	
		void			makeTransposed();								
		TMatrix3D<T>	getTransposed()									const;

		void			setTranslation( const TVector2D<T>& translation );
		TVector2D<T>	getTranslation()								const;

		void			setRotation( const T& angle );
		T				getRotation()									const;

		void			preScale( const TVector2D<T>& scale );
		void			postScale( const TVector2D<T>& scale );
		void			setScale( const TVector2D<T>& scale );

		TVector2D<T>	getScale()										const;
	
	private:
	
		T m_matrix[9];
	};

	template <class T>
	TMatrix3D<T>::TMatrix3D( )
	{
		makeIdentity();
	}

	template <class T>
	TMatrix3D<T>::TMatrix3D( const T* matrix )
	{
		memcpy( m_matrix, matrix, sizeof( T ) * 9 );
	}

	template <class T>
	TMatrix3D<T>::TMatrix3D( const T& m0,  const T& m1,  const T& m2,  
							 const T& m3,  const T& m4,  const T& m5,  
							 const T& m6,  const T& m7,  const T& m8 )
	{
		m_matrix[0] = m0;
		m_matrix[1] = m1;
		m_matrix[2] = m2;
		m_matrix[3] = m3;
		m_matrix[4] = m4;
		m_matrix[5] = m5;
		m_matrix[6] = m6;
		m_matrix[7] = m7;
		m_matrix[8] = m8;
	}
				
	template <class T>
	TMatrix3D<T>::TMatrix3D( const TMatrix3D<T>& other )
	{
		*this = other;
	}

	template <class T>
	T& TMatrix3D<T>::operator () (  u32 row, u32 col ) 
	{ 
		return m_matrix[row * 3 + col]; 
	}

	template <class T>
	const T& TMatrix3D<T>::operator () ( u32 row, u32 col ) const 
	{ 
		return m_matrix[row * 3 + col]; 
	}

	template <class T>
	T& TMatrix3D<T>::operator [] ( u32 index ) 
	{ 
		return m_matrix[index]; 
	}

	template <class T>
	const T& TMatrix3D<T>::operator [] ( u32 index ) const 
	{ 
		return m_matrix[index]; 
	}

	template <class T>
	TMatrix3D<T>& TMatrix3D<T>::operator = ( const T& scalar )
	{
		for ( s32 i = 0; i < 9; ++i )
		{
			m_matrix[i] = scalar;
		}
		return *this;
	}

	template <class T>
	const T* TMatrix3D<T>::getPtr() const 
	{ 
		return m_matrix; 
	}

	template <class T>
	T* TMatrix3D<T>::getPtr() 
	{ 
		return m_matrix; 
	}

	template <class T>
	bool TMatrix3D<T>::operator == ( const TMatrix3D<T> &other ) const
	{
		for ( s32 i = 0; i < 9; ++i )
		{
			if ( m_matrix[i] != other.m_matrix[i] )
			{
				return false;
			}
		}
		return true;
	}

	template <class T>
	bool TMatrix3D<T>::operator != ( const TMatrix3D<T> &other ) const
	{
		return !( *this == other );
	}

	template <class T>
	TMatrix3D<T> TMatrix3D<T>::operator + ( const TMatrix3D<T>& other ) const
	{
		TMatrix3D<T> temp;

		temp[0] = m_matrix[0] + other[0];
		temp[1] = m_matrix[1] + other[1];
		temp[2] = m_matrix[2] + other[2];
		temp[3] = m_matrix[3] + other[3];
		temp[4] = m_matrix[4] + other[4];
		temp[5] = m_matrix[5] + other[5];
		temp[6] = m_matrix[6] + other[6];
		temp[7] = m_matrix[7] + other[7];
		temp[8] = m_matrix[8] + other[8];	

		return temp;
	}

	template <class T>
	TMatrix3D<T>& TMatrix3D<T>::operator += ( const TMatrix3D<T>& other )
	{
		m_matrix[0] += other[0];
		m_matrix[1] += other[1];
		m_matrix[2] += other[2];
		m_matrix[3] += other[3];
		m_matrix[4] += other[4];
		m_matrix[5] += other[5];
		m_matrix[6] += other[6];
		m_matrix[7] += other[7];
		m_matrix[8] += other[8];
	
		return *this;
	}

	template <class T>
	TMatrix3D<T> TMatrix3D<T>::operator - ( const TMatrix3D<T>& other ) const
	{
		TMatrix3D<T> temp;

		temp[0] = m_matrix[0] - other[0];
		temp[1] = m_matrix[1] - other[1];
		temp[2] = m_matrix[2] - other[2];
		temp[3] = m_matrix[3] - other[3];
		temp[4] = m_matrix[4] - other[4];
		temp[5] = m_matrix[5] - other[5];
		temp[6] = m_matrix[6] - other[6];
		temp[7] = m_matrix[7] - other[7];
		temp[8] = m_matrix[8] - other[8];

		return temp;
	}

	template <class T>
	TMatrix3D<T>& TMatrix3D<T>::operator -= ( const TMatrix3D<T>& other )
	{
		m_matrix[0] -= other[0];
		m_matrix[1] -= other[1];
		m_matrix[2] -= other[2];
		m_matrix[3] -= other[3];
		m_matrix[4] -= other[4];
		m_matrix[5] -= other[5];
		m_matrix[6] -= other[6];
		m_matrix[7] -= other[7];
		m_matrix[8] -= other[8];

		return *this;
	}

	template <class T>
	TMatrix3D<T> TMatrix3D<T>::operator * ( const TMatrix3D<T>& other ) const
	{
		TMatrix3D<T> temp;

		const T* m1 = m_matrix;
		const T* m2 = other.m_matrix;

		temp.m_matrix[0] = m1[0] * m2[0] + m1[3] * m2[1] + m1[6] * m2[2];
		temp.m_matrix[1] = m1[1] * m2[0] + m1[4] * m2[1] + m1[7] * m2[2];
		temp.m_matrix[2] = m1[2] * m2[0] + m1[5] * m2[1] + m1[8] * m2[2];
		temp.m_matrix[3] = m1[0] * m2[3] + m1[3] * m2[4] + m1[6] * m2[5];
		temp.m_matrix[4] = m1[1] * m2[3] + m1[4] * m2[4] + m1[7] * m2[5];
		temp.m_matrix[5] = m1[2] * m2[3] + m1[5] * m2[4] + m1[8] * m2[5];
		temp.m_matrix[6] = m1[0] * m2[6] + m1[3] * m2[7] + m1[6] * m2[8];
		temp.m_matrix[7] = m1[1] * m2[6] + m1[4] * m2[7] + m1[7] * m2[8];
		temp.m_matrix[8] = m1[2] * m2[6] + m1[5] * m2[7] + m1[8] * m2[8];

		return temp;
	}

	template <class T>
	TMatrix3D<T>& TMatrix3D<T>::operator *= ( const TMatrix3D<T>& other )
	{
		TMatrix3D<T> temp ( *this );
		
		const T* m1 = temp.m_matrix;
		const T* m2 = other.m_matrix;
		
		m_matrix[0] = m1[0] * m2[0] + m1[3] * m2[1] + m1[6] * m2[2];
		m_matrix[1] = m1[1] * m2[0] + m1[4] * m2[1] + m1[7] * m2[2];
		m_matrix[2] = m1[2] * m2[0] + m1[5] * m2[1] + m1[8] * m2[2];
		m_matrix[3] = m1[0] * m2[3] + m1[3] * m2[4] + m1[6] * m2[5];
		m_matrix[4] = m1[1] * m2[3] + m1[4] * m2[4] + m1[7] * m2[5];
		m_matrix[5] = m1[2] * m2[3] + m1[5] * m2[4] + m1[8] * m2[5];
		m_matrix[6] = m1[0] * m2[6] + m1[3] * m2[7] + m1[6] * m2[8];
		m_matrix[7] = m1[1] * m2[6] + m1[4] * m2[7] + m1[7] * m2[8];
		m_matrix[8] = m1[2] * m2[6] + m1[5] * m2[7] + m1[8] * m2[8];
		
		return *this;
	}

	template <class T>
	TMatrix3D<T> TMatrix3D<T>::operator * ( const T& scalar ) const
	{
		TMatrix3D<T> temp;

		temp[0] = m_matrix[0] * scalar;
		temp[1] = m_matrix[1] * scalar;
		temp[2] = m_matrix[2] * scalar;
		temp[3] = m_matrix[3] * scalar;
		temp[4] = m_matrix[4] * scalar;
		temp[5] = m_matrix[5] * scalar;
		temp[6] = m_matrix[6] * scalar;
		temp[7] = m_matrix[7] * scalar;
		temp[8] = m_matrix[8] * scalar;

		return temp;
	}

	template <class T>
	TMatrix3D<T>& TMatrix3D<T>::operator *= ( const T& scalar )
	{
		m_matrix[0] *= scalar;
		m_matrix[1] *= scalar;
		m_matrix[2] *= scalar;
		m_matrix[3] *= scalar;
		m_matrix[4] *= scalar;
		m_matrix[5] *= scalar;
		m_matrix[6] *= scalar;
		m_matrix[7] *= scalar;
		m_matrix[8] *= scalar;
		
		return *this;
	}

	template <class T>
	void TMatrix3D<T>::set( const T* matrix )
	{
		if( matrix )
		memcpy( m_matrix, matrix, 9 * sizeof( T ) );
	}

	template <class T>
	void TMatrix3D<T>::makeIdentity()
	{
		m_matrix[1] = m_matrix[2] = m_matrix[3] =
		m_matrix[5] = m_matrix[6] = m_matrix[7] = (T)0;
		m_matrix[0] = m_matrix[4] = m_matrix[8] = (T)1;
	}

	template <class T>
	bool TMatrix3D<T>::isIdentity() const
	{
		if ( !isEquals( m_matrix[0], (T)1 ) ||
			 !isEquals( m_matrix[4], (T)1 ) ||
			 !isEquals( m_matrix[8], (T)1 ) )
		{
			return false;
		}
		for ( s32 i = 0; i < 3; ++i )
		{
			for ( s32 j = 0; j < 3; ++j )
			{
				if ( ( j != i ) && ( !isZero( ( *this )( i , j ) ) ) )
				{
					return false;
				}
			}
		}
		return true;
	}

	template <class T>
	void TMatrix3D<T>::setTranslation( const TVector2D<T>& translation )
	{
		m_matrix[6] = translation.x;
		m_matrix[7] = translation.y;
		return *this;
	}

	template <class T>
	TVector2D<T> TMatrix3D<T>::getTranslation() const
	{
		return TVector2D<T>( m_matrix[6], m_matrix[7] );
	}

	template <class T>
	void TMatrix3D<T>::setRotation( const T& angle )
	{
		const T cy = cos( angle );
		const T sy = sin( angle );

		m_matrix[0] = (T)( cy );
		m_matrix[1] = (T)(-sy );

		m_matrix[2] = (T)( sy );
		m_matrix[3] = (T)( cy );
	}

	template <class T>
	T TMatrix3D<T>::getRotation() const
	{
		const TMatrix3D<T> &mat = *this;

		f64 sin = clamp( ( f64 )mat( 1, 0 ), -1.0, 1.0 );
		f64 cos = clamp( ( f64 )mat( 0, 0 ), -1.0, 1.0 );
		T angle = ( T )atan2( sin, cos ) ;

		if ( angle < 0.0 )
		{
			angle += k_2pi;
		}

		return angle;
	}

	template <class T>
	inline void TMatrix3D<T>::preScale( const TVector2D<T>& scale )
	{
		m_matrix[0] *= scale.x;
		m_matrix[1] *= scale.y;

		m_matrix[3] *= scale.x;
		m_matrix[4] *= scale.y;

		m_matrix[6] *= scale.x;
		m_matrix[7] *= scale.y;
	}

	template <class T>
	inline void TMatrix3D<T>::postScale( const TVector2D<T>& scale )
	{
		m_matrix[0] *= scale.x;
		m_matrix[1] *= scale.x;

		m_matrix[3] *= scale.y;
		m_matrix[4] *= scale.y;

		m_matrix[6] *= scale.x;
		m_matrix[7] *= scale.y;
	}

	template <class T>
	void TMatrix3D<T>::setScale( const TVector2D<T>& scale )
	{
		m_matrix[0] = scale.x;
		m_matrix[4] = scale.y;
	}

	template <class T>
	TVector2D<T> TMatrix3D<T>::getScale() const
	{
		TVector2D<T> scale;
		scale.x = TVector2D<T>( m_matrix[0],m_matrix[1] ).length();
		scale.y = TVector2D<T>( m_matrix[3],m_matrix[4] ).length();
		return scale;
	}

	template <class T>
	bool TMatrix3D<T>::makeInverse()
	{
		TMatrix3D<T> temp;

		if ( getInverse( temp ) )
		{
			*this = temp;
			return true;
		}

		return false;
	}

	template <class T>
	bool TMatrix3D<T>::getInverse( TMatrix3D<T>& outMatrix ) const
	{
		return false; //wrong algorithm
		f64 t0 = m_matrix[10] * m_matrix[15] - m_matrix[11] * m_matrix[14];
		f64 t1 = m_matrix[6] * m_matrix[15] - m_matrix[7] * m_matrix[14];
		f64 t2 = m_matrix[6] * m_matrix[11] - m_matrix[7] * m_matrix[10];
		f64 t3 = m_matrix[2] * m_matrix[15] - m_matrix[3] * m_matrix[14];
		f64 t4 = m_matrix[2] * m_matrix[11] - m_matrix[3] * m_matrix[10];
		f64 t5 = m_matrix[2] * m_matrix[7] - m_matrix[3] * m_matrix[6];

		f64 t6 = m_matrix[8] * m_matrix[13] - m_matrix[9] * m_matrix[12];
		f64 t7 = m_matrix[4] * m_matrix[13] - m_matrix[5] * m_matrix[12];
		f64 t8 = m_matrix[4] * m_matrix[9] - m_matrix[5] * m_matrix[8];
		f64 t9 = m_matrix[0] * m_matrix[13] - m_matrix[1] * m_matrix[12];
		f64 t10 = m_matrix[0] * m_matrix[9] - m_matrix[1] * m_matrix[8];
		f64 t11 = m_matrix[0] * m_matrix[5] - m_matrix[1] * m_matrix[4];

		f64 det = t0 * t11 - t1 * t10 + t2 * t9 + t3 * t8 - t4 * t7 + t5 * t6;
		
		if ( isZero( det ) )
		{
			return false;
		}

		det = 1.0 / det;
		T ft0 = (T)(t0 * det);
		T ft1 = (T)(t1 * det);
		T ft2 = (T)(t2 * det);
		T ft3 = (T)(t3 * det);
		T ft4 = (T)(t4 * det);
		T ft5 = (T)(t5 * det);
		T ft6 = (T)(t6 * det);
		T ft7 = (T)(t7 * det);
		T ft8 = (T)(t8 * det);
		T ft9 = (T)(t9 * det);
		T ft10 = (T)(t10 * det);
		T ft11 = (T)(t11 * det);

		outMatrix.m_matrix[0] = m_matrix[5] * ft0 - m_matrix[9] * ft1 + m_matrix[13] * ft2;
		outMatrix.m_matrix[1] = m_matrix[9] * ft3 - m_matrix[1] * ft0 - m_matrix[13] * ft4;
		outMatrix.m_matrix[2] = m_matrix[1] * ft1 - m_matrix[5] * ft3 + m_matrix[13] * ft5;
		outMatrix.m_matrix[3] = m_matrix[5] * ft4 - m_matrix[1] * ft2 - m_matrix[9] * ft5;

		outMatrix.m_matrix[4] = m_matrix[8] * ft1 - m_matrix[4] * ft0 - m_matrix[12] * ft2;
		outMatrix.m_matrix[5] = m_matrix[0] * ft0 - m_matrix[8] * ft3 + m_matrix[12] * ft4;
		outMatrix.m_matrix[6] = m_matrix[4] * ft3 - m_matrix[0] * ft1 - m_matrix[12] * ft5;
		outMatrix.m_matrix[7] = m_matrix[0] * ft2 - m_matrix[4] * ft4 + m_matrix[8] * ft5;

		outMatrix.m_matrix[8] = m_matrix[7] * ft6 - m_matrix[11] * ft7 + m_matrix[15] * ft8;
		outMatrix.m_matrix[9] = m_matrix[11] * ft9 - m_matrix[3] * ft6 - m_matrix[15] * ft10;
		outMatrix.m_matrix[10] = m_matrix[3] * ft7 - m_matrix[7] * ft9 + m_matrix[15] * ft11;
		outMatrix.m_matrix[11] = m_matrix[7] * ft10 - m_matrix[3] * ft8 - m_matrix[11] * ft11;

		outMatrix.m_matrix[12] = m_matrix[10] * ft7 - m_matrix[6] * ft6 - m_matrix[14] * ft8;
		outMatrix.m_matrix[13] = m_matrix[2] * ft6 - m_matrix[10] * ft9 + m_matrix[14] * ft10;
		outMatrix.m_matrix[14] = m_matrix[6] * ft9 - m_matrix[2] * ft7 - m_matrix[14] * ft11;
		outMatrix.m_matrix[15] = m_matrix[2] * ft8 - m_matrix[6] * ft10 + m_matrix[10] * ft11;

		return true;
	}


	template <class T>
	void TMatrix3D<T>::makeTransposed()
	{
		TMatrix3D<T> temp( *this );
		
		m_matrix[0] = temp.m_matrix[0];
		m_matrix[1] = temp.m_matrix[3];
		m_matrix[2] = temp.m_matrix[6];
		
		m_matrix[3] = temp.m_matrix[1];
		m_matrix[4] = temp.m_matrix[4];
		m_matrix[5] = temp.m_matrix[7];
		
		m_matrix[6] = temp.m_matrix[2];
		m_matrix[7] = temp.m_matrix[5];
		m_matrix[8] = temp.m_matrix[8];
	}

	template <class T>
	TMatrix3D<T> TMatrix3D<T>::getTransposed() const
	{
		TMatrix3D<T> temp;

		temp.m_matrix[0] = m_matrix[0];
		temp.m_matrix[1] = m_matrix[3];
		temp.m_matrix[2] = m_matrix[6];
		
		temp.m_matrix[3] = m_matrix[1];
		temp.m_matrix[4] = m_matrix[4];
		temp.m_matrix[5] = m_matrix[7];
		
		temp.m_matrix[6] = m_matrix[2];
		temp.m_matrix[7] = m_matrix[5];
		temp.m_matrix[8] = m_matrix[8];

		return temp;
	}

	typedef TMatrix3D<f32> Matrix3D;

}
}

#endif
