#pragma once
#include"GameObject.h"
#include "InputDevice.h"
#include "Whip.h"

#define TEX_SIMON "Resource\\Simon.png"


#define SIMON_WALKING_SPEED							0.06f
#define SIMON_JUMP_SPEED_Y							0.22f
#define SIMON_GRAVITY								0.018f

#define SIMON_STATE_IDLE_TURNBACK					-100
#define SIMON_STATE_IDLE							0
#define SIMON_STATE_WALKING_RIGHT					100
#define SIMON_STATE_WALKING_LEFT					200
#define SIMON_STATE_JUMP							300
#define SIMON_STATE_SIT								400
#define SIMON_STATE_ATTACK							500
#define SIMON_STATE_CANCEL_ATTACK					600


#define SIMON_ANI_IDLE_TURNBACK						0
#define SIMON_ANI_SIT_LEFT							1
#define SIMON_ANI_IDLE_LEFT							2
#define SIMON_ANI_WALKING_LEFT						3
#define SIMON_ANI_UPSTAIRS_LEFT						4
#define SIMON_ANI_DOWNSTAIRS_LEFT					5

#define SIMON_ANI_STAND_ATTACK_LEFT					6	
#define SIMON_ANI_SIT_ATTACK_LEFT					7
#define SIMON_ANI_UPSTAIRS_ATTACK_LEFT				8
#define SIMON_ANI_DOWNSTAIRS_ATTACK_LEFT			9

#define SIMON_ANI_STAND_GET_SPITEM_LEFT				10

#define SIMON_ANI_SIT_RIGHT							11
#define SIMON_ANI_IDLE_RIGHT						12
#define SIMON_ANI_WALKING_RIGHT						13
#define SIMON_ANI_UPSTAIRS_RIGHT					14
#define SIMON_ANI_DOWNSTAIRS_RIGHT					15

#define SIMON_ANI_STAND_ATTACK_RIGHT				16	
#define SIMON_ANI_SIT_ATTACK_RIGHT					17
#define SIMON_ANI_UPSTAIRS_ATTACK_RIGHT				18
#define SIMON_ANI_DOWNSTAIRS_ATTACK_RIGHT			19

#define SIMON_ANI_STAND_GET_SPITEM_RIGHT			20	
//--------------------------------------------------------

class Simon : public GameObject
{
private:
	static Simon * _instance;
	bool isGrounded;
	bool isSit;
	bool isAttack;

	Whip * whip;
	
	int totalWhip;
	int totalSubWeapon;

	int time;

	int attackSpeed;

	D3DXVECTOR3 info; // hp, energy, life
public:
	Simon();
	~Simon();
	static Simon * GetInstance();

	void LoadAnimation();

	void Update(DWORD dt);
	void Render(ViewPort * camera);
	void SetState(int state);

	void HandleMove();
	void HandleEvent(bool isKeyDown);

	void Move(DWORD dt);
	void Stand(DWORD dt);
	void Jump(DWORD dt);
	void Sit(DWORD dt);
	void Attack(DWORD dt);

	void SetInfo(D3DXVECTOR3 _info) { info = _info; }
	D3DXVECTOR3 GetInfo() { return info; }

};

