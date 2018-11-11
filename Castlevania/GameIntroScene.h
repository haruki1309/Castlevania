#pragma once
#include "Scene.h"
#include "Define.h"
#include "Simon.h"
#include "GameObject.h"

#define TEX_GAME_INTRO "Resource\\GameIntroScene\\GameIntro.png"

//Bat and Cloud: define in GameIntroScene.h
#define BAT_ANI_FLY 0

class Bat : public GameObject
{
public:
	void Update(DWORD dt);
	void Render(ViewPort * camera);
	void SetState(int state) { this->state = state; }
};

//--------------------------------------------------------------
#define CLOUD_ANI_FLY 0
class Cloud : public GameObject
{
public:
	void Update(DWORD dt);
	void Render(ViewPort * camera);
	void SetState(int state) { this->state = state; }
};



//--------------------------------------------------------------
class GameIntroScene : public Scene
{
private:
	Bat bat1, bat2;
	Cloud cloud;
public:
	GameIntroScene();
	~GameIntroScene();

	void Update(DWORD dt);
	void LoadAnimation();
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

