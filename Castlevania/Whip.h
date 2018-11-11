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
public:
	Whip();
	~Whip();

	static Whip * GetInstance();

	void LoadAnimation();

	void SetPosition(D3DXVECTOR3 _simonPosition, bool isStanding, int direction); 

	void SetType(int _type) { type = _type; }

	void Render(ViewPort * camera);
};

