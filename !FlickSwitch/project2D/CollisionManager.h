#pragma once
#include "AABB.h"
#include "GameObject.h"
#include "DynamicArray.h"
#include <iostream>
#include "CollisionInfo.h"
class Application2D;


class CollisionManager
{
public:
	CollisionManager()
	{

	}

	CollisionManager(DynamicArray<GameObject*>* a_gameObjArray)
	{
		gameObjArray = a_gameObjArray;
	}
	~CollisionManager()
	{

	}

	//loops over each gameobject and checks against other gameobject
	void UpdateCollisions()
	{
		//for all objects (i)
		for (unsigned int i = 0; i < gameObjArray->getSize(); i++)
		{
			//for all other objects (j)
			for (unsigned int j = i + 1; j < gameObjArray->getSize(); j++)
			{
				if ((*gameObjArray)[i]->getType() == "player" && (*gameObjArray)[j]->getType() == "box")
				{
					CheckLineCollision((*gameObjArray)[i], (*gameObjArray)[j]);

				}
			}
		}
	}

	bool CheckAABBCollision(GameObject* obj1, GameObject* obj2)
	{
		//check collision between obj1 and obj2
		//if (obj1->getAABB()->Intersect(*obj2->getAABB()))
		{
			obj1->OnCollision(obj2, CollisionSide::NONE );
			obj2->OnCollision(obj1, CollisionSide::NONE);

			obj1->setCollision(true);
			obj2->setCollision(true);

			//obj1->setOtherAABB(*obj2->getAABB());
			//obj2->setOtherAABB(*obj1->getAABB());

			return true;
		}
		//obj1->OnCollision(obj2)
		//obj2->OnCollision(obj1)
		//return true

		obj1->setCollision(false);
		obj2->setCollision(false);
		return false;

		//return false


	}

	bool CheckCircleCollision(GameObject* obj1, GameObject* obj2)
	{
		//distance between objects are less than radii combined
		Vector2 vecBetween = obj2->getPosition() - obj1->getPosition();

		if (vecBetween.magnitude() < obj2->getRadius() + obj1->getRadius())
		{
			return true;
		}

		return false;
	}

	bool CheckLineCollision(GameObject* obj1, GameObject* obj2)
	{
		if (obj1->getPosition().x - obj1->getRadius() < obj2->getLinePos2().x)
		{
			if (obj1->getPosition().x + obj1->getRadius() > obj2->getLinePos1().x)
			{

				if (obj1->getPosition().y - obj1->getRadius() < obj2->getLinePos1().y)
				{
					if (obj1->getPosition().y + obj1->getRadius() > obj2->getLinePos1().y)
					{
			
						obj1->OnCollision(obj2, CollisionSide::TOP);

						return true;
					}
				}

			}
		}

		// left and right collision in general
		if (obj1->getPosition().y - obj1->getRadius() < obj2->getLinePos1().y)
		{
			if (obj1->getPosition().y + obj1->getRadius() > obj2->getLinePos3().y)
			{
				if (obj1->getPosition().x - obj1->getRadius() < obj2->getLinePos2().x)
					{
					if (obj1->getPosition().x + obj1->getRadius() > obj2->getLinePos1().x)
					{
						//obj1->OnCollision(obj2, CollisionSide::LEFT);

						if(obj1->getPosition().x < obj2->getPosition().x)
							std::cout << "LEFT COLLISION\n";
						else
							std::cout << "RIGHT COLLISION\n";
						return true;
					}
					
				}
			
				//else if (obj1->getPosition().x - obj1->getRadius() < obj2->getLinePos2().x)
				//{
				//	if (obj1->getPosition().x + obj1->getRadius() > obj2->getLinePos1().x)
				//	{
				//		std::cout << "RIGHT COLLISION\n";
						//obj1->setRight(true);
				//		return true;
				//	}
				//}
				
			}
			
		}

		obj1->setLeft(false);
	
		return false;
	}

private:
	DynamicArray<GameObject*>* gameObjArray;
};

