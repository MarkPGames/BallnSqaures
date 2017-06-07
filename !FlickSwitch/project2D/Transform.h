#pragma once
#include "Matrix3.h"
#include "Vector2.h"

//every single object needs a Transform
class Transform
{
public:
	Transform();
	~Transform();

	//call this every frame and this sets up your localMatrix based on pos, scale, rot
	void UpdateTransforms();

	//returns local matrix
	Matrix3 GetLocalMatrix();
	//returns global matrix (world translation)
	Matrix3 GetGlobalMatrix();

	//changes positions of current object
	void Translate(const Vector2& translation);
	//scales current object by Vector2 scale
	void Scale(const Vector2& scale);
	//rotates current object by angle (radians)
	void Rotate(float radians);
	//sets parent value to another transform matrix address
	void SetParent(Transform* a_parent);

	//sets the position of the current object
	void SetPosition(const Vector2& pos);
	//sets the scale of the current object
	void SetScale(const Vector2& a_scale);
	//sets the roation of the current object
	void SetRotation(float rads);

	//returns parent* value
	Transform* GetParent() const;
	//returns position of the current object
	Vector2 GetPosition() const;
	//returns scale value of current object
	Vector2 GetScale() const;
	//returns rotation value of current object
	float GetRotation() const;

private:
	Vector2 position;
	float rotation;
	Vector2 scale;
	Transform* parent;

	Matrix3 translationMat;
	Matrix3 rotationMat;
	Matrix3 scaleMat;
	//always update this when pos, rot or scale is changed
	Matrix3 localMatrix;
};


