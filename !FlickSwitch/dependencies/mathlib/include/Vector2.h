#pragma once
#include <cmath>

class Vector2
{
public:
	Vector2();
	~Vector2();

	float x;
	float y;

	Vector2(float a_x, float a_y);

	Vector2 operator+ (const Vector2& rhs) const;
	Vector2 operator- (const Vector2& rhs) const;
	Vector2 operator* (const float other) const;
	Vector2 operator/ (const float other) const;

	Vector2& operator+= (const Vector2& rhs); // v1 + v2
	Vector2& operator-= (const Vector2& rhs); // v1 - v2
	Vector2& operator*= (const float rhs); // v1 * rhs
	Vector2& operator/= (const float rhs); // v1 / rhs

	bool operator==(const Vector2& rhs) const;
	bool operator !=(const Vector2& rhs) const;

	//distance between two points
	float magnitude() const;

	//Takes in a vector and returns it as normalised
	Vector2 normalised() const;

	//Normalises vector
	void normalise();

	//returns the left perpindicular vector
	Vector2 LeftPerpindicular() const;
	//returns the right perpindicular vector
	Vector2 RightPerpindicular() const;

	//Mulitplies two vectors and returns a scalar value
	float dot(const Vector2&) const;

	//overload the cast to a float*
	explicit operator float*();

	//subscript operator
	float& operator[](int index);

	
};

//overload the float and Vector2 mulitplication (f*v)
Vector2 operator*(float lhs, const Vector2& rhs);

