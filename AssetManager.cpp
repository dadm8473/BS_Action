#include "DXUT.h"
#include "Header.h"

AssetManager* AssetManager::instance;
AssetManager* gAssetManager;

void AssetManager::LoadAssets()
{
}

void AssetManager::ReleaseAssets()
{
	for (auto it = textures.begin(); it != textures.end(); ++it)
		if (it->second)
			delete it->second;
	textures.clear();
}

void AssetManager::LoadTexture(string key, LPCWSTR fileName, LPCWSTR extName, int maxScene)
{
	if (textures.find(key) != textures.end())
		return;

	textures[key] = new CTexture(fileName, extName, maxScene);
}

CTexture * AssetManager::GetTexture(string key)
{
	if (textures.find(key) == textures.end())
		return NULL;
	return textures[key];
}
