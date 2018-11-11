#pragma once
#include "GameObject.h"

class SW_Axe : public GameObject
{
public:
	SW_Axe();
	~SW_Axe();

	void LoadAnimation();
	void SetInfo(D3DXVECTOR3 _simonPosition, bool isStanding, int direction);
	void Render(ViewPort * camera);
	void Update(DWORD dt);
};

