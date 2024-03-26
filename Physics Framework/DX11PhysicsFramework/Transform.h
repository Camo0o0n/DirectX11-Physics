#pragma once
//#include "GameObject.h"

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Quaternion.h"

using namespace DirectX;
using namespace std;

class Transform
{
public:
	Transform();
	~Transform();

	void Update(float dt);
	void Move(Vector3 direction);

	//void SetParent(GameObject* parent) { _parent = parent; }

	void SetPosition(Vector3 position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	Vector3 GetPosition() const { return _position; }

	void SetScale(Vector3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	Vector3 GetScale() const { return _scale; }

	void SetRotation(Vector3 rotation) { _orientation = MakeQFromEulerAngles(rotation.x, rotation.y, rotation.z); }
	void SetRotation(float x, float y, float z) { _orientation = MakeQFromEulerAngles(x, y, z); }

	void SetOrientation(Quaternion quaternion) { _orientation = quaternion; }
	Quaternion GetOrientation() const { return _orientation; }

	Vector3 GetRotation() const { return MakeEulerAnglesFromQ(_orientation); }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }


private:
	Vector3 _position;
	Quaternion _orientation;
	Vector3 _scale;

	XMFLOAT4X4 _world;

	//GameObject* _parent = nullptr;
};

