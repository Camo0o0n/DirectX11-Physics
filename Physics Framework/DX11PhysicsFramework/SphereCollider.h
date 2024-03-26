#pragma once
#include "Collider.h"

#include "AABBCollider.h"

//class Collider;
class SphereCollider : public Collider 
{
public:
	SphereCollider(Transform* tf, float r) : Collider(tf) { radius = r; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); };
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;

	float GetRadius() override { return radius; }
	Vector3 GetExtents() override { return Vector3(0, 0, 0); }

	virtual int GetType() override { return 1; }
};

