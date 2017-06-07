#pragma once
#include <cmath>

class Vector3
{
public:
	Vector3();
	~Vector3();

	float x;
	float y;
	float z;

	Vector3(float a_x, float a_y, float a_z);

	Vector3 operator+ (const Vector3& rhs) const;
	Vector3 operator- (const Vector3& rhs) const;
	Vector3 operator* (const float other) const;
	Vector3 operator/ (const float other) const;

	Vector3& operator+= (const Vector3& rhs); // v1 + v2
	Vector3& operator-= (const Vector3& rhs); // v1 - v2
	Vector3& operator*= (const float rhs); // v1 * rhs
	Vector3& operator/= (const float rhs); // v1 / rhs

	bool operator==(const Vector3& rhs) const;
	bool operator !=(const Vector3& rhs) const;

	//distance between two points
	float magnitude() const;

	//Takes in a vector and returns it as normalised
	Vector3 normalised() const;

	//Normalises vector
	void normalise();

	//Mulitplies two vectors and returns a scalar value
	float dot(const Vector3&) const;

	//returns perpindicular vector
	Vector3 cross(const Vector3& rhs) const;

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	float& operator[](int index);
};

//overload the float and Vector2 mulitplication (f*v)
Vector3 operator*(float lhs, const Vector3& rhs);


