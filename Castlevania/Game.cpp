#include "Game.h"


Game * Game::__instance = NULL;

Game::Game()
{
}

Game::~Game()
{

}

Game *Game::GetInstance()
{
	if (__instance == NULL) __instance = new Game();
	return __instance;
}


bool Game::Initialize(HWND hWnd)
{
	graphicsDevice = Graphics::GetInstance();

	inputDevice = InputDevice::GetInstance();

	this->hWnd = hWnd;

	if(!graphicsDevice->Initialize(this->hWnd, GAME_WINDOWED) || !inputDevice->Initialize(this->hWnd))
	{
		return false;
	}
	sceneManager = SceneManager::GetInstance();
	sceneManager->LoadScene(GAME_ENTRANCE_SCENE);
	return true;
}

void Game::Update(DWORD gameTime)
{
	sceneManager->Update(gameTime);
}

void Game::Render(DWORD gameTime)
{
	graphicsDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));

	if (graphicsDevice->Begin())
	{
		graphicsDevice->device->ColorFill(graphicsDevice->GetBackBuffer(), NULL, D3DCOLOR_XRGB(0, 0, 0));

		sceneManager->GetCurrentScene()->Draw();

		graphicsDevice->End();
	}

	graphicsDevice->Present(); // !!!
	
}

void Game::Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / FRAMERATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			inputDevice->ProcessKeyBoard();

			Update(dt);

			Render(dt);
		}
		else
			Sleep(tickPerFrame - dt);
	}
}
