#include "RigidBodyModel.h"


RigidBodyModel::RigidBodyModel(Transform* transform, int sqORcr) : PhysicsModel(transform)
{
	if (sqORcr == 1)
	{
		_collider = new SphereCollider(transform, 1);
		//float sphereStuff = (2.0f / 5.0f) * _mass * pow(_collider->GetRadius(), 2);
		//ZeroMemory(&inertiaTensor, sizeof(XMFLOAT3X3));

		//inertiaTensor._11 = sphereStuff;
		//inertiaTensor._22 = sphereStuff;
		//inertiaTensor._33 = sphereStuff;
	}if (sqORcr == 2)
	{
		_collider = new AABBCollider(transform);
		//ZeroMemory(&inertiaTensor, sizeof(XMFLOAT3X3));
		//inertiaTensor._11 = sphereStuff;
		//inertiaTensor._22 = sphereStuff;
		//inertiaTensor._33 = sphereStuff;
	}
	float sphereStuff = (2.0f / 5.0f) * _mass * pow(1, 2);
	ZeroMemory(&inertiaTensor, sizeof(XMFLOAT3X3));
	inertiaTensor._11 = sphereStuff;
	inertiaTensor._22 = sphereStuff;
	inertiaTensor._33 = sphereStuff;
}

void RigidBodyModel::AddRelativeForce(Vector3 force, Vector3 fPoint)
{
	AddForce(force);
	torque += force ^ fPoint;
}

void RigidBodyModel::Update(float deltaTime)
{
	PhysicsModel::Update(deltaTime);
	CalculateAngularVelocity(deltaTime);
	UpdateRotation(deltaTime);

}

void RigidBodyModel::CalculateAngularVelocity(float deltaTime)
{
	if (_mass == 0) { return; }
	XMVECTOR torqueVector = XMLoadFloat3(new XMFLOAT3(torque.x, torque.y, torque.z));
	XMMATRIX inerTen = XMLoadFloat3x3(&inertiaTensor);;
	XMVECTOR angularAcceleration = XMVector3Transform(torqueVector, XMMatrixInverse(nullptr, inerTen));
	XMFLOAT3 angAcc = XMFLOAT3();
	XMStoreFloat3(&angAcc, angularAcceleration);
	angularVelocity += Vector3(angAcc.x, angAcc.y, angAcc.z) * deltaTime;

	torque = Vector3();
}

void RigidBodyModel::UpdateRotation(float deltaTime)
{
	Quaternion orientation = _transform->GetOrientation();


	orientation += orientation * angularVelocity * 0.5f * deltaTime;
	if (orientation.Magnitude() != 0)
	{
		orientation /= orientation.Magnitude();
	}

	_transform->SetOrientation(orientation);

	angularVelocity *= pow(angularDamping, deltaTime);
}
