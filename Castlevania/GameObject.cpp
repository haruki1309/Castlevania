#include "GameObject.h"



GameObject::GameObject(LPCSTR texturePath)
{
	x = y = 0;

	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(texturePath, &info);
	if (result != D3D_OK)
	{
		//DebugOut((LPWSTR)(L"[ERROR] GetImageInfoFromFile failed: %s\n"), texturePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv = Game::GetInstance()->GetDirect3DDevice();

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		texturePath,						// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),			// Transparent color
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		OutputDebugString("[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	//DebugOut((LPWSTR)(L"[INFO] Texture loaded Ok: %s \n"), texturePath);
}


GameObject::~GameObject()
{
}
