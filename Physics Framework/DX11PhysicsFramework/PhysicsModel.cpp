#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
}

void PhysicsModel::Update(float deltaTime)
{
	if (_mass == 0) { return; }
	if (_transform->GetPosition().y <= 1) { _simulateGravity = false;}
	if (_transform->GetPosition().y > 1) { _simulateGravity = true; }
	if (_simulateGravity)
	{
		_netForce +=  GravityForce();
	}

	_acceleration += _netForce / _mass;

	Vector3 tempVec = _transform->GetPosition();
	Vector3 position = Vector3(tempVec.x, tempVec.y, tempVec.z);

	_velocity += _acceleration * deltaTime;

	Vector3 drag = DragForce();
	_velocity.x -= drag.x;
	_velocity.y -= drag.y;
	_velocity.z -= drag.z;

	//if (_collision)
	//{
	//	FrictionForce();
	//}
	position += _velocity * deltaTime;

	_transform->SetPosition(position);

	_netForce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);

	
}

Vector3 PhysicsModel::DragForce()
{
	Vector3 drag = Vector3(0, 0, 0);
	//drag = 1/2 * density of fluid * speed of object ^ 2 * drag coefficiant * cross sectional area
	drag.x = 0.5 * AirDensity * pow(_velocity.x, 2) * CubeDrag * 0.1;
	drag.y = 0.5 * AirDensity * pow(_velocity.y, 2) * CubeDrag * 0.1;
	drag.z = 0.5 * AirDensity * pow(_velocity.z, 2) * CubeDrag * 0.1;
	if (_velocity.x < 0) { drag.x = -drag.x; }
	if (_velocity.y < 0) { drag.y = -drag.y; }
	if (_velocity.z < 0) { drag.z = -drag.z; }
	return drag;
}

float PhysicsModel::FrictionForce()
{
	/*Vector3 FrictionalForce = Vector3(_netForce.x * )*/
	return 0;
}

void PhysicsModel::AddRelativeForce(Vector3 force, Vector3 fPoint)
{
}
