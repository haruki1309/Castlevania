#pragma once
#include "Scene.h"
#include "Define.h"
#define TEX_GAME_MENU "Resource\\GameMenuScene\\GameMenu.png"


class GameMenuScene : public Scene
{
private:

public:
	GameMenuScene();
	~GameMenuScene();

	void Update(DWORD dt);
	void LoadResource();
	void Initialize();
	void Draw();
	void DestroyAll();

	void OnKeyUp(int keyCode);
	void OnKeyDown(int keyCode);

	bool GetChangingState() { return Scene::GetChangingState(); }
	void SetChangingState(bool _isChangeState) { Scene::SetChangingState(_isChangeState); }

	D3DCOLOR GetBackColor();
};


