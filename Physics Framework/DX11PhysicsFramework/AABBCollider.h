#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
private:
	float _x;
	float _y;
	float _z;
public:
	AABBCollider(Transform* tf) : Collider(tf) { _x = 1; _y = 1; _z = 1; }
	AABBCollider(Transform* tf, Vector3 extents) : Collider(tf) { _x = extents.x; _y = extents.y; _z = extents.z; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;

	Vector3 GetExtents() override { return Vector3(_x, _y, _z); }
	float GetRadius() override { return 0.0f; }

	virtual int GetType() override { return 2; }
};