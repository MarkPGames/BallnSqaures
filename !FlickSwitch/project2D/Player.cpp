#include "Player.h"
#include "Texture.h"
#include "Input.h"
#include <iostream>

Player::Player()
{

}

Player::Player(aie::Texture* a_texture, Vector2 a_position) : GameObject(a_texture, a_position)
{
	objType = "player";
	input = aie::Input::getInstance();
}

Player::~Player()
{
}

bool Player::startup()
{
	velocity = Vector2(0.0f, 0.0f);
	direction = Vector2(0.0f, 0.0f);
	gravity = Vector2(0.0f, -90.8f);
	speed = 100.0f;

	return true;
}

void Player::update(float deltaTime)
{	
	if (input->wasKeyPressed(aie::INPUT_KEY_A))
	{
		direction = Vector2(-1.0f, 0.0f);
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_D))
	{
		direction = Vector2(1.0f, 0.0f);
	}
	
	float speedThisFrame = speed;

	velocity +=  direction * speedThisFrame * deltaTime;
	velocity += gravity * deltaTime;

	//if colliding with ground, maxSpeed is usual, otherwise half
	float maxSpeedThisFrame = collidingWithGround ? maxSpeed : maxSpeed*0.5f;

	if (velocity.x > maxSpeedThisFrame)
	{
		velocity.x = maxSpeedThisFrame;
	}
	if (velocity.x < -maxSpeedThisFrame)
	{
		velocity.x = -maxSpeedThisFrame;
	}


	if (velocity.y > 10.0f)
	{
		velocity.y = 10.0f;
	}

	if (velocity.y < -10.0f)
	{
		velocity.y = -10.0f;
	}

	m_transform.Translate(velocity);

	switch (colourChoice)
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

	collidingWithGround = false;
}

void Player::draw(aie::Renderer2D * a_2dRenderer)
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

	a_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform.GetGlobalMatrix());
}

void Player::OnCollision(GameObject * a_obj2)
{
	std::cout << "Player collided with " << a_obj2->getType() << std::endl;
	std::cout << "Player colour: " << colourChoice << std::endl;

	//should happen if you've hit top
	m_transform.SetPosition(Vector2(m_transform.GetPosition().x, a_obj2->getLinePos1().y + 32));
	
	collidingWithGround = true;

	if (colour != a_obj2->getColour() && a_obj2->getBoolColour() == true)
	{
		m_transform.SetPosition(Vector2(500, 500));
		velocity = Vector2(0.0f, 0.0f);
		direction = Vector2(0.0f, 0.0f);
		colourChoice = rand() % 4;
		hasRestart = true;
	}
	else if (colour == a_obj2->getColour())
	{
		//set's box's ability to change colour to false
		a_obj2->setBoolColour(false);
	
		colourChoice = rand() % 4;
	}
}
