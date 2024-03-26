#include "AABBCollider.h"
#include "SphereCollider.h"

bool AABBCollider::CollidesWith(AABBCollider& other, CollisionManifold& out)
{
	Vector3 myPos = _tf->GetPosition();
	Vector3 myExt = Vector3(_x, _y, _z);
	Vector3 theirPos = other.GetPosition();
	Vector3 theirExt = other.GetExtents();

	Vector3 myMin = myPos - myExt;
	Vector3 myMax = myPos + myExt;
	Vector3 theirMin = theirPos - theirExt;
	Vector3 theirMax = theirPos + theirExt;
	Vector3 myClosestPoint = myPos;
	Vector3 theirClosestPoint = theirPos;

	if (theirMin.x > myClosestPoint.x)
		myClosestPoint.x = theirMin.x;
	if (theirMin.y > myClosestPoint.y)
		myClosestPoint.y = theirMin.y;
	if (theirMin.z > myClosestPoint.z)
		myClosestPoint.z = theirMin.z;
	if (theirMax.x < myClosestPoint.x)
		myClosestPoint.x = theirMax.x;
	if (theirMax.y < myClosestPoint.y)
		myClosestPoint.y = theirMax.y;
	if (theirMax.z < myClosestPoint.z)
		myClosestPoint.z = theirMax.z;

	if (myMin.x > theirClosestPoint.x)
		theirClosestPoint.x = myMin.x;
	if (myMin.y > theirClosestPoint.y)
		theirClosestPoint.y = myMin.y;
	if (myMin.z > theirClosestPoint.z)
		theirClosestPoint.z = myMin.z;
	if (myMax.x < theirClosestPoint.x)
		theirClosestPoint.x = myMax.x;
	if (myMax.y < theirClosestPoint.y)
		theirClosestPoint.y = myMax.y;
	if (myMax.z < theirClosestPoint.z)
		theirClosestPoint.z = myMax.z;

	if (myMin.x > theirMax.x || myMax.x < theirMin.x || myMin.y > theirMax.y || myMax.y < theirMin.y || myMin.z > theirMax.z || myMax.z < theirMin.z)
	{
		return false;
	}
	else
	{

		return true;
	}


}

bool AABBCollider::CollidesWith(SphereCollider& other, CollisionManifold& out)
{
	Vector3 myPos = _tf->GetPosition();
	Vector3 myExt = Vector3(_x, _y, _z);
	Vector3 theirPos = other.GetPosition();
	float radius = other.GetRadius();

	Vector3 myMin = myPos + myExt;
	Vector3 myMax = myPos - myExt;
	Vector3 closestPoint = theirPos;


	if (myMin.x > closestPoint.x)
		closestPoint.x = myMin.x;
	if (myMin.y > closestPoint.y)
		closestPoint.y = myMin.y;
	if (myMin.z > closestPoint.z)
		closestPoint.z = myMin.z;
	if (myMax.x < closestPoint.x)
		closestPoint.x = myMax.x;
	if (myMax.y < closestPoint.y)
		closestPoint.y = myMax.y;
	if (myMax.z < closestPoint.z)
		closestPoint.z = myMax.z;

	float distance = sqrt((closestPoint.x - theirPos.x) * (closestPoint.x - theirPos.x) + (closestPoint.y - theirPos.y) * (closestPoint.y - theirPos.y) + (closestPoint.z - theirPos.z) * (closestPoint.z - theirPos.z));

	if (distance < radius)
	{
		out.collisionNormal = theirPos - myPos;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal);
		//out.points[0].penetrationDepth = fabs(diff.Magnitude() - radius);

		return true;
	}

	return false;
}


