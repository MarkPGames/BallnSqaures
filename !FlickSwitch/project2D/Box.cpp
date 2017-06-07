#include "Box.h"
#include "Texture.h"

Box::Box()
{
	size = Vector2(0, 0);
}


Box::~Box()
{

}

Box::Box(aie::Texture * a_texture, Vector2 a_position) : GameObject(a_texture, a_position )
{
	objType = "box";
	size = Vector2(a_texture->getWidth(), a_texture->getHeight());
	bottomLeft = a_position - size / 2.0f;
	topRight = a_position + size / 2.0f;
	topLeft.x = a_position.x - size.x / 2.0f;
	topLeft.y = topRight.y;
	linePos1 = topLeft;
	linePos2 = topRight;
}

bool Box::startup()
{
	return false;
}

void Box::update(float deltaTime)
{

}

void Box::draw(aie::Renderer2D * a_2dRenderer)
{
	a_2dRenderer->setRenderColour(1, 1, 1, 1);
	a_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform.GetGlobalMatrix(), size.x, size.y, 100);
}