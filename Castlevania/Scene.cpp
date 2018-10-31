#include "Scene.h"





void Scene::Update(DWORD dt)
{
}

void Scene::LoadResource()
{
	this->texturesManager = Textures::GetInstance();

	this->spriteManager = Sprites::GetInstance();

	this->animationManager = Animations::GetInstance();
}

