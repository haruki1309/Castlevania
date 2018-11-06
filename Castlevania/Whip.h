#pragma once
#include "GameObject.h"


#define NOMAL_WHIP 0
#define SMALL_WHIP 1
#define YELLOW_WHIP 2
#define RED_WHIP 3
#define BLUE_WHIP 4
#define VIOLET_WHIP 5

#define WHIP_TEX "Resource\\Weapons\\Whip.png"

class Whip : public GameObject
{
private:
	static Whip * _instance;
	int type;
	bool isLeft;

public:
	Whip();
	~Whip();

	static Whip * GetInstance();

	void LoadResource();

	void SetPosition(D3DXVECTOR3 _simonPosition, bool isStanding, int direction); 

	void SetIsLeft(bool _isLeft) { isLeft = _isLeft; }

	void SetType(int _type) { type = _type; }

	void Render();

	int GetCurrentFrame() { return animations[type]->GetCurrentFrame(); }
};

