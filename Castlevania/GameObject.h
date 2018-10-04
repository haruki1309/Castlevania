#pragma once
#include "Define.h"
#include "Game.h"

#include <Windows.h>
#include <d3dx9.h>
#include <vector>


class GameObject
{
protected:
	float x;
	float y;

	LPDIRECT3DTEXTURE9 texture;
public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }

	GameObject(LPCSTR texturePath);
	void Update(DWORD dt);
	void Render();
	~GameObject();
};

