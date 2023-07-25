#include "Buttons.h"
#include "EventHandler.h"
#include "GameObject.h"


MenuButton::MenuButton(const ObjectParam* params, void (*callback)()): SDLGameObject(params)
{
    m_currentFrame = MOUSE_OUT; // start at frame 0
    m_callback = callback;
    m_Released = false;
}

void MenuButton::draw()
{
    SDLGameObject::draw(); // use the base class drawing
}

void MenuButton::update()
{
    vec2* mousePos = TheEventHandler::Instance()
        ->getMousePosition();

    if (mousePos->getX() < (m_position.getX() + m_size.getX())
        && mousePos->getX() > m_position.getX()
        && mousePos->getY() < (m_position.getY() + m_size.getY())
        && mousePos->getY() > m_position.getY())
    {
        m_currentFrame = MOUSE_OVER;

        if (TheEventHandler::Instance()->getMouseButtonState(LEFT) && m_Released)
        {
            m_currentFrame = CLICKED;

            m_callback();

            m_Released = false;
        }
        else {
            if (TheEventHandler::Instance()->getMouseButtonState(LEFT) && !m_Released) {
                m_Released = false;
            }
            else {
                m_Released = true;
            }
        }
    }
    else
    {
        m_currentFrame = MOUSE_OUT;
        if (TheEventHandler::Instance()->getMouseButtonState(LEFT) && !m_Released) {
            m_Released = false;
        }
        else {
            m_Released = true;
        }
    }
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}