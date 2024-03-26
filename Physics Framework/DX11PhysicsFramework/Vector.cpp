//#include "Vector.h"
//
//Vector::Vector(Vector3 vector)
//{
//	_vector = vector;
//}
//
//Vector::~Vector()
//{
//	
//	
//}
//
//Vector3 Vector::Add(Vector3 vec1, Vector3 vec2)
//{
//	Vector3 combVec = Vector3(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
//	return combVec;
//}
//
//Vector3 Vector::Subtract(Vector3 vec1, Vector3 vec2)
//{
//	Vector3 combVec = Vector3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
//	return combVec;
//}
//
//Vector3 Vector::MulByScal(Vector3 vec, float scalar)
//{
//	Vector3 mulScal = Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
//	return mulScal;
//}
//
//Vector3 Vector::MulVec(Vector3 vec1, Vector3 vec2)
//{
//	Vector3 mulVec = Vector3(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
//	return mulVec;
//}
//
//Vector3 Vector::DivByFloat(Vector3 vec, float floatVal)
//{
//	/*Debug::DebugPrintF("netForce = %f, %f, %f, float = %f\n", vec.x, vec.y, vec.z, floatVal);*/
//	Vector3 devVal = Vector3(vec.x / floatVal, vec.y / floatVal, vec.z / floatVal);
//	return devVal;
//
//}
//
//float Vector::Magnitude(Vector3 vec)
//{
//	float mag = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
//	return mag;
//}
//
//Vector3 Vector::Normalise(Vector3 vec)
//{
//	float mag = Magnitude(vec);
//	Vector3 normVec = Vector3(vec.x / mag, vec.y / mag, vec.z / mag);
//	return normVec;
//}
//
//float Vector::Dot(Vector3 vec1, Vector3 vec2)
//{
//	Vector3 nMagL = Normalise(vec1);
//	Vector3 nMagR = Normalise(vec2);
//	float dot = (nMagL.x * nMagR.x) + (nMagL.y * nMagR.y) + (nMagL.z * nMagR.z);
//	return dot;
//}
//
//Vector3 Vector::Cross(Vector3 vec1, Vector3 vec2)
//{
//	return Vector3();
//}
