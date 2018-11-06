#include "Whip.h"
#include "Animations.h"
#include "Textures.h"

Whip::Whip()
{
	type = NOMAL_WHIP;
	LoadResource();
}


Whip::~Whip()
{
}

Whip * Whip::_instance = NULL;

Whip * Whip::GetInstance()
{
	if (_instance == NULL) _instance = new Whip();
	return _instance;
}

void Whip::LoadResource()
{
	Textures::GetInstance()->Add(100, WHIP_TEX, D3DCOLOR_XRGB(0, 128, 128));

	D3DXVECTOR3 whipPos = D3DXVECTOR3(0, 0, 0); //cho nay sai

	//nomal left
	Sprites::GetInstance()->Add(100, 4, 6, 68, 38, Textures::GetInstance()->GetTexture(100), whipPos);
	Sprites::GetInstance()->Add(101, 88, 6, 151, 38, Textures::GetInstance()->GetTexture(100), whipPos);
	Sprites::GetInstance()->Add(102, 175, 6, 239, 38, Textures::GetInstance()->GetTexture(100), whipPos);

	LPANIMATION aniNomalLeft = new Animation(200);
	aniNomalLeft->Add(100);
	aniNomalLeft->Add(101);
	aniNomalLeft->Add(102);
	Animations::GetInstance()->Add(100, aniNomalLeft);
	this->AddAnimation(100); // 0 animation nomal left
	//nomal right
	Sprites::GetInstance()->Add(103, 431, 6, 495, 38, Textures::GetInstance()->GetTexture(100), whipPos);
	Sprites::GetInstance()->Add(104, 348, 6, 411, 38, Textures::GetInstance()->GetTexture(100), whipPos);
	Sprites::GetInstance()->Add(105, 260, 6, 324, 38, Textures::GetInstance()->GetTexture(100), whipPos);

	LPANIMATION aniNomalRight = new Animation(200);
	aniNomalRight->Add(103);
	aniNomalRight->Add(104);
	aniNomalRight->Add(105);
	Animations::GetInstance()->Add(101, aniNomalRight);
	this->AddAnimation(101); // 1 animation nomal left



}

void Whip::SetPosition(D3DXVECTOR3 _simonPosition, bool _isStanding, int direction)
{
	if (direction == 1)
	{
		isLeft = false;
	}
	else if (direction == -1)
	{
		isLeft = true;
	}
	if (_isStanding)
	{
		if (isLeft)
		{
			position.x = _simonPosition.x - 32;
			position.y = _simonPosition.y;
		}
		else
		{
			position.x = _simonPosition.x - 16;
			position.y = _simonPosition.y;
		}
	}
	else
	{
		if (isLeft)
		{
			position.x = _simonPosition.x - 32;
			position.y = _simonPosition.y + 8;
		}
		else
		{
			position.x = _simonPosition.x - 16;
			position.y = _simonPosition.y + 8;
		}
	}
}

void Whip::Render()
{
	int currentFrame;
	switch (type)
	{
	case NOMAL_WHIP:
		if (isLeft)
		{
			animations[0]->Render(position.x, position.y);	
		}
		else
		{
			animations[1]->Render(position.x, position.y);
		}
	}
}