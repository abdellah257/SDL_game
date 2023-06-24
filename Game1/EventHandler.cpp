#include "EventHandler.h"
#include "Game.h"
#include "SDL3/SDL.h"

EventHandler* EventHandler::s_pInstance = 0;


bool EventHandler::getMouseButtonState(int button_index)
{   
    return m_mouseButtonsState[button_index];
}

vec2* EventHandler::getMousePosition()
{
    return m_mousePosition;
}

bool EventHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keyboardState != 0)
    {
        if (m_keyboardState[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

void EventHandler::update()
{
    m_keyboardState = (Uint8*)SDL_GetKeyboardState(0);
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            TheGame::Instance()->quit();
        }
        if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonsState[LEFT] = true;
            }

            if (event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonsState[MIDDLE] = true;
            }

            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonsState[RIGHT] = true;
            }
        }

        if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                m_mouseButtonsState[LEFT] = false;
            }

            if (event.button.button == SDL_BUTTON_MIDDLE)
            {
                m_mouseButtonsState[MIDDLE] = false;
            }

            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                m_mouseButtonsState[RIGHT] = false;
            }
        }
        if (event.type == SDL_EVENT_MOUSE_MOTION)
        {
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
        }
    }

}

void EventHandler::clean() {

}