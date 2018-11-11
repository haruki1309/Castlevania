#include "GameMenuScene.h"

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