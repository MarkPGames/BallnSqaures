#pragma once

#include "Texture.h"
#include "Transform.h"
#include "Renderer2D.h"
#include "Input.h"
#include "AABB.h"
#include "CollisionInfo.h"

enum class COLOUR
{
	RED,
	GREEN,
	BLUE,
	YELLOW
};

class GameObject
{
public:
	GameObject();
	GameObject(aie::Texture* a_texture, Vector2 position);
	virtual ~GameObject();

	//assigns the texture passed in to m_texture
	void SetTexture(aie::Texture* a_texture);

	virtual bool startup();
	virtual void update(float deltaTime);
	virtual void draw(aie::Renderer2D* a_2drenderer);

	Vector2 getPosition();
	Vector2 getLinePos1();
	Vector2 getLinePos2();
	Vector2 getLinePos3();
	void setLinePos1(Vector2 a_linePos1);
	void setLinePos2(Vector2 a_linePos2);

	std::string getType();
	const GameObject* getObject();

	virtual void OnCollision(GameObject* a_obj2, CollisionSide a_collisionInfo);
	void setCollision(bool a_collision);

	float getRadius() const;
	void setRadius(float a_radius);
	void setType(std::string a_objType);
	void setBoolColour(bool a_boolColour);
	bool getBoolColour();
	COLOUR getColour();
	int getColourChoice();
	void setColourChoice(int a_colourChoice);
	void setHasRestart(bool a_hasRestart);
	bool getHasRestart();
	void setLeft(bool a_left);
	void setRight(bool a_right);


protected:
	aie::Texture* m_texture;
	Transform m_transform;

	std::string objType;
	bool collision, boolColour, hasRestart, left, right;
	Vector2 linePos1, linePos2, linePos3;

	//circle collision
	float m_radius;

	int colourChoice, colourPrev;
	COLOUR colour;
};

