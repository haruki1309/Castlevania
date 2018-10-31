#include "ViewPort.h"



ViewPort::ViewPort()
{
}


ViewPort::~ViewPort()
{
}

D3DXVECTOR3 ViewPort::ConvertPosInViewPort(D3DXVECTOR3 _realPos)
{
	D3DXVECTOR3 temp;
	return temp;
}

void ViewPort::SetCameraPos(int x, int y)
{
	cameraPos.x = x;
	cameraPos.y = y;
	cameraPos.z = 0;
}
