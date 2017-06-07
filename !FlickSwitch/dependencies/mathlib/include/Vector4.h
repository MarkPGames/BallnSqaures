#pragma once
#include <cmath>

class Vector4
{
public:
	Vector4();
	~Vector4();

	float x;
	float y;
	float z;
	float w;

	Vector4(float a_x, float a_y, float a_z, float a_w);

	Vector4 operator+ (const Vector4& rhs) const;
	Vector4 operator- (const Vector4& rhs) const;
	Vector4 operator* (const float other) const;
	Vector4 operator/ (const float other) const;

	Vector4& operator+= (const Vector4& rhs); // v1 + v2
	Vector4& operator-= (const Vector4& rhs); // v1 - v2
	Vector4& operator*= (const float rhs); // v1 * rhs
	Vector4& operator/= (const float rhs); // v1 / rhs

	bool operator==(const Vector4& rhs) const;
	bool operator !=(const Vector4& rhs) const;

	//distance between two points
	float magnitude() const;

	//Takes in a vector and returns it as normalised
	Vector4 normalised() const;

	//Normalises vector
	void normalise();

	//Mulitplies two vectors and returns a scalar value
	float dot(const Vector4&) const;

	//returns perpindicular vector
	Vector4 cross(const Vector4& rhs) const;

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	float& operator[](int index);
};

//overload the float and Vector2 mulitplication (f*v)
Vector4 operator*(float lhs, const Vector4& rhs);



