#pragma once
#ifndef __CARACTERS__
#define __CARACTERS__

#include "GameObject.h"

class Player : public SDLGameObject
{
public:

	Player(const ObjectParam* param);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

class Enemy : public SDLGameObject
{
public:

	Enemy(const ObjectParam* param);
	void draw();
	void update();
	void clean();
};

#endif