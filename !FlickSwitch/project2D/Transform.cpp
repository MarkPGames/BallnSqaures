#include "Transform.h"



Transform::Transform()
{
	rotation = 0.0f;
	scale = Vector2(1.0f, 1.0f);
	parent = nullptr;
}


Transform::~Transform()
{

}

void Transform::UpdateTransforms()
{
	//convert pos, rot and scale to localmatrix
	translationMat.setTranslate(position.x, position.y);
	rotationMat.setRotateZ(rotation);
	scaleMat.setScaleXY(scale.x, scale.y);

	//set local matrix
	localMatrix = translationMat * rotationMat * scaleMat;

	//update global matrix
	//globalMatrix = localMatrix;
}

Matrix3 Transform::GetLocalMatrix()
{

	return localMatrix;
}

Matrix3 Transform::GetGlobalMatrix()
{
	if (parent != nullptr)
	{
		return parent->GetGlobalMatrix() * localMatrix;
	}
	else
	{
		return localMatrix;
	}
	
}

void Transform::Translate(const Vector2& translation)
{
	position += translation;
	UpdateTransforms();
}

void Transform::Scale(const Vector2& a_scale)
{
	scale += a_scale;
	UpdateTransforms();
}

void Transform::Rotate(float angle)
{
	rotation += angle;
	UpdateTransforms();
}

void Transform::SetParent(Transform * a_parent)
{
	parent = a_parent;
}

void Transform::SetPosition(const Vector2& pos)
{
	//update the pos Vector insie the transform
	position.x = pos.x;
	position.y = pos.y;

	//make sure tghe localMatrix is updated
	UpdateTransforms();
}

void Transform::SetScale(const Vector2& a_scale)
{
	scale.x = a_scale.x;
	scale.y = a_scale.y;

	UpdateTransforms();
}

void Transform::SetRotation(float rads)
{
	rotation = rads;
	UpdateTransforms();
}

Transform* Transform::GetParent() const
{
	return parent;
}

Vector2 Transform::GetPosition() const
{
	return position;
}

Vector2 Transform::GetScale() const
{
	return scale;
}

float Transform::GetRotation() const
{
	return rotation;
}
