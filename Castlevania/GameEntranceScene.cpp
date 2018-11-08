#include "GameEntranceScene.h"



GameEntranceScene::GameEntranceScene()
{
	Simon::GetInstance()->SetPosition(10, 152);
	entranceMap = new TileMap();
	entranceViewPort = new ViewPort();

	entranceViewPort->SetCameraPos(D3DXVECTOR3(0, 0, 0));
	entranceViewPort->SetCameraSize(256, 160);
}


GameEntranceScene::~GameEntranceScene()
{
}

void GameEntranceScene::KeyState()
{
	Simon::GetInstance()->HandleMove();

}

void GameEntranceScene::OnKeyUp(int keyCode)
{
	Simon::GetInstance()->HandleEvent(false);
}

void GameEntranceScene::OnKeyDown(int keyCode)
{
	Simon::GetInstance()->HandleEvent(true);
}
void GameEntranceScene::Update(DWORD dt)
{
	Scene::Update(dt);
	Simon::GetInstance()->Update(dt);

	D3DXVECTOR3 pos = entranceViewPort->GetCameraPos();
	pos.x += Simon::GetInstance()->vx * dt;
	entranceViewPort->SetCameraPos(pos);
	
}
void GameEntranceScene::LoadResource()
{
	Textures::GetInstance()->Add(2, "Resource\\Map\\MapState1_a_TileSet.png", D3DCOLOR_XRGB(255, 0, 255));
	Sprites::GetInstance()->Add(99, 0, 0, 256, 64, Textures::GetInstance()->GetTexture(2));

	entranceMap->LoadMatrixMap("Resource\\Map\\MapState1_a_TileSet_bg.txt");
	entranceMap->InitTileSet(Sprites::GetInstance()->GetSprite(99));

}
void GameEntranceScene::Initialize()
{
	LoadResource();
}
void GameEntranceScene::Draw()
{
	entranceMap->Draw(entranceViewPort);
	Simon::GetInstance()->Render(entranceViewPort);
}
void GameEntranceScene::DestroyAll()
{

}
D3DCOLOR GameEntranceScene::GetBackColor()
{
	return this->backColor;
}