#include "AABB.h"



AABB::AABB()
{
}

AABB::AABB(const Vector2 & center, const Vector2 & halfwidths)
{
	c = center;
	hw = halfwidths;
}


AABB::~AABB()
{
}

bool AABB::Intersect ( const AABB &other)
{

	float otherTop = other.c.y + other.hw.y;
	float otherBottom = other.c.y - other.hw.y;
	float otherLeft = other.c.x - other.hw.x;
	float otherRight = other.c.x + other.hw.x;

	//if (bottom < otherTop && top > otherBottom)
	//{
	//	if (left < otherRight && right > otherLeft)
	//	{
	//		return true;
	//	}
	//}

	//axis check X
	if ( !(left < otherRight && right > otherLeft) )
	{
		return false;
	}

	//axis check Y
	if (!(bottom < otherTop && top > otherBottom))
	{
		return false;
	}

	return true;
}

void AABB::update(Vector2 vec)
{
	c = vec;
	SetSides();
}

void AABB::SetSides()
{
	top = c.y + hw.y;
	bottom = c.y - hw.y;
	left = c.x - hw.x;
	right = c.x + hw.x;
}