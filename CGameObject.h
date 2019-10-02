#pragma once
class CGameObject
{
public:

	float gracity;

	RECT rect;
	
public:
	CGameObject();
	~CGameObject();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};

