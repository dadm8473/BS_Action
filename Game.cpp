#include "DXUT.h"
#include "Header.h"

LPD3DXSPRITE gSprite = NULL;
CScene * gScene = NULL;

void Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &gSprite);

	gAssetManager = new AssetManager;
	gAssetManager->LoadAssets();

	gScene = new CTitleScene();
}

void Term()
{
	gAssetManager->ReleaseAssets();

	if (gSprite)
		gSprite->Release();

	if (gScene)
		delete gScene;
}

void Update(float deltaTime)
{
	if (gScene)
		gScene->Update(deltaTime);
}

void Render()
{
	gSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (gScene)
		gScene->Render(gSprite);

	gSprite->End();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (gScene)
		gScene->MsgProc(uMsg, wParam, lParam);
}
