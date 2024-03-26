#pragma once
#include "Transform.h"
#include "Appearance.h"
#include "Structures.h"
#include "RigidBodyModel.h"

class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material, int sqORcr);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform() const { return _transform; }
	Appearance* GetAppearance() const { return _appearance; }
	
	RigidBodyModel* GetPhysicsModel() const { return _physModel; }

	void Update(float dt);

private:
	string _type;

	Transform* _transform;
	Appearance* _appearance;

	RigidBodyModel* _physModel;
};

