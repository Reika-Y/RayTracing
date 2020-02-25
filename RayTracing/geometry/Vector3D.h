#pragma once

// 3次元ベクトルクラス
template<typename T>
struct Vector3D
{
	// コンストラクタ
	Vector3D() :x(0), y(0), z(0) {};
	Vector3D(T inx, T iny, T inz) :x(inx), y(iny), z(inz) {};

	// メンバ変数
	T x;
	T y;
	T z;

	// ゼロ初期化
	void Zero(void);

	// 代入演算子
	Vector3D& operator = (const Vector3D& v);

	// 添え字演算子
	T& operator [] (int i);

	// 比較演算子
	bool operator == (const Vector3D& v)const;
	bool operator != (const Vector3D& v)const;
	bool operator <	 (const Vector3D& v)const;
	bool operator <= (const Vector3D& v)const;
	bool operator >  (const Vector3D& v)const;
	bool operator >= (const Vector3D& v)const;

	// 単項演算子
	Vector3D& operator += (const Vector3D& v);
	Vector3D& operator -= (const Vector3D& v);
	Vector3D& operator *= (T k);
	Vector3D& operator /= (T k);
	Vector3D operator + () const;
	Vector3D operator - () const;

	// ベクトルの大きさを返します
	float Magnitude()const;

	// 正規化(大きさを１に)します
	void Normalize();

	// 正規化ベクトルを返します
	Vector3D Normalized();
};

// ベクトルの演算
// Vector3D + Vector3D
template<typename T>
Vector3D<T> operator + (const Vector3D<T>& u, const Vector3D<T>& v);

// Vector3D - Vector3D
template<typename T>
Vector3D<T> operator - (const Vector3D<T>& u, const Vector3D<T>& v);

// T * Vector3D
template<typename T>
Vector3D<T> operator * (const T k, const Vector3D<T>& v);

// Vector3D * T 
template<typename T>
Vector3D<T> operator * (const Vector3D<T>& v, const T k);

// Vector3D * Vector3D
template<typename T>
Vector3D<T> operator * (const Vector3D<T>& u, const Vector3D<T>& v);

// Vector3D / T
template<typename T>
Vector3D<T> operator / (const Vector3D<T>& v, const T k);

// Vector3D / Vector3D
template<typename T>
Vector3D<T> operator / (const Vector3D<T>& u, const Vector3D<T>& v);

// Vector3D % int
template<typename T>
Vector3D<T> operator % (const Vector3D<T>& v, const int k);

// 内積
template<typename T1, typename T2>
float Dot(const Vector3D<T1>& u, const Vector3D<T2>& v);

// 外積
template<typename T>
Vector3D<T> Cross(const Vector3D<T>& u, const Vector3D<T>& v);

typedef Vector3D<int> Vector3;			// 整数型ベクトル
typedef Vector3D<float> Vector3f;		// 実数型ベクトル

typedef Vector3 Position3;
typedef Vector3f Position3f;

typedef Vector3f Color;

#include "./details/Vector3D.h"