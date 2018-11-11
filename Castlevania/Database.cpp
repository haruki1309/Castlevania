#include "Database.h"

Database * Database::instance = NULL;

Database::Database()
{
}

Database::~Database()
{
}

Database * Database::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Database();
	}
	return instance;
}

void Database::LoadTexture()
{
	Textures::GetInstance()->Add(TEX_SIMON_ID, TEX_SIMON_SOURCE, D3DCOLOR_XRGB(0, 128, 128));

	Textures::GetInstance()->Add(TEX_WHIP_ID, TEX_WHIP_SOURCE, D3DCOLOR_XRGB(0, 128, 128));

	Textures::GetInstance()->Add(TEX_CANDLE_SOURCE_ID, TEX_CANDLE_SOURCE, D3DCOLOR_XRGB(34, 177, 76));

	Textures::GetInstance()->Add(TEX_GAME_MENU_SCENE_ID, TEX_GAME_MENU_SOURCE, D3DCOLOR_XRGB(128, 0, 0));

	Textures::GetInstance()->Add(TEX_GAME_INTRO_SCENE_ID, TEX_GAME_INTRO_SOURCE, D3DCOLOR_XRGB(128, 0, 0));

	Textures::GetInstance()->Add(TEX_GAME_ENTRANCE_SCENE_ID, TEX_GAME_ENTRANCE_SOURCE, D3DCOLOR_XRGB(255, 0, 255));

	Textures::GetInstance()->Add(TEX_SUBWEAPONS_ID, TEX_SUBWEAPONS_SOURCE, D3DCOLOR_XRGB(255, 0, 255));
}

void Database::CreateSprite()
{
#pragma region Sprite Simon
	//turn back
	Sprites::GetInstance()->Add(-201, 249, 7, 265, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//sit left
	Sprites::GetInstance()->Add(-200, 87, 7, 103, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//idle left + walking left
	Sprites::GetInstance()->Add(-199, 4, 7, 20, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-198, 29, 7, 45, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-197, 58, 7, 74, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//upstairs left
	Sprites::GetInstance()->Add(-196, 156, 7, 172, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//downstairs left
	Sprites::GetInstance()->Add(-195, 131, 7, 147, 39, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//stand attack left
	Sprites::GetInstance()->Add(-194, 27, 46, 43, 78, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-193, 58, 46, 74, 78, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-192, 88, 46, 104, 78, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//sit attack left
	Sprites::GetInstance()->Add(-191, 26, 91, 42, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-190, 55, 91, 71, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-189, 85, 91, 101, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//upstairs attack left
	Sprites::GetInstance()->Add(-188, 129, 47, 145, 79, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-187, 159, 47, 175, 79, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-186, 194, 47, 210, 79, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//downstairs attack left
	Sprites::GetInstance()->Add(-185, 129, 91, 145, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-184, 158, 91, 174, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-183, 194, 91, 210, 123, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));


	//eat sp item left
	Sprites::GetInstance()->Add(-182, 228, 89, 224, 121, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-181, 252, 89, 268, 121, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-180, 227, 47, 243, 79, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-179, 249, 47, 265, 79, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//======================================================================
	//sit right
	Sprites::GetInstance()->Add(-178, 172, 136, 188, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//idle right + walking right
	Sprites::GetInstance()->Add(-177, 255, 136, 271, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-176, 230, 136, 247, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-175, 201, 136, 217, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//upstairs right
	Sprites::GetInstance()->Add(-174, 103, 136, 119, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//downstairs right
	Sprites::GetInstance()->Add(-173, 128, 136, 145, 168, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	
	//stand attack right
	Sprites::GetInstance()->Add(-172, 232, 175, 248, 207, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-171, 201, 175, 217, 207, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-170, 171, 175, 187, 207, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//sit attack right
	Sprites::GetInstance()->Add(-169, 233, 220, 249, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-168, 204, 220, 220, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-167, 174, 220, 190, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//upstairs attack right
	Sprites::GetInstance()->Add(-166, 130, 176, 146, 208, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-165, 100, 176, 116, 208, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-164, 65, 176, 81, 208, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//downstairs attack right
	Sprites::GetInstance()->Add(-163, 130, 220, 146, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-162, 101, 220, 117, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-161, 65, 220, 81, 252, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));

	//eat sp item right
	Sprites::GetInstance()->Add(-160, 31, 218, 47, 250, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-159, 7, 218, 23, 250, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-158, 32, 176, 48, 208, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
	Sprites::GetInstance()->Add(-157, 10, 176, 26, 208, Textures::GetInstance()->GetTexture(TEX_SIMON_ID));
#pragma endregion

#pragma region Sprite Whip
	//nomal left
	Sprites::GetInstance()->Add(100, 8, 9, 68, 38, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(101, 92, 9, 152, 31, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(102, 179, 9, 208, 22, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));

	//nomal right
	Sprites::GetInstance()->Add(103, 432, 9, 448, 38, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(104, 348, 9, 364, 31, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(105, 260, 9, 320, 38, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));

	//red left
	Sprites::GetInstance()->Add(106, 33, 133, 109, 162, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(107, 117, 133, 193, 155, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(108, 203, 133, 248, 145, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));

	//red right
	Sprites::GetInstance()->Add(109, 473, 133, 489, 162, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(110, 389, 133, 405, 155, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));
	Sprites::GetInstance()->Add(111, 302, 133, 378, 145, Textures::GetInstance()->GetTexture(TEX_WHIP_ID));


#pragma endregion

#pragma region Sprite Menu
	//load sprite to sprites map from textures map
	Sprites::GetInstance()->Add(0, 2, 2, 258, 226, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));

	//bat animation
	Sprites::GetInstance()->Add(1, 275, 2, 346, 57, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(2, 353, 2, 424, 57, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(3, 431, 2, 502, 57, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(4, 511, 2, 582, 57, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(5, 589, 2, 660, 57, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));

	Sprites::GetInstance()->Add(6, 275, 63, 346, 118, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(7, 353, 63, 424, 118, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(8, 431, 63, 502, 118, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(9, 511, 63, 582, 118, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(10, 589, 63, 660, 118, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));

	Sprites::GetInstance()->Add(11, 275, 125, 346, 180, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(12, 353, 125, 424, 180, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(13, 431, 125, 502, 180, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(14, 511, 125, 582, 180, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(15, 589, 125, 660, 180, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));


	//title animation
	Sprites::GetInstance()->Add(16, 75, 130, 186, 137, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
	Sprites::GetInstance()->Add(17, 75, 138, 186, 145, Textures::GetInstance()->GetTexture(TEX_GAME_MENU_SCENE_ID));
#pragma endregion

#pragma region Sprite Intro
	//background
	Sprites::GetInstance()->Add(50, 6, 6, 262, 230, Textures::GetInstance()->GetTexture(TEX_GAME_INTRO_SCENE_ID));

	//bat
	Sprites::GetInstance()->Add(51, 287, 102, 295, 109, Textures::GetInstance()->GetTexture(TEX_GAME_INTRO_SCENE_ID));
	Sprites::GetInstance()->Add(52, 274, 102, 282, 110, Textures::GetInstance()->GetTexture(TEX_GAME_INTRO_SCENE_ID));

	//cloud
	Sprites::GetInstance()->Add(53, 268, 78, 300, 92, Textures::GetInstance()->GetTexture(TEX_GAME_INTRO_SCENE_ID));
#pragma endregion

#pragma region Sprite Entrance
	Sprites::GetInstance()->Add(99, 0, 0, 256, 64, Textures::GetInstance()->GetTexture(TEX_GAME_ENTRANCE_SCENE_ID));
#pragma endregion

#pragma region Sprite Large candle
	Sprites::GetInstance()->Add(401, 44, 21, 60, 53, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));
	Sprites::GetInstance()->Add(402, 71, 21, 87, 53, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));
#pragma endregion

#pragma region Sprite Object Hitted
	Sprites::GetInstance()->Add(403, 11, 73, 19, 86, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));
	Sprites::GetInstance()->Add(404, 27, 73, 35, 86, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));
	Sprites::GetInstance()->Add(405, 38, 73, 46, 86, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));
	Sprites::GetInstance()->Add(406, 52, 73, 60, 86, Textures::GetInstance()->GetTexture(TEX_CANDLE_SOURCE_ID));

#pragma endregion

#pragma region Sub Weapons
	//AXE
	Sprites::GetInstance()->Add(600, 0, 0, 16, 16, Textures::GetInstance()->GetTexture(TEX_SUBWEAPONS_ID));
	Sprites::GetInstance()->Add(601, 16, 0, 32, 16, Textures::GetInstance()->GetTexture(TEX_SUBWEAPONS_ID));
	Sprites::GetInstance()->Add(602, 32, 0, 48, 16, Textures::GetInstance()->GetTexture(TEX_SUBWEAPONS_ID));
	Sprites::GetInstance()->Add(603, 48, 0, 64, 16, Textures::GetInstance()->GetTexture(TEX_SUBWEAPONS_ID));

#pragma endregion
}

void Database::CreateAnimation()
{
#pragma region Animation Simon
	LPANIMATION aniTurningBack = new Animation(120);
	aniTurningBack->Add(-201);
	Animations::GetInstance()->Add(-50, aniTurningBack); // 0 animation turn back

	LPANIMATION aniSitLeft = new Animation(120);
	aniSitLeft->Add(-200);
	Animations::GetInstance()->Add(-49, aniSitLeft); // 1 animation sit left

	LPANIMATION aniIdleLeft = new Animation(100);
	aniIdleLeft->Add(-199);
	Animations::GetInstance()->Add(-48, aniIdleLeft); // 2 animation idle left

	LPANIMATION aniWalkingLeft = new Animation(100);
	aniWalkingLeft->Add(-199);
	aniWalkingLeft->Add(-198);
	aniWalkingLeft->Add(-197);
	aniWalkingLeft->Add(-198);
	Animations::GetInstance()->Add(-47, aniWalkingLeft); //3 animation walking left

	LPANIMATION aniUpstairLeft = new Animation(120);
	aniUpstairLeft->Add(-196);
	aniUpstairLeft->Add(-198);
	Animations::GetInstance()->Add(-46, aniUpstairLeft); // 4 animation upstairs left

	LPANIMATION aniDownstairLeft = new Animation(120);
	aniDownstairLeft->Add(-195);
	aniDownstairLeft->Add(-198);
	Animations::GetInstance()->Add(-45, aniDownstairLeft); // 5 animation downstairs left

	LPANIMATION aniStandAttackLeft = new Animation(100);
	aniStandAttackLeft->Add(-194);
	aniStandAttackLeft->Add(-193);
	aniStandAttackLeft->Add(-192, 200);
	Animations::GetInstance()->Add(-44, aniStandAttackLeft); // 6 animation stand attack left

	LPANIMATION aniSitAttackLeft = new Animation(100);
	aniSitAttackLeft->Add(-191);
	aniSitAttackLeft->Add(-190);
	aniSitAttackLeft->Add(-189, 200);
	Animations::GetInstance()->Add(-43, aniSitAttackLeft); // 7 animation sit attack left


	LPANIMATION aniUpStairsAttackLeft = new Animation(100);
	aniUpStairsAttackLeft->Add(-188);
	aniUpStairsAttackLeft->Add(-187);
	aniUpStairsAttackLeft->Add(-186, 200);
	Animations::GetInstance()->Add(-42, aniUpStairsAttackLeft); // 8 animation upstairs attack left

	LPANIMATION aniDownStairsAttackLeft = new Animation(100);
	aniDownStairsAttackLeft->Add(-185);
	aniDownStairsAttackLeft->Add(-184);
	aniDownStairsAttackLeft->Add(-183, 200);
	Animations::GetInstance()->Add(-41, aniDownStairsAttackLeft); // 9 animation downstairs attack left
	
	LPANIMATION aniEatSpItemLeft = new Animation(120);
	aniEatSpItemLeft->Add(-182);
	aniEatSpItemLeft->Add(-181);
	aniEatSpItemLeft->Add(-180);
	aniEatSpItemLeft->Add(-179);
	Animations::GetInstance()->Add(-40, aniEatSpItemLeft); // 10 animation eat sp item left

	//=======================================================================================

	LPANIMATION aniSitRight = new Animation(120);
	aniSitRight->Add(-178);
	Animations::GetInstance()->Add(-39, aniSitRight); // 11 animation sit right

	LPANIMATION aniIdleRight = new Animation(120);
	aniIdleRight->Add(-177);
	Animations::GetInstance()->Add(-38, aniIdleRight); // 12 animation idle right

	LPANIMATION aniWalkingRight = new Animation(100);
	aniWalkingRight->Add(-177);
	aniWalkingRight->Add(-176);
	aniWalkingRight->Add(-175);
	aniWalkingRight->Add(-176);
	Animations::GetInstance()->Add(-37, aniWalkingRight); // 13 animation walking right

	LPANIMATION aniUpstairRight = new Animation(120);
	aniUpstairRight->Add(-174);
	aniUpstairRight->Add(-176);
	Animations::GetInstance()->Add(-36, aniUpstairRight); // 14 animation upstairs right

	LPANIMATION aniDownstairRight = new Animation(120);
	aniDownstairRight->Add(-173);
	aniDownstairRight->Add(-176);
	Animations::GetInstance()->Add(-35, aniDownstairRight); // 15 animation downstairs right

	LPANIMATION aniStandAttackRight = new Animation(100);
	aniStandAttackRight->Add(-172);
	aniStandAttackRight->Add(-171);
	aniStandAttackRight->Add(-170, 200);
	Animations::GetInstance()->Add(-34, aniStandAttackRight); // 16 animation stand attack right

	LPANIMATION aniSitAttackRight = new Animation(100);
	aniSitAttackRight->Add(-169);
	aniSitAttackRight->Add(-168);
	aniSitAttackRight->Add(-167, 200);
	Animations::GetInstance()->Add(-33, aniSitAttackRight); // 17 animation sit attack right

	LPANIMATION aniUpStairsAttackRight = new Animation(100);
	aniUpStairsAttackRight->Add(-166);
	aniUpStairsAttackRight->Add(-165);
	aniUpStairsAttackRight->Add(-164, 200);
	Animations::GetInstance()->Add(-32, aniUpStairsAttackRight); // 18 animation upstairs attack right

	LPANIMATION aniDownStairsAttackRight = new Animation(100);
	aniDownStairsAttackRight->Add(-163);
	aniDownStairsAttackRight->Add(-162);
	aniDownStairsAttackRight->Add(-161, 200);
	Animations::GetInstance()->Add(-31, aniDownStairsAttackRight); // 19 animation downstairs attack right

	LPANIMATION aniEatSpItemRight = new Animation(120);
	aniEatSpItemRight->Add(-160);
	aniEatSpItemRight->Add(-159);
	aniEatSpItemRight->Add(-158);
	aniEatSpItemRight->Add(-157);
	Animations::GetInstance()->Add(-30, aniEatSpItemRight); // 20 animation eat sp item attack right
#pragma endregion

#pragma region Animation Whip														
	LPANIMATION aniNomalLeft = new Animation(100);
	aniNomalLeft->Add(100);
	aniNomalLeft->Add(101);
	aniNomalLeft->Add(102, 200);
	Animations::GetInstance()->Add(100, aniNomalLeft); // 0 animation nomal left
					
	LPANIMATION aniNomalRight = new Animation(100);
	aniNomalRight->Add(103);
	aniNomalRight->Add(104);
	aniNomalRight->Add(105, 200);
	Animations::GetInstance()->Add(101, aniNomalRight); // 1 animation nomal left

	LPANIMATION aniRedLeft = new Animation(100);
	aniRedLeft->Add(106);
	aniRedLeft->Add(107);
	aniRedLeft->Add(108, 200);
	Animations::GetInstance()->Add(102, aniRedLeft); // 0 animation nomal left

	LPANIMATION aniRedRight = new Animation(100);
	aniRedRight->Add(109);
	aniRedRight->Add(110);
	aniRedRight->Add(111, 200);
	Animations::GetInstance()->Add(103, aniRedRight); // 1 animation nomal left
#pragma endregion

#pragma region Animation Menu
														
	LPANIMATION aniBat = new Animation(100);

	for (int i = 1; i <= 15; i++)
	{
		aniBat->Add(i);
	}

	LPANIMATION aniTitle = new Animation(100);
	for (int i = 16; i <= 17; i++)
	{
		aniTitle->Add(i);
	}

	Animations::GetInstance()->Add(0, aniBat);
	Animations::GetInstance()->Add(1, aniTitle);

#pragma endregion

#pragma region Animation Intro
	LPANIMATION aniBatFly = new Animation(50);
	aniBatFly->Add(51);
	aniBatFly->Add(52);
	Animations::GetInstance()->Add(2, aniBatFly); // bat fly

	LPANIMATION aniCloudFly = new Animation(120);
	aniCloudFly->Add(53);
	Animations::GetInstance()->Add(3, aniCloudFly); // cloud

#pragma endregion

#pragma region Animation Large candle
	LPANIMATION aniBurn = new Animation(100);
	aniBurn->Add(401);
	aniBurn->Add(402);
	Animations::GetInstance()->Add(500, aniBurn); // nomal ani
#pragma endregion

#pragma region Animation Object Hitted
	LPANIMATION aniHit = new Animation(100);
	aniHit->Add(403);
	aniHit->Add(404);
	Animations::GetInstance()->Add(501, aniHit); //hitted 1

	LPANIMATION aniHit1 = new Animation(100);
	aniHit1->Add(405);
	aniHit1->Add(406);
	Animations::GetInstance()->Add(502, aniHit1); //hitted 2
#pragma endregion

#pragma region Sub Weapons
	//AXE
	LPANIMATION aniAxeRight = new Animation(100);
	aniAxeRight->Add(600);
	aniAxeRight->Add(601);
	aniAxeRight->Add(602);
	aniAxeRight->Add(603);
	Animations::GetInstance()->Add(600, aniAxeRight); // axe right

	LPANIMATION aniAxeLeft = new Animation(100);
	aniAxeLeft->Add(601);
	aniAxeLeft->Add(600);
	aniAxeLeft->Add(603);
	aniAxeLeft->Add(602);
	Animations::GetInstance()->Add(601, aniAxeLeft); // axe left



#pragma endregion
}