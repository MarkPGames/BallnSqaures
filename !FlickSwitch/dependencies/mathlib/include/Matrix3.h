#pragma once
#include "Vector2.h"
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	~Matrix3();

	Matrix3(
		float a_Xx, float a_Xy, float a_Xz,
		float a_Yx, float a_Yy, float a_Yz,
		float a_Zx, float a_Zy, float a_Zz);

	//R x C
	float m[3][3]; //Xx	Xy Xz	x-axis
				   //Yx Yy Yz	y-axis
				   //Zx Zy Zz	y-axis

	Matrix3 operator+(const Matrix3& rhs) const;
	Matrix3 operator-(const Matrix3& rhs) const;
	Matrix3 operator*(const Matrix3& other) const;

	Matrix3& operator+=(const Matrix3& rhs);
	Matrix3& operator-=(const Matrix3& rhs);
	Matrix3& operator*=(const Matrix3& rhs);

	Vector3 operator*(const Vector3& rhs) const;

	//Transpose (column major to row major)
	void transpose();

	//Returns transposed Matrix3
	Matrix3 transposed() const;

	//Sets scale for X and Y
	void setScaleXY(float x, float y);
	//Sets scale for X and Y and Z
	void setScaleXYZ(float x, float y, float z);

	//Takes in an angle and calculates rotation on X
	void setRotateX(float angle);
	//Takes in an angle and calculates rotation on Y
	void setRotateY(float angle);
	//Takes in an angle and calculates rotation on Z
	void setRotateZ(float angle);

	//Takes in x and y pos and sets them in the matrix
	void setTranslate(float x, float y);

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	Vector3& operator[](int index);
};
