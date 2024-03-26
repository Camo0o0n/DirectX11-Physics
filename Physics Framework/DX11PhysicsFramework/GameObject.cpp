#include "GameObject.h"
#include "Debug.h"

GameObject::GameObject(string type, Geometry geometry, Material material, int sqORcr) : _type(type)
{
	_transform = new Transform();
	_appearance = new Appearance(geometry, material);
	_physModel = new RigidBodyModel(_transform, sqORcr);
}

GameObject::~GameObject()
{
	_transform = nullptr;
	_appearance = nullptr;
}

void GameObject::Update(float dt)
{
	_transform->Update(dt);
	_physModel->Update(dt);
}
