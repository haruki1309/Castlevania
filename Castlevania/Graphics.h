#pragma once
#include<d3dx9.h>
#include <d3d9.h>
#include<string>

class Graphics
{
public:
	Graphics();
	~Graphics();

	bool Initialize(HWND hWnd, bool windowed);
	void Clear(D3DCOLOR color);
	void Begin();
	void End();
	void Present();

	LPDIRECT3DDEVICE9 device;
private:
	LPDIRECT3D9 direct3d;
};

