#include "GameEntranceScene.h"



GameEntranceScene::GameEntranceScene()
{
	Simon::GetInstance()->SetPosition(10, 152);
	entranceMap = new TileMap();
	entranceViewPort = new ViewPort();

	entranceViewPort->SetCameraPos(D3DXVECTOR3(0, 0, 0));
	entranceViewPort->SetCameraSize(256, 160);

	LoadResource();
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
	
}
void GameEntranceScene::OnKeyDown(int keyCode)
{
	Simon::GetInstance()->HandleEvent(true);

	if (InputDevice::GetInstance()->IsKeyDown(DIK_D))
	{
		D3DXVECTOR3 currentCamPos = entranceViewPort->GetCameraPos();
		currentCamPos.x++;
		entranceViewPort->SetCameraPos(currentCamPos);
	}	
}


void GameEntranceScene::Update(DWORD dt)
{
	Scene::Update(dt);
	Simon::GetInstance()->Update(dt);

	D3DXVECTOR3 currentCamPos = entranceViewPort->GetCameraPos();
	entranceViewPort->SetCameraPos(currentCamPos);
}
void GameEntranceScene::LoadResource()
{
	Scene::LoadResource();

	texturesManager->Add(2, "Resource\\Map\\MapState1_a_TileSet.png", D3DCOLOR_XRGB(0, 0, 0));

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
	Simon::GetInstance()->Render();
}
void GameEntranceScene::DestroyAll()
{

}
D3DCOLOR GameEntranceScene::GetBackColor()
{
	return this->backColor;
}