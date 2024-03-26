#pragma once

#include <directxmath.h>
#include "Transform.h"
#include "Vector.h"
#include "Debug.h"
#include "Collider.h"

class PhysicsModel abstract
{
#define AirDensity 1.293
#define CubeDrag 1.05
public:

	PhysicsModel(Transform* transform);
	virtual void Update(float deltaTime);

	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }

	Vector3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }

	void AddForce(Vector3 force) { _netForce += force; }

	static Vector3 GravityForce() { return Vector3(0, -9.81f, 0); }

	void SetMass(float mass) { _mass = mass; }
	float GetMass() const { return _mass; }
	float GetInverseMass() const { if (_mass == 0) return 0; return 1.0f / _mass; }

	Vector3 DragForce();
	float FrictionForce();
	
	bool IsCollideable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }

	void SetCollider(Collider* collider) { _collider = collider; }

	void ApplyImpulse(Vector3 impulse) { _velocity += impulse; }

	//in particle ignore the force point and simply call add force with the force
	//Rigidbody will call addforce and also calculate and store a vector3 torque
	virtual void AddRelativeForce(Vector3 force, Vector3 fPoint);

protected:
	Collider* _collider;

	bool _simulateGravity = true;
	Transform* _transform;
	Vector3 _velocity = Vector3();
	Vector3 _acceleration = Vector3();
	float _mass = 1.0f;
	Vector3 _netForce = Vector3(0, 0, 0);
};

