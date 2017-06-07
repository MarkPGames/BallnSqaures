#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	~Matrix2();

	Matrix2(float a_Xx, float a_Xy, float a_Yx, float a_Yy);

		  //R x C
	float m[2][2]; //Xx	Xy	x-axis
				   //Yx Yy	y-axis

	Matrix2 operator+(const Matrix2& rhs) const;
	Matrix2 operator-(const Matrix2& rhs) const;
	Matrix2 operator*(const Matrix2& other) const;

	Matrix2& operator+=(const Matrix2& rhs);
	Matrix2& operator-=(const Matrix2& rhs);
	Matrix2& operator*=(const Matrix2& rhs);

	//V = M*V
	Vector2 operator*(const Vector2& rhs) const;

	//Transpose (column major to row major)
	void transpose();
	//Returns transposed Matrix2
	Matrix2 transposed() const;

	//Sets scale for X and Y
	void setScaleXY(float x, float y);


	//Takes in an angle and calculates rotation
	void setRotate(float angle);

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	Vector2& operator[](int index);

};

