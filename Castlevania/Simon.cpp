#include "Simon.h"
#include "Textures.h"
#include "Animations.h"

//sprite simon bat dau tu -200

Simon * Simon::_instance = NULL;

Simon::Simon()
{
	whip = Whip::GetInstance();
	attackSpeed = 100;
	SetState(SIMON_STATE_IDLE);
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

	D3DXVECTOR3 simonPos = D3DXVECTOR3(0, 0, 0); //cho nay sai
	//turn back
	Sprites::GetInstance()->Add(-201, 249, 7, 265, 39, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniTurningBack = new Animation(120);
	aniTurningBack->Add(-201);
	Animations::GetInstance()->Add(-50, aniTurningBack);
	this->AddAnimation(-50); // 0 animation turn back

	//sit left
	Sprites::GetInstance()->Add(-200, 87, 7, 103, 39, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniSitLeft = new Animation(120);
	aniSitLeft->Add(-200);
	Animations::GetInstance()->Add(-49, aniSitLeft);
	this->AddAnimation(-49); // 1 animation sit left

	//idle left + walking left
	Sprites::GetInstance()->Add(-199, 4, 7, 20, 39, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-198, 29, 7, 45, 39, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-197, 58, 7, 74, 39, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniIdleLeft = new Animation(100);
	aniIdleLeft->Add(-199);
	Animations::GetInstance()->Add(-48, aniIdleLeft);
	this->AddAnimation(-48); // 2 animation idle left


	LPANIMATION aniWalkingLeft = new Animation(100);
	aniWalkingLeft->Add(-199);
	aniWalkingLeft->Add(-198);
	aniWalkingLeft->Add(-197);
	aniWalkingLeft->Add(-198);
	Animations::GetInstance()->Add(-47, aniWalkingLeft);
	this->AddAnimation(-47); //3 animation walking left

	//upstairs left
	Sprites::GetInstance()->Add(-196, 156, 7, 172, 39, Textures::GetInstance()->GetTexture(-1));
	LPANIMATION aniUpstairLeft = new Animation(120);
	aniUpstairLeft->Add(-196);
	aniUpstairLeft->Add(-198);
	Animations::GetInstance()->Add(-46, aniUpstairLeft);
	this->AddAnimation(-46); // 4 animation upstairs left

	//downstairs left
	Sprites::GetInstance()->Add(-195, 131, 7, 147, 39, Textures::GetInstance()->GetTexture(-1));
	LPANIMATION aniDownstairLeft = new Animation(120);
	aniDownstairLeft->Add(-195);
	aniDownstairLeft->Add(-198);
	Animations::GetInstance()->Add(-45, aniDownstairLeft);
	this->AddAnimation(-45); // 5 animation downstairs left

	//stand attack left
	Sprites::GetInstance()->Add(-194, 27, 46, 43, 78, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-193, 58, 46, 74, 78, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-192, 88, 46, 104, 78, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniStandAttackLeft = new Animation(attackSpeed);
	aniStandAttackLeft->Add(-194);
	aniStandAttackLeft->Add(-193);
	aniStandAttackLeft->Add(-192, 200);
	Animations::GetInstance()->Add(-44, aniStandAttackLeft);
	this->AddAnimation(-44); // 6 animation stand attack left

	//sit attack left
	Sprites::GetInstance()->Add(-191, 26, 91, 42, 123, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-190, 55, 91, 71, 123, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-189, 85, 91, 101, 123, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniSitAttackLeft = new Animation(attackSpeed);
	aniSitAttackLeft->Add(-191);
	aniSitAttackLeft->Add(-190);
	aniSitAttackLeft->Add(-189, 200);
	Animations::GetInstance()->Add(-43, aniSitAttackLeft);
	this->AddAnimation(-43); // 7 animation sit attack left

	//upstairs attack left
	Sprites::GetInstance()->Add(-188, 129, 47, 145, 79, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-187, 159, 47, 175, 79, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-186, 194, 47, 210, 79, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniUpStairsAttackLeft = new Animation(attackSpeed);
	aniUpStairsAttackLeft->Add(-188);
	aniUpStairsAttackLeft->Add(-187);
	aniUpStairsAttackLeft->Add(-186, 200);
	Animations::GetInstance()->Add(-42, aniUpStairsAttackLeft);
	this->AddAnimation(-42); // 8 animation upstairs attack left

	//downstairs attack left
	Sprites::GetInstance()->Add(-185, 129, 91, 145, 123, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-184, 158, 91, 174, 123, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-183, 194, 91, 210, 123, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniDownStairsAttackLeft = new Animation(attackSpeed);
	aniDownStairsAttackLeft->Add(-185);
	aniDownStairsAttackLeft->Add(-184);
	aniDownStairsAttackLeft->Add(-183, 200);
	Animations::GetInstance()->Add(-41, aniDownStairsAttackLeft);
	this->AddAnimation(-41); // 9 animation downstairs attack left

	//eat sp item left
	Sprites::GetInstance()->Add(-182, 228, 89, 224, 121, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-181, 252, 89, 268, 121, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-180, 227, 47, 243, 79, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-179, 249, 47, 265, 79, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniEatSpItemLeft = new Animation(120);
	aniEatSpItemLeft->Add(-182);
	aniEatSpItemLeft->Add(-181);
	aniEatSpItemLeft->Add(-180);
	aniEatSpItemLeft->Add(-179);
	Animations::GetInstance()->Add(-40, aniEatSpItemLeft);
	this->AddAnimation(-40); // 10 animation eat sp item attack left

	//======================================================================
	//sit right
	Sprites::GetInstance()->Add(-178, 172, 136, 188, 168, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniSitRight = new Animation(120);
	aniSitRight->Add(-178);
	Animations::GetInstance()->Add(-39, aniSitRight);
	this->AddAnimation(-39); // 11 animation sit right

	//idle right + walking right
	Sprites::GetInstance()->Add(-177, 255, 136, 271, 168, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-176, 230, 136, 247, 168, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-175, 201, 136, 217, 168, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniIdleRight = new Animation(120);
	aniIdleRight->Add(-177);
	Animations::GetInstance()->Add(-38, aniIdleRight);
	this->AddAnimation(-38); // 12 animation idle right


	LPANIMATION aniWalkingRight = new Animation(100);
	aniWalkingRight->Add(-177);
	aniWalkingRight->Add(-176);
	aniWalkingRight->Add(-175);
	aniWalkingRight->Add(-176);
	Animations::GetInstance()->Add(-37, aniWalkingRight);
	this->AddAnimation(-37); // 13 animation walking right

	//upstairs right
	Sprites::GetInstance()->Add(-174, 103, 136, 119, 168, Textures::GetInstance()->GetTexture(-1));
	LPANIMATION aniUpstairRight = new Animation(120);
	aniUpstairRight->Add(-174);
	aniUpstairRight->Add(-176);
	Animations::GetInstance()->Add(-36, aniUpstairRight);
	this->AddAnimation(-36); // 14 animation upstairs right

	//downstairs right
	Sprites::GetInstance()->Add(-173, 128, 136, 145, 168, Textures::GetInstance()->GetTexture(-1));
	LPANIMATION aniDownstairRight = new Animation(120);
	aniDownstairRight->Add(-173);
	aniDownstairRight->Add(-176);
	Animations::GetInstance()->Add(-35, aniDownstairRight);
	this->AddAnimation(-35); // 15 animation downstairs right

	//stand attack right
	Sprites::GetInstance()->Add(-172, 232, 175, 248, 207, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-171, 201, 175, 217, 207, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-170, 171, 175, 187, 207, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniStandAttackRight = new Animation(attackSpeed);
	aniStandAttackRight->Add(-172);
	aniStandAttackRight->Add(-171);
	aniStandAttackRight->Add(-170, 200);
	Animations::GetInstance()->Add(-34, aniStandAttackRight);
	this->AddAnimation(-34); // 16 animation stand attack right

	//sit attack right
	Sprites::GetInstance()->Add(-169, 233, 220, 249, 252, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-168, 204, 220, 220, 252, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-167, 174, 220, 190, 252, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniSitAttackRight = new Animation(attackSpeed);
	aniSitAttackRight->Add(-169);
	aniSitAttackRight->Add(-168);
	aniSitAttackRight->Add(-167, 200);
	Animations::GetInstance()->Add(-33, aniSitAttackRight);
	this->AddAnimation(-33); // 17 animation sit attack right

	//upstairs attack right
	Sprites::GetInstance()->Add(-166, 130, 176, 146, 208, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-165, 100, 176, 116, 208, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-164, 65, 176, 81, 208, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniUpStairsAttackRight = new Animation(attackSpeed);
	aniUpStairsAttackRight->Add(-166);
	aniUpStairsAttackRight->Add(-165);
	aniUpStairsAttackRight->Add(-164, 200);
	Animations::GetInstance()->Add(-32, aniUpStairsAttackRight);
	this->AddAnimation(-32); // 18 animation upstairs attack right

	//downstairs attack right
	Sprites::GetInstance()->Add(-163, 130, 220, 146, 252, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-162, 101, 220, 117, 252, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-161, 65, 220, 81, 252, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniDownStairsAttackRight = new Animation(attackSpeed);
	aniDownStairsAttackRight->Add(-163);
	aniDownStairsAttackRight->Add(-162);
	aniDownStairsAttackRight->Add(-161, 200);
	Animations::GetInstance()->Add(-31, aniDownStairsAttackRight);
	this->AddAnimation(-31); // 19 animation downstairs attack right

	//eat sp item right
	Sprites::GetInstance()->Add(-160, 31, 218, 47, 250, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-159, 7, 218, 23, 250, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-158, 32, 176, 48, 208, Textures::GetInstance()->GetTexture(-1));
	Sprites::GetInstance()->Add(-157, 10, 176, 26, 208, Textures::GetInstance()->GetTexture(-1));

	LPANIMATION aniEatSpItemRight = new Animation(120);
	aniEatSpItemRight->Add(-160);
	aniEatSpItemRight->Add(-159);
	aniEatSpItemRight->Add(-158);
	aniEatSpItemRight->Add(-157);
	Animations::GetInstance()->Add(-30, aniEatSpItemRight);
	this->AddAnimation(-30); // 20 animation eat sp item attack right
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
	}
	else if (InputDevice::GetInstance()->IsKeyDown(DIK_LEFTARROW) && isGrounded && !isAttack)
	{
		SetState(SIMON_STATE_WALKING_LEFT);
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
	if (camera != NULL)
	{
		this->position = camera->ConvertPosInViewPort(this->position);
	}
	animations[ani]->Render(position.x, position.y);
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