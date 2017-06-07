#pragma once
#include "Vector2.h"

class AABB
{
public:
	AABB();
	~AABB();
	AABB(const Vector2 & center, const Vector2 & halfwidths);

	Vector2 c;        // center point
	Vector2 hw;        // halfwidths

	float top;
	float bottom;
	float left;
	float right;

	bool Intersect(const AABB &other);
	

	void update(Vector2 vec);

private:
	void SetSides();
};

