#include "Box.h"
#include "Texture.h"
#include <iostream>

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
	size = Vector2( float( a_texture->getWidth()), float(a_texture->getHeight()) );
	bottomLeft = a_position - size / 2.0f;
	topRight = a_position + size / 2.0f;
	topLeft.x = a_position.x - size.x / 2.0f;
	topLeft.y = topRight.y;
	linePos1 = topLeft;
	linePos2 = topRight;
	linePos3 = Vector2(linePos1.x, linePos1.y - m_radius);
	timer = 0.0f;
}

void Box::update(float deltaTime)
{
	timer += deltaTime;
	colourPrev = colourChoice;

	if (timer > 1.2f)
	{
		if (boolColour == true)
		{
			colourChoice = rand() % 4;

			while (colourChoice == colourPrev)
			{
				colourChoice = rand() % 4;
			}
		}
		else
		{
			colourChoice = colourChoice;
		}
		timer = 0.0f;
	}

	switch(colourChoice)
	{
	case 0:
		colour = COLOUR::RED;
		break;
	case 1:
		colour = COLOUR::GREEN;
		break;
	case 2:
		colour = COLOUR::BLUE;
		break;
	case 3:
		colour = COLOUR::YELLOW;
		break;
	}
}

void Box::draw(aie::Renderer2D * a_2dRenderer)
{
	switch (colour)
	{
	case COLOUR::RED:
		a_2dRenderer->setRenderColour(1, 0, 0, 1);
		break;
	case COLOUR::GREEN:
		a_2dRenderer->setRenderColour(0, 1, 0, 1);
		break;
	case COLOUR::BLUE:
		a_2dRenderer->setRenderColour(0, 0, 1, 1);
		break;
	case COLOUR::YELLOW:
		a_2dRenderer->setRenderColour(1, 1, 0, 1);
		break;
	default:
		a_2dRenderer->setRenderColour(1, 1, 1, 1);
		break;
	}

	a_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform.GetGlobalMatrix(), size.x, size.y, 100);
}
