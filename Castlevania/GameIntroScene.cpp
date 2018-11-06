#include "GameIntroScene.h"


void Bat::Update(DWORD dt)
{
	GameObject::Update(dt);
}

void Bat::Render()
{
	this->animations[BAT_ANI_FLY]->Render(this->position.x, this->position.y);
}

void Cloud::Update(DWORD dt)
{
	GameObject::Update(dt);
}

void Cloud::Render()
{
	this->animations[CLOUD_ANI_FLY]->Render(this->position.x, this->position.y);
}
//--------------------------------------------------------------------
GameIntroScene::GameIntroScene()
{
	this->texturesManager = new Textures(); //may cai nay chac khong can, t se chuyen thanh lay truc tiep luon
	this->spriteManager = new Sprites();
	this->animationManager = new Animations();

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

void GameIntroScene::LoadResource()
{
	Scene::LoadResource();

	texturesManager->Add(1, TEX_GAME_INTRO, D3DCOLOR_XRGB(128, 0, 0));
	//background
	spriteManager->Add(50, 6, 6, 262, 230, texturesManager->GetTexture(1), D3DXVECTOR3(0, 0, 0));

	//bat
	D3DXVECTOR3 batPos = D3DXVECTOR3(238, 170, 0);
	spriteManager->Add(51, 287, 102, 295, 109, texturesManager->GetTexture(1), batPos);
	spriteManager->Add(52, 274, 102, 282, 110, texturesManager->GetTexture(1), batPos);
	

	LPANIMATION aniBatFly = new Animation(50);
	aniBatFly->Add(51);
	aniBatFly->Add(52);

	animationManager->Add(2, aniBatFly);
	bat1.AddAnimation(2);
	bat2.AddAnimation(2);

	//cloud :) 
	spriteManager->Add(53, 268, 78, 300, 92, texturesManager->GetTexture(1), D3DXVECTOR3(0, 0, 0));
	LPANIMATION aniCloudFly = new Animation(120);
	aniCloudFly->Add(53);
	animationManager->Add(3, aniCloudFly);
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
	Simon::GetInstance()->SetPosition(240, 168);
}

void GameIntroScene::DestroyAll()
{

}

void GameIntroScene::Draw()
{
	spriteManager->GetSprite(50)->Draw();

	Simon::GetInstance()->Render();

	bat1.Render();
	bat2.Render();
	cloud.Render();
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
