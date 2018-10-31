#pragma once
#include"GameObject.h"

#define TEX_SIMON "Resource\\Simon.png"


#define SIMON_WALKING_SPEED 0.037f
#define SIMON_JUMP_SPEED_Y 0.5f
#define SIMON_GRAVITY 0.1f

#define SIMON_STATE_IDLE_TURNBACK -100
#define SIMON_STATE_IDLE 0
#define SIMON_STATE_WALKING_RIGHT 100
#define SIMON_STATE_WALKING_LEFT 200
#define SIMON_STATE_JUMP 300
#define SIMON_STATE_SIT 400
#define SIMON_STATE_ATTACK 500

#define SIMON_ANI_IDLE_TURNBACK		0
#define SIMON_ANI_IDLE_LEFT			1
#define SIMON_ANI_WALKING_LEFT		2
#define SIMON_ANI_IDLE_RIGHT		3
#define SIMON_ANI_WALKING_RIGHT		4



class Simon : public GameObject
{
private:
	static Simon * _instance;
public:
	Simon();
	~Simon();
	static Simon * GetInstance();

	void LoadResource();

	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

