
#ifndef __Game__
#define __Game__

#include <vector>
#include <SDL3/SDL.h>
#include "TextureManager.h"
#include "GameObject.h"

#pragma once
class Game
{
public:

	void init(char* title, int screen_height, int screen_width);

	void render();
	void update();
	void event_handler();
	void clean();

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


private:

	static Game* s_pInstance;

	Game();

	std::vector<GameObject*> m_gameObjects;

	bool m_Running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

};

typedef Game TheGame;

#endif

