#include "Simon.h"
#include "Textures.h"
#include "Animations.h"

//sprite simon bat dau tu -200

Simon * Simon::_instance = NULL;

Simon::Simon()
{
	LoadResource();
}


Simon::~Simon()
{
}

Simon * Simon::GetInstance()
{
	if (_instance == NULL) _instance = new Simon();
	return _instance;
}

void Simon::LoadResource()
{
	Textures::GetInstance()->Add(-1, TEX_SIMON, D3DCOLOR_XRGB(0, 128, 128));

	D3DXVECTOR3 simonPos = D3DXVECTOR3(238, 170, 0);
	//turn back
	Sprites::GetInstance()->Add(-201, 327, 8, 343, 40, Textures::GetInstance()->GetTexture(-1), simonPos);

	LPANIMATION aniTurningBack = new Animation(120);

	aniTurningBack->Add(-201);

	Animations::GetInstance()->Add(-50, aniTurningBack);

	this->AddAnimation(-50); // 0 animation turn back

	//idle left
	Sprites::GetInstance()->Add(-200, 79, 10, 97, 40, Textures::GetInstance()->GetTexture(-1), simonPos);
	Sprites::GetInstance()->Add(-199, 109, 9, 122, 40, Textures::GetInstance()->GetTexture(-1), simonPos);
	Sprites::GetInstance()->Add(-198, 135, 10, 151, 40, Textures::GetInstance()->GetTexture(-1), simonPos);

	LPANIMATION aniIdleLeft = new Animation(120);
	aniIdleLeft->Add(-200);
	Animations::GetInstance()->Add(-49, aniIdleLeft);
	this->AddAnimation(-49); // 1 animation idle left


	LPANIMATION aniWalkingLeft = new Animation(140);
	for (int i = -200; i <= -198; i++)
	{
		aniWalkingLeft->Add(i);
	}
	Animations::GetInstance()->Add(-48, aniWalkingLeft);
	this->AddAnimation(-48); //2 animation walking left


	SetPosition(238, 170);
}

void Simon::Update(DWORD dt)
{
	GameObject::Update(dt);
}

void Simon::Render()
{
	int ani;
	if (vx == 0)
	{
		if (nx > 0)
		{
			ani = SIMON_ANI_IDLE_RIGHT; 
		}
		else if (nx == 0)
		{
			ani = SIMON_ANI_IDLE_TURNBACK; 
		}
		else
		{
			ani = SIMON_ANI_IDLE_LEFT;
		}
	}
	else
	{
		if (vx > 0)
		{
			ani = SIMON_ANI_WALKING_RIGHT;
		}			
		else
		{
			ani = SIMON_ANI_WALKING_LEFT;
		}
	}
	animations[ani]->Render(x, y);
}

void Simon::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_JUMP:

	case SIMON_STATE_IDLE:
		vx = 0;
		break;
	case SIMON_STATE_WALKING_LEFT:
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		break;
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	case SIMON_STATE_IDLE_TURNBACK:
		vx = 0;
		nx = 0;
	}
}