#include "GameObject.h"
#include "lib.h"
#include <string>

#pragma once
enum button_state
{
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	CLICKED = 2
};

class MenuButton : public SDLGameObject {

	void (*m_callback)();
	bool m_Released;

public:

	MenuButton(const ObjectParam* param, void (*callback)());

	void draw();
	void update();
	void clean();
};


