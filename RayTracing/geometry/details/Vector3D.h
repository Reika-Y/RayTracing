#pragma once
#include <cmath>
#include "../Vector3D.h"

// ゼロ初期化
template <typename T>
void Vector3D<T>::Zero(void)
{
	x = 0;
	y = 0;
	z = 0;
}

// 代入演算子
template <typename T>
Vector3D<T>& Vector3D<T>::operator =(const Vector3D<T>& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

// 添え字演算子
template <typename T>
T& Vector3D<T>::operator [] (int i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else if (i == 2)
	{
		return z;
	}
	return x;
}

// 比較演算子
template <typename T>
bool Vector3D<T>::operator == (const Vector3D& v)const
{
	return (x == v.x && y == v.y && z == v.z);
}
template <typename T>
bool Vector3D<T>::operator != (const Vector3D& v)const
{
	return !(x == v.x && y == v.y && z == v.z);
}
template <typename T>
bool Vector3D<T>::operator < (const Vector3D& v)const
{
	return (x < v.x && y < v.y && z < v.z);
}
template <typename T>
bool Vector3D<T>::operator <= (const Vector3D& v)const
{
	return (x <= v.x && y <= v.y && z <= v.z);
}
template <typename T>
bool Vector3D<T>::operator > (const Vector3D& v)const
{
	return (x > v.x && y > v.y && z > v.z);
}
template <typename T>
bool Vector3D<T>::operator >= (const Vector3D& v)const
{
	return (x >= v.x && y >= v.y && z >= v.z);
}

// 単項演算子
template <typename T>
Vector3D<T>& Vector3D<T>::operator+= (const Vector3D<T>& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
template <typename T>
Vector3D<T>& Vector3D<T>::operator-= (const Vector3D<T>& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
template <typename T>
Vector3D<T>& Vector3D<T>::operator*= (T k)
{
	x *= k;
	y *= k;
	z *= k;
	return *this;
}
template <typename T>
Vector3D<T>& Vector3D<T>::operator/= (T k)
{
	x /= k;
	y /= k;
	z /= k;
	return *this;
}
template <typename T>
Vector3D<T> Vector3D<T>::operator+ ()const
{
	return *this;
}
template <typename T>
Vector3D<T> Vector3D<T>::operator- ()const
{
	return Vector3D(-x, -y, -z);
}

// ベクトルの大きさを返します
template <typename T>
float Vector3D<T>::Magnitude(void)const
{
	return sqrtf(x * x + y * y + z * z);
}

// 正規化(大きさを１に)します
template<typename T>
void Vector3D<T>::Normalize()
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

// 正規化ベクトルを返します
template<typename T>
Vector3D<T> Vector3D<T>::Normalized()
{
	float mag = Magnitude();
	return Vector3D(x /= mag, y /= mag, z /= mag);
}

// ベクトルの演算
// Vector3D + Vector3D
template<typename T>
Vector3D<T> operator + (const Vector3D<T>& u, const Vector3D<T>& v)
{
	return Vector3D<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}

// Vector3D - Vector3D
template<typename T>
Vector3D<T> operator - (const Vector3D<T>& u, const Vector3D<T>& v)
{
	return Vector3D<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}

// T * Vector3D
template<typename T>
Vector3D<T> operator * (const T k, const Vector3D<T>& v)
{
	return Vector3D<T>(k * v.x, k * v.y, k * v.z);
}

// Vector3D * T 
template<typename T>
Vector3D<T> operator * (const Vector3D<T>& v, const T k)
{
	return Vector3D<T>(v.x * k, v.x * k, v.z * k);
}

// Vector3D * Vector3D
template<typename T>
Vector3D<T> operator * (const Vector3D<T>& u, const Vector3D<T>& v)
{
	return Vector3D<T>(u.x * v.x, u.y * v.y, u.z * v.z);
}

// Vector3D / T
template<typename T>
Vector3D<T> operator / (const Vector3D<T>& v, const T k)
{
	return Vector3D<T>(v.x / k, v.y / k, v.z / k);
}

// Vector3D / Vector3D
template<typename T>
Vector3D<T> operator / (const Vector3D<T>& u, const Vector3D<T>& v)
{
	return Vector3D<T>(u.x / v.x, u.y / v.y, u.z / v.z);
}

// Vector3D % int
template<typename T>
Vector3D<T> operator % (const Vector3D<T>& v, const int k)
{
	return Vector3D<T>(v.x % k, v.y % k, v.z % k);
}

// 内積
template<typename T1, typename T2>
float Dot(const Vector3D<T1>& u, const Vector3D<T2>& v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

// 外積
template<typename T>
Vector3D<T> Cross(const Vector3D<T>& u, const Vector3D<T>& v)
{
	return Vector3D<T>((u.y * v.z - u.z * v.y), (u.z * v.x - u.x * v.z), (u.x * v.y - u.y * v.x));
}