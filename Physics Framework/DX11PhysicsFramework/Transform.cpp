#include "Transform.h"

Transform::Transform()
{
	_position = Vector3();
	_scale = Vector3(1.0f, 1.0f, 1.0f);
}

Transform::~Transform()
{	
	//_parent = nullptr;
}

void Transform::Update(float dt)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	Vector3 vector = _orientation.GetVector();
	XMMATRIX rotation = XMMatrixRotationQuaternion(XMVectorSet(vector.x, vector.y, vector.z, _orientation.GetScalar()));
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	//if (_parent != nullptr)
	//{
	//	XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetTransform()->GetWorldMatrix());
	//}
}

void Transform::Move(Vector3 direction)
{
	_position.x += direction.x;
	_position.y += direction.y;
	_position.z += direction.z;
}
