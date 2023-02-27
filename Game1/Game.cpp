#include <iostream>
#include "SDL3/SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Caracters.h"
#include "Game.h"


Game* Game::s_pInstance = 0;

Game::Game() {
    m_Running = false;
    m_window = 0;
    m_renderer = 0;
}

void Game::init(char* title, int screen_height, int screen_width) {

    m_gameObjects.push_back(new Player(new ObjectParam(0, 0, 128, 130, 0, 1, "1")));
    m_gameObjects.push_back(new Enemy(new ObjectParam(300, 100, 128, 130, 0, 1, "1")));
    m_gameObjects.push_back(new Enemy(new ObjectParam(300, 200, 128, 130, 0, 1, "1")));
    m_gameObjects.push_back(new Enemy(new ObjectParam(300, 300, 128, 130, 0, 1, "1")));

    int state = SDL_Init(SDL_INIT_EVERYTHING);
    if (state >= 0) {
        m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            screen_width, screen_height, SDL_WINDOW_RESIZABLE);
        if (m_window != 0) {
            m_renderer = SDL_CreateRenderer(m_window, NULL, 0);
        }
        else {
            std::cout << "Failed to create the Window !" << std::endl;
            m_Running = false;
        }
    }
    else {
        std::cout << "Failed to Initialize SDL ! " << std::endl;
        
        m_Running = false;
    }



    bool texloaded = TheTextureManager::Instance()->load("spritelib_gpl/platform/char9-bg.png", "1", m_renderer);

    
    if (!texloaded) {
        std::cout << "Texture Loading Failed !\n";
        std::cout << "------------------------\n";
    }
    else {
        std::cout << "Texture Loaded Successfully\n";
        std::cout << "---------------------------\n";
    }

    
  
    std::cout << "Initialization Successful" << std::endl;
    std::cout << "-------------------------" << std::endl;
    m_Running = true;
}

void Game::render() {

    SDL_SetRenderDrawColor(m_renderer, 0, 100, 0, 255);

    SDL_RenderClear(m_renderer);

    for (auto e : m_gameObjects) {
        e->draw();
    }

    SDL_RenderPresent(m_renderer);
}

void Game::update() {
    
    int m = ((SDL_GetTicks() / 100) % 6);
    for (auto e : m_gameObjects) {
        e->update();
    }
    
}

void Game::event_handler() {
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            m_Running = false;
            break;

        default:
            break;
        }
    }
}

void Game::clean() {
    std::cout << "cleaning the Game Objects ... \n";
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

void update_char9() {
    
}