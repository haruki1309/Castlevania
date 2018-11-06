#include "GameObject.h"

GameObject::GameObject()
{
	position.x = position.y = 0;
	vx = vy = 0;
	nx = 1;
}
GameObject::~GameObject()
{

}
void GameObject::Update(DWORD dt)
{
	this->dt = dt;
}

void GameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = Animations::GetInstance()->GetAnimation(aniId);
	animations.push_back(ani);
}

