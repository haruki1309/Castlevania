#include "GameIntroScene.h"


void Bat::Update(DWORD dt)
{
	GameObject::Update(dt);
	this->position.x += vx * dt;
	this->position.y += vy * dt;
}

void Bat::Render(ViewPort * camera)
{
	this->animations[BAT_ANI_FLY]->Render(this->position.x, this->position.y);
}

void Cloud::Update(DWORD dt)
{
	GameObject::Update(dt);
	this->position.x += vx * dt;
	this->position.y += vy * dt;
}

void Cloud::Render(ViewPort * camera)
{
	this->animations[CLOUD_ANI_FLY]->Render(this->position.x, this->position.y);
}
//--------------------------------------------------------------------
GameIntroScene::GameIntroScene()
{
	bat1.SetPosition(36, 125);
	bat2.SetPosition(144, 62);
	cloud.SetPosition(215, 70);

	bat1.SetSpeed(0.01, -0.008);
	bat2.SetSpeed(-0.008, -0.002);
	cloud.SetSpeed(-0.008, 0);

	backColor = D3DCOLOR_XRGB(255, 0, 0);

	LoadResource();
	
}


GameIntroScene::~GameIntroScene()
{
}

void GameIntroScene::LoadAnimation()
{
	bat1.AddAnimation(2);
	bat2.AddAnimation(2);
	cloud.AddAnimation(3);
}

void GameIntroScene::Update(DWORD dt)
{
	Scene::Update(dt);

	Simon::GetInstance()->Update(dt);

	bat1.Update(dt);
	bat2.Update(dt);
	cloud.Update(dt);
	
	if (Simon::GetInstance()->GetPosition().x <= 122)
	{
		Simon::GetInstance()->SetState(SIMON_STATE_IDLE_TURNBACK);

		bat1.SetSpeed(0, 0);
		bat2.SetSpeed(0, 0);
		cloud.SetSpeed(0, 0);

		//this->SetChangingState(true);
	}
}

void GameIntroScene::Initialize()
{
	this->isChangeState = false;

	Simon::GetInstance()->SetState(SIMON_STATE_WALKING_LEFT);
	Simon::GetInstance()->SetPosition(240.0f, 168.0f);
	Simon::GetInstance()->SetSpeed(-0.03f, 0);
}

void GameIntroScene::DestroyAll()
{

}

void GameIntroScene::Draw()
{
	Sprites::GetInstance()->GetSprite(50)->Draw(0, 0);
	Simon::GetInstance()->Render(NULL);
	bat1.Render(NULL);
	bat2.Render(NULL);
	cloud.Render(NULL);
}

D3DCOLOR GameIntroScene::GetBackColor()
{
	return this->backColor;
}

void GameIntroScene::OnKeyUp(int keyCode)
{

}

void GameIntroScene::OnKeyDown(int keyCode)
{

}

void GameIntroScene::KeyState()
{

}
