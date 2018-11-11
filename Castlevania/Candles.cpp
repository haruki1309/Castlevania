#include "Candles.h"
#include "Textures.h"


LargeCandles::LargeCandles()
{
	LoadAnimation();
	state = 0;
	width = 16;
	height = 32;
}


LargeCandles::~LargeCandles()
{
}

void LargeCandles::SetState(int state)
{
	GameObject::SetState(state);
}

void LargeCandles::LoadAnimation()
{
	AddAnimation(500);
	AddAnimation(501);
	AddAnimation(502);
}

void LargeCandles::Update(DWORD dt)
{

}
void LargeCandles::Render(ViewPort * camera)
{
	//just display object inside our camera
	if (position.x >= camera->GetCameraPos().x - width && position.x <= camera->GetCameraPos().x + camera->GetCameraWidth())
	{
		D3DXVECTOR3 viewPortPos = camera->ConvertPosInViewPort(this->position);

		switch (state)
		{
		case 0:
			animations[0]->Render(viewPortPos.x, viewPortPos.y);
			break;
		case 1:
			animations[1]->Render(viewPortPos.x, viewPortPos.y + 8);
			animations[2]->Render(viewPortPos.x + 8, viewPortPos.y + 11);
			break;
		}
	}
}