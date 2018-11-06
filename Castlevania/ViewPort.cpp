#include "ViewPort.h"



ViewPort::ViewPort()
{
}


ViewPort::~ViewPort()
{
}

D3DXVECTOR3 ViewPort::ConvertPosInViewPort(D3DXVECTOR3 _realPos)
{
	return _realPos - cameraPos;
}

void ViewPort::SetCameraPos(D3DXVECTOR3 _camPos)
{
	cameraPos = _camPos;
}
