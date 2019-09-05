#pragma once
class AssetManager
{
private:
	static AssetManager* instance;
	map<string, CTexture*>textures;

public:
	static AssetManager* Instance()
	{
		if (!instance)
			instance = new AssetManager();

		return instance;
	}

public:
	void LoadAssets();
	void ReleaseAssets();
	void LoadTexture(string key, LPCWSTR fileName, LPCWSTR extName, int maxScene);
	CTexture* GetTexture(string key);
};

extern AssetManager* gAssetManager;