#include "Graphics.h"


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
	if (device)
	{
		device->Release();
		device = NULL;
	}
	if (direct3d)
	{
		direct3d->Release();
		direct3d = NULL;
	}
}

bool Graphics::Initialize(HWND hWnd, bool  windowed)
{
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS presentationParams;
	ZeroMemory(&presentationParams, sizeof(presentationParams));

	presentationParams.Windowed = windowed;
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentationParams.hDeviceWindow = hWnd;

	if (!SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT, //Adapter mac dinh
		D3DDEVTYPE_HAL, //Device Type: High Speed Graphic Card
		hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&presentationParams,
		&device)))
	{
		return false;
	}
	return true;
}

void Graphics::Clear(D3DCOLOR color)
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

void Graphics::Begin()
{
	device->BeginScene();
}

void Graphics::End()
{
	device->EndScene();
}

void Graphics::Present()
{
	device->Present(NULL, NULL, NULL, NULL);
}
