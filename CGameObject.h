#pragma once
class CGameObject
{
public:
	// object classic
	int hp;
	int type;

	// move
	int movedir = 1;
	float moveSpeed;

	// rigid
	float gracity;

	RECT rect;
	
public:
	CGameObject();
	~CGameObject();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);

public:
	virtual void Move(float deltaTime);
	virtual void Attack();
};

