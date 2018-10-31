#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include "Graphics.h"
#include <unordered_map>

using namespace std;

//Stuct Sprite
class Sprite
{
private:
	int						id;				// Sprite ID in the sprite database

	RECT					sourceRect;
	LPD3DXSPRITE			spriteHandler;
	LPDIRECT3DTEXTURE9		texture;

	D3DXVECTOR3				position;

public:
	Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, D3DXVECTOR3 position);

	void Draw();
	void Draw(int x, int y);
	void Draw(D3DXVECTOR3 position, RECT rect);
};

typedef Sprite * LPSPRITE;

//Sprite Manager
class Sprites
{
	static Sprites * instance;

	unordered_map<int, LPSPRITE> sprites;

public:
	void Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, D3DXVECTOR3 position);
	LPSPRITE GetSprite(int id);

	static Sprites * GetInstance();
};

