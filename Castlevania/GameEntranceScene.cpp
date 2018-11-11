#include "GameEntranceScene.h"



GameEntranceScene::GameEntranceScene()
{
	Simon::GetInstance()->SetPosition(20, 152);
	entranceMap = new TileMap();
	entranceViewPort = new ViewPort();

	entranceViewPort->SetCameraPos(D3DXVECTOR3(0, 0, 0));
	entranceViewPort->SetCameraSize(256, 160);

	ui = new UI(Simon::GetInstance()->GetInfo().x, Simon::GetInstance()->GetInfo().y, Simon::GetInstance()->GetInfo().z, 1);
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
	gameTime += dt;
	if (gameTime >= 1000)
	{
		ui->Update(300 - (int)gameTime / 1000, Simon::GetInstance()->GetInfo().x, Simon::GetInstance()->GetInfo().y, Simon::GetInstance()->GetInfo().z, 1);
	}
	

	Scene::Update(dt);
	Simon::GetInstance()->Update(dt);

	D3DXVECTOR3 pos = entranceViewPort->GetCameraPos();
	if (Simon::GetInstance()->GetPosition().x >= 112)
	{
		pos.x += Simon::GetInstance()->vx * dt;
		if (Simon::GetInstance()->GetPosition().x >= 626)
		{
			pos.x = 512;

			if (Simon::GetInstance()->GetPosition().x >= 752)
			{
				Simon::GetInstance()->SetPosition(752, Simon::GetInstance()->GetPosition().y);
			}
		}
	}
	else
	{
		pos.x = 0;
		if (Simon::GetInstance()->GetPosition().x <= 0)
		{
			Simon::GetInstance()->SetPosition(0, Simon::GetInstance()->GetPosition().y);
		}
	}
	entranceViewPort->SetCameraPos(pos);
}

void GameEntranceScene::Initialize()
{
	Simon::GetInstance()->LoadAnimation();

	entranceMap->LoadMatrixMap("Resource\\Map\\MapState1_a_TileSet_bg.txt");
	entranceMap->InitTileSet(Sprites::GetInstance()->GetSprite(99));

	ui->Initialize();

	//load object
	LargeCandles * lCandles;

	lCandles = new LargeCandles();
	lCandles->SetPosition(80, 152);
	listStaticObject.push_back(lCandles);

	lCandles = new LargeCandles();
	lCandles->SetPosition(216, 152);
	listStaticObject.push_back(lCandles);

	lCandles = new LargeCandles();
	lCandles->SetPosition(352, 152);
	listStaticObject.push_back(lCandles);

	lCandles = new LargeCandles();
	lCandles->SetPosition(472, 152);
	listStaticObject.push_back(lCandles);

	lCandles = new LargeCandles();
	lCandles->SetPosition(600, 152);
	listStaticObject.push_back(lCandles);

}
void GameEntranceScene::Draw()
{
	ui->Render();

	entranceMap->Draw(entranceViewPort);

	for (int i = 0; i < listStaticObject.size(); i++)
	{
		listStaticObject[i]->Render(entranceViewPort);
	}

	Simon::GetInstance()->Render(entranceViewPort);	
}
void GameEntranceScene::DestroyAll()
{

}
D3DCOLOR GameEntranceScene::GetBackColor()
{
	return this->backColor;
}