#include "Whip.h"
#include "Animations.h"
#include "Textures.h"

Whip::Whip()
{
	LoadAnimation();
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

void Whip::LoadAnimation()
{
	AddAnimation(100); // 0 animation nomal left
	AddAnimation(101); // 1 animation nomal left
	AddAnimation(102); // 2 animation red left
	AddAnimation(103); // 3 animation red left
}

void Whip::SetPosition(D3DXVECTOR3 _simonPosition, bool _isStanding, int direction)
{
	this->nx = direction;
	switch (type)
	{
	case NOMAL_WHIP: case SMALL_WHIP:		
		if (_isStanding)
		{
			if (nx == -1)
			{
				position.x = _simonPosition.x - 28;
				position.y = _simonPosition.y + 3;
			}
			else if(nx == 1)
			{
				position.x = _simonPosition.x - 16;
				position.y = _simonPosition.y + 3;
			}
		}
		else
		{
			if (nx == -1)
			{
				position.x = _simonPosition.x - 28;
				position.y = _simonPosition.y + 11;
			}
			else if (nx == 1)
			{
				position.x = _simonPosition.x - 16;
				position.y = _simonPosition.y + 11;
			}
		}
		break;
	case YELLOW_WHIP: case RED_WHIP: case BLUE_WHIP: case VIOLET_WHIP:
		if (_isStanding)
		{
			if (nx = -1)
			{
				position.x = _simonPosition.x - 44;
				position.y = _simonPosition.y + 3;
			}
			else if (nx == 1)
			{
				position.x = _simonPosition.x - 16;
				position.y = _simonPosition.y + 3;
			}
		}
		else
		{
			if (nx == -1)
			{
				position.x = _simonPosition.x - 44;
				position.y = _simonPosition.y + 11;
			}
			else if (nx == 1)
			{
				position.x = _simonPosition.x - 16;
				position.y = _simonPosition.y + 11;
			}
		}
		break;
	}
	
}

void Whip::Render(ViewPort * camera)
{
	int ani;
	switch (type)
	{
	case NOMAL_WHIP:
		if (nx == -1)
		{
			ani = 0;
		}
		else if (nx == 1)
		{
			ani = 1;
		}
		break;
	case RED_WHIP:
		if (nx == -1)
		{
			ani = 2;
		} 
		else if (nx == 1)
		{
			ani = 3;
		}
		break;
	}
	D3DXVECTOR3 viewPortPos = this->position;
	if (camera != NULL)
	{
		viewPortPos = camera->ConvertPosInViewPort(this->position);
	}
	animations[ani]->Render(viewPortPos.x, viewPortPos.y);
}