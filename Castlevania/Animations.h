#pragma once
#include "Sprites.h"
#include <unordered_map>

using namespace std;


//Struture of Animation Frame
class AnimationFrame
{
	LPSPRITE sprite;
	DWORD time;

public:
	AnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
};

typedef AnimationFrame *LPANIMATION_FRAME;

//Struture of Animation
class Animation
{
	DWORD lastFrameTime;
	int defaultTime;
	int currentFrame;
	vector<LPANIMATION_FRAME> frames;
public:
	Animation(int defaultTime) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; }
	void Add(int spriteId, DWORD time = 0);
	void Render(float x, float y);
};

typedef Animation *LPANIMATION;

//Animation Manager
class Animations
{
	static Animations * instance;

	unordered_map<int, LPANIMATION> animationsList;

public:
	void Add(int id, LPANIMATION ani);
	LPANIMATION Get(int id);

	static Animations * GetInstance();
};
