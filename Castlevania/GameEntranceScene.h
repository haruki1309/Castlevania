#pragma once
#include "Scene.h"
#include "TileMap.h"
#include "Simon.h"


class GameEntranceScene : public Scene
{
private:
	TileMap * entranceMap;
	ViewPort * entranceViewPort;

public:
	GameEntranceScene();
	~GameEntranceScene();

	void Update(DWORD dt);
	void LoadResource();
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

