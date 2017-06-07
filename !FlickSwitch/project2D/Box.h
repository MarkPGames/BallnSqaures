#pragma once
#include "Transform.h"
#include "GameObject.h"

enum class SIDE
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
};

class Box : public GameObject
{
public:
	Box();
	Box(aie::Texture* a_texture, Vector2 a_position);
	~Box();

	bool startup();
	void update(float deltaTime);
	void draw(aie::Renderer2D* a_2dRenderer);

private:

	Vector2 size, bottomLeft, topRight, topLeft;
	float boxWidth, boxHeight;

};

