#include "Simon.h"
#include "Textures.h"
#include "Animations.h"

Simon * Simon::_instance = NULL;

Simon::Simon()
{
	whip = Whip::GetInstance();
	whip->SetType(NOMAL_WHIP);
	attackSpeed = 100;
	info = D3DXVECTOR3(16, 5, 3);
	SetState(SIMON_STATE_IDLE);
}

Simon::~Simon()
{
}

Simon * Simon::GetInstance()
{
	if (_instance == NULL) _instance = new Simon();
	return _instance;
}

void Simon::LoadAnimation()
{
	AddAnimation(-50); // 0 animation turn back

	AddAnimation(-49); // 1 animation sit left

	AddAnimation(-48); // 2 animation idle left

	AddAnimation(-47); //3 animation walking left

	AddAnimation(-46); // 4 animation upstairs left

	AddAnimation(-45); // 5 animation downstairs left

	AddAnimation(-44); // 6 animation stand attack left

	AddAnimation(-43); // 7 animation sit attack left

	AddAnimation(-42); // 8 animation upstairs attack left

	AddAnimation(-41); // 9 animation downstairs attack left

	AddAnimation(-40); // 10 animation eat sp item attack left

	//======================================================================
	AddAnimation(-39); // 11 animation sit right

	AddAnimation(-38); // 12 animation idle right

	AddAnimation(-37); // 13 animation walking right

	AddAnimation(-36); // 14 animation upstairs right

	AddAnimation(-35); // 15 animation downstairs right

	AddAnimation(-34); // 16 animation stand attack right

	AddAnimation(-33); // 17 animation sit attack right

	AddAnimation(-32); // 18 animation upstairs attack right

	AddAnimation(-31); // 19 animation downstairs attack right

	AddAnimation(-30); // 20 animation eat sp item attack right
}

void Simon::Update(DWORD dt)
{
	GameObject::Update(dt);

	vy += SIMON_GRAVITY;

	switch (state)
	{
	case SIMON_STATE_IDLE:
		Stand(dt);
		break;
	case SIMON_STATE_SIT:
		Sit(dt);
		break;
	case SIMON_STATE_JUMP:
		Jump(dt);
		break;
	case SIMON_STATE_WALKING_RIGHT:
		Move(dt);
		break;
	case SIMON_STATE_WALKING_LEFT:
		Move(dt);
		break;
	case SIMON_STATE_ATTACK:
		Attack(dt);
		break;
	case SIMON_STATE_IDLE_TURNBACK:
		break;
	}
}

void Simon::HandleMove()
{
	if (InputDevice::GetInstance()->IsKeyDown(DIK_RIGHTARROW) && isGrounded && !isAttack)
	{
		SetState(SIMON_STATE_WALKING_RIGHT);
		if (isSit)
		{
			SetState(SIMON_STATE_SIT);
		}
	}
	else if (InputDevice::GetInstance()->IsKeyDown(DIK_LEFTARROW) && isGrounded && !isAttack)
	{
		SetState(SIMON_STATE_WALKING_LEFT);
		if (isSit)
		{
			SetState(SIMON_STATE_SIT);
		}
	}
	else if (InputDevice::GetInstance()->IsKeyDown(DIK_DOWNARROW) && isGrounded &&!isAttack)
	{
		SetState(SIMON_STATE_SIT);
	}
	else if(isGrounded && !isAttack)
	{
		SetState(SIMON_STATE_IDLE);
	}
}

void Simon::HandleEvent(bool isKeyDown)
{
	if (isKeyDown)
	{
		if (InputDevice::GetInstance()->IsKeyDown(DIK_SPACE) && !isAttack)
		{
			SetState(SIMON_STATE_JUMP);
		}
		if (InputDevice::GetInstance()->IsKeyDown(DIK_LCONTROL) && !isAttack)
		{
			SetState(SIMON_STATE_ATTACK);
		}
	}
}

void Simon::Render(ViewPort * camera)
{
	int ani;
	
	switch (state)
	{
	case SIMON_STATE_IDLE:
		if (isGrounded)
		{
			if (nx > 0)
			{
				ani = SIMON_ANI_IDLE_RIGHT;
			}
			else if (nx < 0)
			{
				ani = SIMON_ANI_IDLE_LEFT;
			}
			break;
		}
	case SIMON_STATE_IDLE_TURNBACK:
		ani = SIMON_ANI_IDLE_TURNBACK;
		break;
		
	case SIMON_STATE_WALKING_LEFT:
		ani = SIMON_ANI_WALKING_LEFT;
		if (isSit)
		{
			ani = SIMON_ANI_SIT_LEFT;
		}
		break;
	case SIMON_STATE_WALKING_RIGHT:
		ani = SIMON_ANI_WALKING_RIGHT;
		if (isSit)
		{
			ani = SIMON_ANI_SIT_RIGHT;
		}
		break;
	case SIMON_STATE_ATTACK:
		if (!isSit)
		{
			if (nx > 0)
			{
				ani = SIMON_ANI_STAND_ATTACK_RIGHT;
			}
			else if (nx < 0)
			{
				ani = SIMON_ANI_STAND_ATTACK_LEFT;
			}
		}
		else
		{
			if (nx > 0)
			{
				ani = SIMON_ANI_SIT_ATTACK_RIGHT;
			}
			else if (nx < 0)
			{
				ani = SIMON_ANI_SIT_ATTACK_LEFT;
			}
		}
		whip->Render(camera);
		break;
	case SIMON_STATE_SIT:
		if (nx > 0)
		{
			ani = SIMON_ANI_SIT_RIGHT;
		}
		else if (nx < 0)
		{
			ani = SIMON_ANI_SIT_LEFT;
		}
		break;
	case SIMON_STATE_JUMP:
		if (nx > 0)
		{
			ani = SIMON_ANI_SIT_RIGHT;
		}
		else if (nx < 0)
		{
			ani = SIMON_ANI_SIT_LEFT;
		}
		break;
	}
	D3DXVECTOR3 viewPortPos = position;
	if (camera != NULL)
	{
		viewPortPos = camera->ConvertPosInViewPort(this->position);
	}
	animations[ani]->Render(viewPortPos.x, viewPortPos.y);
}

void Simon::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_IDLE:
		vx = 0;
		vy = 0;
		time = 0;

		isSit = false;
		isGrounded = true;
		isAttack = false;
		break;
	case SIMON_STATE_SIT:
		vx = 0;
		vy = 0;
		time = 0;

		this->isSit = true;
		this->isGrounded = true;
		isAttack = false;
		break;
	case SIMON_STATE_JUMP:
		if (position.y == 152 && !isSit)
		{
			time = 0;
			vy = -SIMON_JUMP_SPEED_Y;
			isGrounded = false;
			isSit = false;
			isAttack = false;
		}
		break;
	case SIMON_STATE_WALKING_RIGHT:
		nx = 1;
		vx = SIMON_WALKING_SPEED;
		isGrounded = true;
		isAttack = false;
		time = 0;
		break;
	case SIMON_STATE_WALKING_LEFT:
		nx = -1;
		vx = -SIMON_WALKING_SPEED;
		isGrounded = true;
		isAttack = false;
		time = 0;
		break;
	case SIMON_STATE_IDLE_TURNBACK:
		nx = 0;
		vx = vy = 0;
		isGrounded = true;
		isSit = false;
		break;
	case SIMON_STATE_ATTACK:
		time = 0;
		if (isGrounded)
		{
			vx = 0;
		}
		isAttack = true;
		whip->SetPosition(this->position, !isSit, nx);
	}
}

void Simon::Move(DWORD dt)
{
	if (!isSit)
	{
		position.x += dt * vx;
	}
	if (position.y > 152) // 
	{
		isGrounded = true;
		vy = 0;
		position.y = 152.0f;
	}
}

void Simon::Stand(DWORD dt)
{
	position.x += dt * vx;
	if (position.y > 152) 
	{
		isGrounded = true;
		vy = 0;
		position.y = 152.0f;
	}
}

void Simon::Sit(DWORD dt)
{
	position.x += dt * vx;
	if (position.y > 152) // 
	{
		isGrounded = true;
		vx = 0;
		position.y = 152.0f;
	}
}

void Simon::Jump(DWORD dt)
{
	position.y += dt * vy;
	position.x += dt * vx;

	if (position.y > 152) // 
	{
		isGrounded = true;
		vy = 0;
		position.y = 152.0f;
	}
}

void Simon::Attack(DWORD dt)
{
	position.y += dt * vy;
	position.x += dt * vx;
	if (position.y > 152)
	{
		isGrounded = true;
		vy = 0;
		position.y = 152.0f;
	}

	whip->SetPosition(position, !isSit, nx);
	time += dt;
	if (time <= 400)
	{
		isAttack = true;
	}
	else
	{
		time = 0;
		isAttack = false;
		if (!isGrounded)
		{
			SetState(SIMON_STATE_JUMP);
		}
	}
}