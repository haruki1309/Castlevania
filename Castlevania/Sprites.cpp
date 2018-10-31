#include "Sprites.h"


//Structure of Sprite
Sprite::Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, D3DXVECTOR3 position)
{
	this->id = id;

	this->sourceRect.left = left;
	this->sourceRect.top = top;
	this->sourceRect.right = right;
	this->sourceRect.bottom = bottom;

	this->texture = tex;
	this->spriteHandler = NULL;
	this->spriteHandler = Graphics::GetInstance()->GetSpriteHandler();
	this->position = position;

}

void Sprite::Draw()
{
	if (spriteHandler)
	{
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandler->Draw(this->texture, &sourceRect, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));

		spriteHandler->End();
	}
	
}
void Sprite::Draw(int x, int y)
{
	if (spriteHandler)
	{
		position.x = x;
		position.y = y;
		position.z = 0;

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		spriteHandler->Draw(this->texture, &sourceRect, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));

		spriteHandler->End();
	}
}

void Sprite::Draw(D3DXVECTOR3 _position, RECT _rect)
{
	position = _position;
	sourceRect = _rect;

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	spriteHandler->Draw(this->texture, &sourceRect, NULL, &position, D3DCOLOR_XRGB(255, 255, 255));

	spriteHandler->End();
}

//Manage All Sprite:

Sprites * Sprites::instance = NULL;

Sprites *Sprites::GetInstance()
{
	if (instance == NULL) instance = new Sprites();
	return instance;
}

void Sprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex, D3DXVECTOR3 position)
{
	LPSPRITE s = new Sprite(id, left, top, right, bottom, tex, position);
	sprites[id] = s;
}

LPSPRITE Sprites::GetSprite(int id)
{
	return sprites[id];
}
