#include "Game.h"
#include "Sprites.h"

//Structure of Sprite
Sprite::Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
}

void Sprite::Draw(float x, float y)
{
	Game * game = Game::GetInstance();
	game->Draw(x, y, texture, left, top, right, bottom);
}


//Manage All Sprite:

Sprites * Sprites::instance = NULL;

Sprites *Sprites::GetInstance()
{
	if (instance == NULL) instance = new Sprites();
	return instance;
}

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new Sprite(id, left, top, right, bottom, tex);
	sprites[id] = s;
}

LPSPRITE Sprites::Get(int id)
{
	return sprites[id];
}
