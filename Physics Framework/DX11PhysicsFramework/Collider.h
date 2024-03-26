#pragma once
#include "Transform.h"
#include "Vector.h"
#include "Structures.h"
//#include "SphereCollider.h"

class SphereCollider;
class AABBCollider;

class Collider abstract
{
protected:
	Transform* _tf;
	float radius;
	float _x;
	float _y;
	float _z;
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) = 0;

	Vector3 GetPosition() const { return _tf->GetPosition(); }

	virtual Vector3 GetExtents() = 0;

	virtual int GetType() = 0;
	virtual float GetRadius() = 0;
};