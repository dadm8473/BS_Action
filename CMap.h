#pragma once
class CMap
{
public:
	CCamera* camera;

	CMatrix topLayer[2];
	CMatrix midLayer[2];
	CMatrix bottomLayer[2];

public:
	CMap(int stage, CCamera* camera);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};

