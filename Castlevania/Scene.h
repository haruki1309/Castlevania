#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "Textures.h"
#include "Animations.h"
#include "InputDevice.h"


class Scene
{
protected:
	D3DCOLOR backColor;

	bool isChangeState;

public:
	Scene() {};
	~Scene() {};

	virtual void Update(DWORD dt);
	virtual void LoadResource();
	virtual void Initialize() = 0;
	virtual void Draw() = 0;
	virtual void DestroyAll() = 0;

	virtual void OnKeyUp(int keyCode) = 0;
	virtual void OnKeyDown(int keyCode) = 0;
	virtual void KeyState() = 0;
	virtual bool GetChangingState() { return this->isChangeState; }
	virtual void SetChangingState(bool _isChangeState) { this->isChangeState = _isChangeState; }

	virtual D3DCOLOR GetBackColor() = 0;
};

