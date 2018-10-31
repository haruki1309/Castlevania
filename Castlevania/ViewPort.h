#pragma once
#include <d3dx9.h>



class ViewPort
{
private:
	D3DXVECTOR3 cameraPos;
	
	int cameraWidth, cameraHeight;

	RECT region;

public:
	ViewPort();
	~ViewPort();

	D3DXVECTOR3 ConvertPosInViewPort(D3DXVECTOR3 _realPos);

	void SetCameraPos(int x, int y);

	void SetCameraSize(int _width, int _height) { cameraWidth = _width; cameraHeight = _height; }

	void GetCameraSize(int &_width, int &_height) { _width = cameraWidth; _height = cameraHeight; }

	D3DXVECTOR3 GetCameraPos() { return this->cameraPos; }
};

