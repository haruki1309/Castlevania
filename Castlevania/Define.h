#pragma once
#define SAFE_DELETE(p) {if(p) { delete(p); p = NULL;} } 

#define CLASS_NAME	"Castle Vania"
#define FULLSCREEN	false
#define GAME_TITLE	"Castle Vania"

#define GAME_WIDTH	640
#define GAME_HEIGHT	480
#define FRAME_RATE			30
#define FPS					60
#define MAX_TIME_PER_FRAME	1000 / FPS
