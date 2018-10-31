#include "GameMenuScene.h"

void GameMenuScene::LoadResource()
{
	Scene::LoadResource();

	//load image to textures map
	texturesManager->Add(0, TEX_GAME_MENU, D3DCOLOR_XRGB(255, 255, 255));

	//load sprite to sprites map from textures map
	spriteManager->Add(0, 2, 2, 258, 226, texturesManager->GetTexture(0), D3DXVECTOR3(0, 0, 0));

	D3DXVECTOR3 batPosision = D3DXVECTOR3(185, 97, 0);

	//bat animation
	spriteManager->Add(1, 275, 2, 346, 57, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(2, 353, 2, 424, 57, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(3, 431, 2, 502, 57, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(4, 511, 2, 582, 57, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(5, 589, 2, 660, 57, Textures::GetInstance()->GetTexture(0), batPosision);

	spriteManager->Add(6, 275, 63, 346, 118, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(7, 353, 63, 424, 118, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(8, 431, 63, 502, 118, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(9, 511, 63, 582, 118, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(10, 589, 63, 660, 118, Textures::GetInstance()->GetTexture(0), batPosision);

	spriteManager->Add(11, 275, 125, 346, 180, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(12, 353, 125, 424, 180, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(13, 431, 125, 502, 180, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(14, 511, 125, 582, 180, Textures::GetInstance()->GetTexture(0), batPosision);
	spriteManager->Add(15, 589, 125, 660, 180, Textures::GetInstance()->GetTexture(0), batPosision);


	//title animation
	spriteManager->Add(16, 75, 130, 186, 137, Textures::GetInstance()->GetTexture(0), D3DXVECTOR3(73, 128, 0));
	spriteManager->Add(17, 75, 138, 186, 145, Textures::GetInstance()->GetTexture(0), D3DXVECTOR3(73, 128, 0));

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

	animationManager->Add(0, aniBat);
	animationManager->Add(1, aniTitle);
}

GameMenuScene::GameMenuScene()
{
	this->texturesManager = new Textures();
	this->spriteManager = new Sprites();
	this->animationManager = new Animations();

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
	spriteManager->GetSprite(0)->Draw();

	animationManager->GetAnimation(0)->Render();
	
	animationManager->GetAnimation(1)->Render();
	
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


D3DCOLOR GameMenuScene::GetBackColor()
{
	return this->backColor;
}