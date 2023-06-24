#include "SDL3/SDL.h"
#include "lib.h"
#include <iostream>
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

#pragma once
class EventHandler
{
public:

	static EventHandler* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new EventHandler();
			return s_pInstance;
		}

		return s_pInstance;
	}

	bool getMouseButtonState(int button_index);
	vec2* getMousePosition();
	bool isKeyDown(SDL_Scancode key);

	void update();
	void clean();

private:

	static EventHandler* s_pInstance;
	std::vector<bool> m_mouseButtonsState;
	vec2* m_mousePosition;
	Uint8* m_keyboardState;

	EventHandler(){
		for (int i = 0; i < 3; i++) {
			m_mouseButtonsState.push_back(false);
		}
		m_mousePosition = new vec2();
		m_keyboardState = 0;
	}
	~EventHandler(){}
};

typedef EventHandler TheEventHandler;

