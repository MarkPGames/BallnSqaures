#pragma once

#include "Texture.h"
#include "Transform.h"
#include "Renderer2D.h"
#include "Input.h"
#include "AABB.h"

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
	void setLinePos1(Vector2 a_linePos1);
	void setLinePos2(Vector2 a_linePos2);

	std::string getType();



	virtual void OnCollision(GameObject* a_obj2);
	void setCollision(bool a_collision);

	float getRadius() const;
	void setRadius(float a_radius);
	void setType(std::string a_objType);


protected:
	aie::Texture* m_texture;
	Transform m_transform;

	std::string objType;
	bool collision, hasMoved;
	Vector2 linePos1, linePos2;

	//circle collision
	float m_radius;
};

