#pragma once
#include <d3d9.h>
#include <d3dx9.h>


//Graphics la doi tuong dai dien cho card man hinh

class Graphics
{
private:
	static Graphics * __instance;
	LPDIRECT3D9 direct3d;
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;

public:
	Graphics();
	~Graphics();

	LPDIRECT3DDEVICE9 device;

	LPDIRECT3DSURFACE9 GetBackBuffer() { return this->backBuffer; }

	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	bool Initialize(HWND hWnd, bool windowed);
	void Clear(D3DCOLOR color);
	bool Begin();
	void End();
	void Present();

	static Graphics * GetInstance();

};

