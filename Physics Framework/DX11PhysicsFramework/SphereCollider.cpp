#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
	Vector3 distance = GetPosition() - other.GetPosition();
	float radiSum = other.GetRadius() + GetRadius();

	if (distance.Magnitude() <= radiSum)
	{
		out.collisionNormal = distance;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * GetRadius());
		out.points[0].penetrationDepth = fabs(distance.Magnitude() - radiSum);

		return true;
	}
	return false;
}
bool SphereCollider::CollidesWith(AABBCollider& other, CollisionManifold& out)
{
	Vector3 myPos = _tf->GetPosition();
	Vector3 theirPos = other.GetPosition();
	Vector3 theirExt = other.GetExtents();

	Vector3 theirMin = theirPos + theirExt;
	Vector3 theirMax = theirPos - theirPos;
	Vector3 closestPoint = myPos;

	if (theirMin.x > closestPoint.x)
		closestPoint.x = theirMin.x;
	if (theirMin.y > closestPoint.y)
		closestPoint.y = theirMin.y;
	if (theirMin.z > closestPoint.z)
		closestPoint.z = theirMin.z;
	if (theirMax.x < closestPoint.x)
		closestPoint.x = theirMax.x;
	if (theirMax.y < closestPoint.y)
		closestPoint.y = theirMax.y;
	if (theirMax.z < closestPoint.z)
		closestPoint.z = theirMax.z;



	float distance = sqrt((closestPoint.x - myPos.x) *
		(closestPoint.x - myPos.x) + (closestPoint.y - myPos.y) *
		(closestPoint.y - myPos.y) + (closestPoint.z - myPos.z) *
		(closestPoint.z - myPos.z));

	return(distance < radius);
}