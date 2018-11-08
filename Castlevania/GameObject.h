#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>
#include"Animations.h"
#include "Sprites.h"
#include "ViewPort.h"

using namespace std;

#define ID_TEX_BBOX -100		// special texture to draw object bounding box

class GameObject;
typedef GameObject * LPGAMEOBJECT;

class GameObject
{
public:
	D3DXVECTOR3 position;

	float dx;	// dx = vx*dt
	float dy;	// dy = vy*dt

	float vx;
	float vy;

	int nx;

	int state;

	DWORD dt;

	vector<LPANIMATION> animations;

public:
	void SetPosition(float x, float y) { this->position.x = x, this->position.y = y; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->vy = vy; }
	void SetDirection(int _nx) { this->nx = _nx; }

	D3DXVECTOR3 GetPosition() { return this->position; }
	void GetSpeed(float &vx, float &vy) { vx = this->vx; vy = this->vy; }
	int GetState() { return this->state; }
	void AddAnimation(int aniId);

	virtual void Update(DWORD dt);
	virtual void Render(ViewPort * camera) = 0;
	virtual void SetState(int state) { this->state = state; }

	GameObject();
	~GameObject();
};

