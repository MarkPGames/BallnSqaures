#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Input.h"
#include "Vector2.h"
#include "DynamicArray.h"
#include "CollisionManager.h"

class GameObject;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D* m_2dRenderer;
	aie::Input* input;
	aie::Texture* m_playerTexture;
	aie::Texture* m_boxTexture;
	aie::Texture* m_boxStartTexture;

	Vector2 cameraPos;

	DynamicArray <GameObject*> gameObjArray;
	CollisionManager* collisionManager;
};

