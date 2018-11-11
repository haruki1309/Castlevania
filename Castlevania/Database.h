#pragma once
#include "d3d9.h"
#include "Textures.h"
#include "Sprites.h"
#include "Animations.h"

#define TEX_SIMON_SOURCE			"Resource\\Simon.png"
#define TEX_WHIP_SOURCE				"Resource\\Weapons\\Whip.png"
#define TEX_CANDLE_SOURCE			"Resource\\Object\\Object.png"
#define TEX_GAME_MENU_SOURCE		"Resource\\GameMenuScene\\GameMenu.png"
#define TEX_GAME_INTRO_SOURCE		"Resource\\GameIntroScene\\GameIntro.png"
#define TEX_GAME_ENTRANCE_SOURCE	"Resource\\Map\\MapState1_a_TileSet.png"
#define TEX_CANDLE_SOURCE			"Resource\\Object\\Object.png"
#define TEX_SUBWEAPONS_SOURCE		"Resource\\Weapons\\SubWeapons.png"

#define TEX_SIMON_ID				0
#define TEX_WHIP_ID					1
#define TEX_GAME_MENU_SCENE_ID		2
#define TEX_GAME_INTRO_SCENE_ID		3
#define TEX_GAME_ENTRANCE_SCENE_ID	4
#define TEX_CANDLE_SOURCE_ID		5
#define TEX_SUBWEAPONS_ID			6

class Database
{
	static Database * instance;
public:
	Database();
	~Database();
	static Database * GetInstance();

	void LoadTexture();
	void CreateSprite();
	void CreateAnimation();
};

