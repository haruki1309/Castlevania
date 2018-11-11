#pragma once
#include "GameObject.h"

#define CANDLE_TEX "Resource\\Object\\Object.png"

class LargeCandles : public GameObject
{
private:
	int width, height;
public:
	LargeCandles();
	~LargeCandles();
	void SetState(int state);

	void Update(DWORD dt);
	void Render(ViewPort * camera);

	void LoadAnimation();
};

