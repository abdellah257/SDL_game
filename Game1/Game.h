
#ifndef __Game__
#define __Game__

#include <vector>
#include <SDL3/SDL.h>
#include "GameObject.h"
#include "States.h"
#include "GameState.h"

enum game_states
{
	MENU = 0,
	PLAY = 1,
	PAUSE = 2,
	GAMEOVER = 3
};

#pragma once
class Game
{
public:

	void init(char* title, int screen_height, int screen_width);

	void render();
	void update();
	void event_handler();
	void clean();
	void quit();

	bool is_Running() const {
		return m_Running;
	}

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_renderer; }
	SDL_Window* getWindow() const { return m_window; }

	GameStateMachine* getStateMachine() { return m_stateMachine; }


private:

	static Game* s_pInstance;

	Game();
	
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	GameStateMachine* m_stateMachine;

	bool m_Running;
	game_states m_currentState;
};

typedef Game TheGame;

#endif

