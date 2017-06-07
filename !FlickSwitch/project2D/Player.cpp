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

	//if (velocity.magnitude() > maxSpeed)
	//{
	//	velocity = velocity.normalised() * maxSpeed;
	//}

	//prevPosition = m_transform.GetPosition();
	m_transform.Translate(velocity);

	
	system("cls");
	std::cout << "COLLIDING WITH GROUND: " << collidingWithGround << std::endl;
	std::cout << "maxSpeedThisFrame " << maxSpeedThisFrame << std::endl;
	std::cout<< "speed: " << speed << std::endl;
	std::cout << "vel.y: "<< velocity.y << std::endl;

	collidingWithGround = false;
}

void Player::draw(aie::Renderer2D * a_2dRenderer)
{
	a_2dRenderer->setRenderColour(0, 0, 255, 1);
	a_2dRenderer->drawSpriteTransformed3x3(m_texture, (float*)m_transform.GetGlobalMatrix());

	//Draw m_AABB
	//m_2dRenderer->setRenderColour(255,0,0);
	////top
	//m_2dRenderer->drawLine(m_AABB.left, m_AABB.top, m_AABB.right, m_AABB.top);
	////bottom
	//m_2dRenderer->drawLine(m_AABB.left, m_AABB.bottom, m_AABB.right, m_AABB.bottom);
	////right
	//m_2dRenderer->drawLine(m_AABB.right, m_AABB.bottom, m_AABB.right, m_AABB.top);
	////lef
	//m_2dRenderer->drawLine(m_AABB.left, m_AABB.bottom, m_AABB.left, m_AABB.top);
}

void Player::OnCollision(GameObject * a_obj2)
{
	std::cout << "Player collided with " << a_obj2->getType() << std::endl;
	//speed = 100;

	//should happen if you've hit top
	m_transform.SetPosition(Vector2(m_transform.GetPosition().x, a_obj2->getLinePos1().y + 32));
	
	collidingWithGround = true;
	/*Vector2 vecBetween = a_obj2->getPosition() - m_transform.GetPosition();
	velocity -= vecBetween.normalised() * 1.0f;*/
	//collision = true;
}
