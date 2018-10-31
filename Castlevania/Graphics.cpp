#include "Graphics.h"

Graphics * Graphics::__instance = NULL;

Graphics * Graphics::GetInstance()
{
	if (__instance == NULL) __instance = new Graphics();
	return __instance;
}

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

	RECT userRect;
	GetClientRect(hWnd, &userRect);

	presentationParams.BackBufferHeight = userRect.bottom + 1;
	presentationParams.BackBufferWidth = userRect.right + 1;

	if (!SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT, //Adapter mac dinh
		D3DDEVTYPE_HAL, //Device Type: High Speed Graphic Card
		hWnd,
		D3DCREATE_MIXED_VERTEXPROCESSING,
		&presentationParams,
		&device)))
	{
		return false;
	}

	device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(Graphics::GetInstance()->device, &spriteHandler);

	return true;
}

void Graphics::Clear(D3DCOLOR color)
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

bool Graphics::Begin()
{
	return device->BeginScene();
}

void Graphics::End()
{
	device->EndScene();
}

void Graphics::Present()
{
	device->Present(NULL, NULL, NULL, NULL);
}
