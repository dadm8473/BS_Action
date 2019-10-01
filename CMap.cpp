#include "DXUT.h"
#include "Header.h"

CMap::CMap(int stage, CCamera * camera)
	: camera(camera)
{
	for (int i = 0; i < 2; ++i)
	{
		topLayer[i] = CMatrix();
		topLayer[i].position.x = 1024 * i;

		midLayer[i] = CMatrix();
		midLayer[i].position.x = 1024 * i;
		midLayer[i].position.y = -300;

		bottomLayer[i] = CMatrix();
		bottomLayer[i].position.x = 1024 * i;
		bottomLayer[i].position.y = -500;
	}
}

void CMap::Update(float deltaTime)
{
	if (!camera)
		return;

	for (int i = 0; i < 2; ++i)
	{
		if (topLayer[i].position.x <= camera->position.x / 5 - 1024)
			topLayer[i].position.x += 1024 * 2;
		if (topLayer[i].position.x >= camera->position.x / 5 + 1024)
			topLayer[i].position.x -= 1024 * 2;

		topLayer[i].position.y = camera->position.y / 5;

		if (midLayer[i].position.x <= camera->position.x / 3 - 1024)
			midLayer[i].position.x += 1024 * 2;
		if (midLayer[i].position.x >= camera->position.x / 3 + 1024)
			midLayer[i].position.x -= 1024 * 2;

		midLayer[i].position.y = camera->position.y / 3;

		if (bottomLayer[i].position.x <= camera->position.x / 1.5f - 1024)
			bottomLayer[i].position.x += 1024 * 2;
		if (bottomLayer[i].position.x >= camera->position.x / 1.5f + 1024)
			bottomLayer[i].position.x -= 1024 * 2;

		topLayer[i].Update(deltaTime, camera->position / 5);
		midLayer[i].Update(deltaTime, camera->position / 3);
		bottomLayer[i].Update(deltaTime, camera->position / 1.5f);
	}

}

void CMap::Render(LPD3DXSPRITE sprite)
{
	for (int i = 0; i < 2; ++i)
	{
		topLayer->Draw(sprite, gAssetManager->GetTexture("BG_Top"));
		midLayer->Draw(sprite, gAssetManager->GetTexture("BG_Mid"));
		bottomLayer->Draw(sprite, gAssetManager->GetTexture("BG_Bottom"));
	}
}
