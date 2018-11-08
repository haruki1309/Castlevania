#include "GameMenuScene.h"

void GameMenuScene::LoadResource()
{
	//load image to textures map
	Textures::GetInstance()->Add(0, TEX_GAME_MENU, D3DCOLOR_XRGB(128, 0, 0));

	//load sprite to sprites map from textures map
	Sprites::GetInstance()->Add(0, 2, 2, 258, 226, Textures::GetInstance()->GetTexture(0));

	//bat animation
	Sprites::GetInstance()->Add(1, 275, 2, 346, 57, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(2, 353, 2, 424, 57, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(3, 431, 2, 502, 57, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(4, 511, 2, 582, 57, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(5, 589, 2, 660, 57, Textures::GetInstance()->GetTexture(0));

	Sprites::GetInstance()->Add(6, 275, 63, 346, 118, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(7, 353, 63, 424, 118, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(8, 431, 63, 502, 118, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(9, 511, 63, 582, 118, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(10, 589, 63, 660, 118, Textures::GetInstance()->GetTexture(0));

	Sprites::GetInstance()->Add(11, 275, 125, 346, 180, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(12, 353, 125, 424, 180, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(13, 431, 125, 502, 180, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(14, 511, 125, 582, 180, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(15, 589, 125, 660, 180, Textures::GetInstance()->GetTexture(0));


	//title animation
	Sprites::GetInstance()->Add(16, 75, 130, 186, 137, Textures::GetInstance()->GetTexture(0));
	Sprites::GetInstance()->Add(17, 75, 138, 186, 145, Textures::GetInstance()->GetTexture(0));

	//load animationframe to animations map from sprite map

	LPANIMATION aniBat = new Animation(100);

	for (int i = 1; i <= 15; i++)
	{
		aniBat->Add(i);
	}

	LPANIMATION aniTitle = new Animation(100);
	for (int i = 16; i <= 17; i++)
	{
		aniTitle->Add(i);
	}

	Animations::GetInstance()->Add(0, aniBat);
	Animations::GetInstance()->Add(1, aniTitle);
}

GameMenuScene::GameMenuScene()
{
	backColor = D3DCOLOR_XRGB(255, 0, 0);

	LoadResource();
}


GameMenuScene::~GameMenuScene()
{

}

void GameMenuScene::Update(DWORD dt)
{
	Scene::Update(dt);
}

void GameMenuScene::Initialize()
{
	this->isChangeState = false;
}

void GameMenuScene::Draw()
{
	Sprites::GetInstance()->GetSprite(0)->Draw(0, 0);

	Animations::GetInstance()->GetAnimation(0)->Render(0, 0);
	
	Animations::GetInstance()->GetAnimation(1)->Render(0, 0);
	
}

void GameMenuScene::DestroyAll()
{

}

void GameMenuScene::OnKeyUp(int keyCode)
{

}

void GameMenuScene::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case DIK_SPACE:

		this->SetChangingState(true);

		break;
	}
}

void GameMenuScene::KeyState()
{

}

D3DCOLOR GameMenuScene::GetBackColor()
{
	return this->backColor;
}