#pragma once

// 2次元ベクトルクラス
template<typename T>
struct Vector2D
{
	// コンストラクタ
	Vector2D() :x(0), y(0) {};
	Vector2D(T inx, T iny) :x(inx), y(iny) {};

	// メンバ変数
	T x;
	T y;

	// ゼロ初期化
	void Zero(void);

	// 代入演算子
	Vector2D &operator = (const Vector2D& v);

	// 添え字演算子
	T &operator [] (int i);

	// 比較演算子
	bool operator == (const Vector2D& v)const;
	bool operator != (const Vector2D& v)const;
	bool operator <	 (const Vector2D& v)const;
	bool operator <= (const Vector2D& v)const;
	bool operator >  (const Vector2D& v)const;
	bool operator >= (const Vector2D& v)const;

	// 単項演算子
	Vector2D& operator += (const Vector2D& v);
	Vector2D& operator -= (const Vector2D& v);
	Vector2D& operator *= (int k);
	Vector2D& operator /= (int k);
	Vector2D operator + () const;
	Vector2D operator - () const;

	// ベクトルの大きさを返します
	float Magnitude()const;

	// 正規化(大きさを１に)します
	void Normalize();

	// 正規化ベクトルを返します
	Vector2D Normalized();
};

// ベクトルの演算
// Vector2D + Vector2D
template<typename T>
Vector2D<T> operator + (const Vector2D<T>& u, const Vector2D<T>& v);

// Vector2D - Vector2D
template<typename T>
Vector2D<T> operator - (const Vector2D<T>& u, const Vector2D<T>& v);

// int * Vector2D
template<typename T>
Vector2D<T> operator * (const int k, const Vector2D<T>& v);

// Vector2D * int 
template<typename T>
Vector2D<T> operator * (const Vector2D<T>& v, const int k);

// Vector2D * Vector2D
template<typename T>
Vector2D<T> operator * (const Vector2D<T>& u, const Vector2D<T>& v);

// Vector2D / int
template<typename T>
Vector2D<T> operator / (const Vector2D<T>& v, const int k);

// Vector2D / Vector2D
template<typename T>
Vector2D<T> operator / (const Vector2D<T>& u, const Vector2D<T>& v);

// Vector2D % int
template<typename T>
Vector2D<T> operator % (const Vector2D<T> & v, const int k);

// 内積
template<typename T1, typename T2>
float Dot(const Vector2D<T1>& u, const Vector2D<T2>& v);

// 外積
template<typename T>
float Cross(const Vector2D<T>& u, const Vector2D<T>& v);

typedef Vector2D<int> Vector2;			// 整数型ベクトル
typedef Vector2D<float> Vector2f;		// 実数型ベクトル

typedef Vector2 Position2;
typedef Vector2f Position2f;

#include "./details/Vector2D.h"


