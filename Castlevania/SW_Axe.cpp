#include "SW_Axe.h"



SW_Axe::SW_Axe()
{
	LoadAnimation();
}


SW_Axe::~SW_Axe()
{
}
void SW_Axe::LoadAnimation() 
{
	AddAnimation(600); //0 right
	AddAnimation(601); //1 left
}

void SW_Axe::SetInfo(D3DXVECTOR3 _simonPosition, bool isStanding, int direction)
{
	this->nx = direction;
	if (nx == -1)
	{

	}
	else if (nx == 1)
	{

	}
}

void SW_Axe::Render(ViewPort * camera)
{
	D3DXVECTOR3 viewPortPos = this->position;
	if (camera != NULL)
	{
		viewPortPos = camera->ConvertPosInViewPort(this->position);
	}
	if (nx == 1)
	{
		animations[0]->Render(viewPortPos.x, viewPortPos.y);
	}
}

void SW_Axe::Update(DWORD dt) // moveable object
{
	position.x += vx * dt;
	position.y += vy * dt;
}