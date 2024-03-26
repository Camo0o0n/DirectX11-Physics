#pragma once
#include "PhysicsModel.h"
#include "SphereCollider.h"
#include "AABBCollider.h"	

class RigidBodyModel : public PhysicsModel
{
public:
	RigidBodyModel(Transform* transform, int sqORcr);
	
	virtual void AddRelativeForce(Vector3 force, Vector3 fPoint);
	void CalculateAngularVelocity(float deltaTime);
	void UpdateRotation(float deltaTime);

	void Update(float deltaTime) override;

private:
	XMFLOAT3X3 inertiaTensor;
	Vector3 angularVelocity = Vector3(0, 0, 0);
	float angularDamping = 0.40f;
	Vector3 torque;
};

