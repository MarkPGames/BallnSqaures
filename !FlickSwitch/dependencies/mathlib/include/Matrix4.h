#pragma once
#include "Vector3.h"
#include "Vector4.h"
class Matrix4
{
public:
	Matrix4();
	~Matrix4();

	Matrix4(
		float a_Xx, float a_Xy, float a_Xz, float a_Xt,
		float a_Yx, float a_Yy, float a_Yz, float a_Yt,
		float a_Zx, float a_Zy, float a_Zz, float a_Zt,
		float a_Tx, float a_Ty, float a_Tz, float a_Tt);

	float m[4][4]; //Xx Xy Xz Xw	X axis		m00 m01 m02 m03
				   //Yx Yy Yz Yw		Y axis		m10 m11 m12 m13
				   //Zx Zy Zz Zw		Z axis		m20 m21 m22 m23
				   //Tx Ty Tz Tw		Translation	m30 m31 m32 m33

	Matrix4 operator+(const Matrix4& rhs) const;
	Matrix4 operator-(const Matrix4& rhs) const;
	Matrix4 operator*(const Matrix4& other) const;

	Matrix4& operator+=(const Matrix4& rhs);
	Matrix4& operator-=(const Matrix4& rhs);
	Matrix4& operator*=(const Matrix4& rhs);

	Vector3 operator*(const Vector3& rhs) const;
	Vector4 operator*(const Vector4& rhs) const;

	//Transpose (column major to row major)
	void transpose();

	//Returns transposed Matrix4
	Matrix4 transposed() const;

	//Takes in an angle and calculates rotation on X
	void setRotateX(float angle);
	//Takes in an angle and calculates rotation on Y
	void setRotateY(float angle);
	//Takes in an angle and calculates rotation on Z
	void setRotateZ(float angle);

	//Takes in x, y and z pos and sets them in the matrix
	void setTranslate(float x, float y, float z);

	//Sets scale for X and Y and Z
	void setScale(float x, float y, float z);

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	Vector4& operator[](int index);
};

