#pragma once
#include "Scene.h"
#include "TileMap.h"
#include "UI.h"
#include "Simon.h"
#include "Candles.h"


class GameEntranceScene : public Scene
{
private:
	TileMap * entranceMap;
	ViewPort * entranceViewPort;
	UI * ui;
	vector<LPGAMEOBJECT> listStaticObject;
	vector<LPGAMEOBJECT> listMovingObject;
public:
	GameEntranceScene();
	~GameEntranceScene();

	void Update(DWORD dt);
	void Initialize();
	void Draw();
	void DestroyAll();

	void OnKeyUp(int keyCode);
	void OnKeyDown(int keyCode);
	void KeyState();

	bool GetChangingState() { return Scene::GetChangingState(); }
	void SetChangingState(bool _isChangeState) { Scene::SetChangingState(_isChangeState); }

	D3DCOLOR GetBackColor();
};

