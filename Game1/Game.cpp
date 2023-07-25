#include <iostream>
#include "SDL3/SDL.h"
#include "SDL_image.h"
#include "EventHandler.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Caracters.h"
#include "Buttons.h"
#include "Game.h"
#include "GameState.h"
#include "States.h"


Game* Game::s_pInstance = 0;

Game::Game() {
    m_Running = false;
    m_window = 0;
    m_renderer = 0;
}

void Game::init(char* title, int screen_height, int screen_width) {

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

    m_stateMachine = new GameStateMachine();

    MenuState* menu = new MenuState();
    m_stateMachine->pushState(menu);
    m_currentState = MENU;
  
    std::cout << "Initialization Successful" << std::endl;
    std::cout << "-------------------------" << std::endl;
    m_Running = true;
}

void Game::render() {

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

    SDL_RenderClear(m_renderer);

    m_stateMachine->render();

    SDL_RenderPresent(m_renderer);
}

void Game::update() {
    
    int m = ((SDL_GetTicks() / 100) % 6);

    m_stateMachine->update();
}

void Game::event_handler() {
    
    TheEventHandler::Instance()->update();
}

void Game::quit() {
    Game::clean();
    m_Running = false;
}

void Game::clean() {
    std::cout << "cleaning the Game Objects ... \n";
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}
