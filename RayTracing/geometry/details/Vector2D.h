#pragma once
#include <cmath>
#include "../Vector2D.h"

// ゼロ初期化
template<typename T>
void Vector2D<T>::Zero(void)
{
	x = 0;
	y = 0;
}

// 代入演算子
template<typename T>
Vector2D<T> & Vector2D<T>::operator=(const Vector2D<T> & v)
{
	x = v.x;
	y = v.y;
	return *this;
}

// 添え字演算子
template<typename T>
T & Vector2D<T>::operator[](int i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	return x;
}

// 比較演算子
template<typename T>
bool Vector2D<T>::operator==(const Vector2D & v) const
{
	return (x == v.x && y == v.y);
}
template<typename T>
bool Vector2D<T>::operator!=(const Vector2D & v) const
{
	return !(x == v.x && y == v.y);
}
template<typename T>
bool Vector2D<T>::operator<(const Vector2D & v) const
{
	return (x < v.x && y < v.y);
}
template<typename T>
bool Vector2D<T>::operator<=(const Vector2D & v) const
{
	return (x <= v.x && y <= v.y);
}
template<typename T>
bool Vector2D<T>::operator>(const Vector2D & v) const
{
	return (x > v.x && y > v.y);
}
template<typename T>
bool Vector2D<T>::operator>=(const Vector2D & v) const
{
	return (x >= v.x && y >= v.y);
}

// 単項演算子
template<typename T>
Vector2D<T> & Vector2D<T>::operator+=(const Vector2D & v)
{
	x += v.x;
	y += v.y;
	return *this;
}
template<typename T>
Vector2D<T> & Vector2D<T>::operator-=(const Vector2D & v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}
template<typename T>
Vector2D<T> & Vector2D<T>::operator*=(int k)
{
	x *= k;
	y *= k;
	return *this;
}
template<typename T>
Vector2D<T> & Vector2D<T>::operator/=(int k)
{
	x /= k;
	y /= k;
	return *this;
}
template<typename T>
Vector2D<T> Vector2D<T>::operator+() const
{
	return *this;
}
template<typename T>
Vector2D<T> Vector2D<T>::operator-() const
{
	return Vector2D(-x, -y);
}

// ベクトルの大きさを返します
template<typename T>
float Vector2D<T>::Magnitude() const
{
	return sqrtf(x * x + y * y);
}

// 正規化(大きさを１に)します
template<typename T>
void Vector2D<T>::Normalize()
{
	float mag = Magnitude();
	x /= mag;
	y /= mag;
}

// 正規化ベクトルを返します
template<typename T>
Vector2D<T> Vector2D<T>::Normalized()
{
	float mag = Magnitude();
	return Vector2D(x /= mag, y /= mag);
}

// ベクトルの演算
// Vector2D + Vector2D
template<typename T>
Vector2D<T> operator+(const Vector2D<T>& u, const Vector2D<T>& v)
{
	return Vector2D<T>(u.x + v.x, u.y + v.y);
}
// Vector2D - Vector2D
template<typename T>
Vector2D<T> operator-(const Vector2D<T>& u, const Vector2D<T>& v)
{
	return Vector2D<T>(u.x - v.x, u.y - v.y);
}

// int * Vector2D
template<typename T>
Vector2D<T> operator * (const int k, const Vector2D<T>& v)
{
	return Vector2D<T>(k * v.x, k * v.y);
}

// Vector2D * int 
template<typename T>
Vector2D<T> operator * (const Vector2D<T>& v, const int k)
{
	return Vector2D<T>(v.x * k, v.y * k);
}

// Vector2D * Vector2D
template<typename T>
Vector2D<T> operator * (const Vector2D<T>& u, const Vector2D<T>& v)
{
	return Vector2D<T>(u.x * v.x, u.y * v.y);
}

// Vector2D / int
template<typename T>
Vector2D<T> operator / (const Vector2D<T>& v, const int k)
{
	return Vector2D<T>(v.x / k, v.y / k);
}

// Vector2D / Vector2D
template<typename T>
Vector2D<T> operator / (const Vector2D<T>& u, const Vector2D<T>& v)
{
	return Vector2D<T>(u.x / v.x, u.y / v.y);
}

// Vector2D % int
template<typename T>
Vector2D<T> operator % (const Vector2D<T> & v, const int k)
{
	return Vector2D<T>(v.x % k, v.y % k);
}

// 内積
template<typename T1, typename T2>
float Dot(const Vector2D<T1>& u, const Vector2D<T2>& v)
{
	return (u.x * v.x + u.y * v.y);
}

// 外積
template<typename T>
float Cross(const Vector2D<T>& u, const Vector2D<T>& v)
{
	return (u.x * v.y - u.y * v.x);
}
