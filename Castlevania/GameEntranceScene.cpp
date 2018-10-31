#include "GameEntranceScene.h"



GameEntranceScene::GameEntranceScene()
{
	entranceMap = new TileMap();
	entranceViewPort = new ViewPort();

	entranceViewPort->SetCameraPos(0, 40);
	entranceViewPort->SetCameraSize(256, 160);

	LoadResource();
}


GameEntranceScene::~GameEntranceScene()
{
}


void GameEntranceScene::OnKeyUp(int keyCode)
{

}
void GameEntranceScene::OnKeyDown(int keyCode)
{
	if (keyCode == DIK_SPACE)
	{
		D3DXVECTOR3 pos = entranceViewPort->GetCameraPos();
		pos.x -= 5;

		entranceViewPort->SetCameraPos(pos.x, pos.y);

		Draw();
	}
	

}


void GameEntranceScene::Update(DWORD dt)
{
	Scene::Update(dt);
}
void GameEntranceScene::LoadResource()
{
	Scene::LoadResource();

	texturesManager->Add(2, "Resource\\Map\\MapState1_a_TileSet.png", D3DCOLOR_XRGB(255, 255, 255));

	spriteManager->Add(100, 0, 0, 256, 224, texturesManager->GetTexture(2), D3DXVECTOR3(0, 0, 0));

	entranceMap->LoadMatrixMap("Resource\\Map\\MapState1_a_TileSet_bg.txt");
}
void GameEntranceScene::Initialize()
{
	entranceMap->InitTileSet(spriteManager->GetSprite(100));
}
void GameEntranceScene::Draw()
{
	entranceMap->Draw(entranceViewPort);
}
void GameEntranceScene::DestroyAll()
{

}
D3DCOLOR GameEntranceScene::GetBackColor()
{
	return this->backColor;
}