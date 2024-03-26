#pragma once
#include "Structures.h"

class Appearance
{
public:
	Appearance(Geometry geometry, Material material);
	~Appearance();

	Geometry GetGeometryData() const { return _geometry; }
	void SetGeometry(Geometry geometry) { _geometry = geometry; }
	
	Material GetMaterial() const { return _material; }
	void SetMaterial(Material material) { _material = material; }


	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* const* GetTextureRV() { return &_textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	void Draw(ID3D11DeviceContext* pImmediateContext);

private:
	Geometry _geometry;
	Material _material;

	ID3D11ShaderResourceView* _textureRV = nullptr;
};

