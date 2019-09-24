#pragma once
class CGameObject
{
public:
	CGameObject();
	~CGameObject();

public:
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};

