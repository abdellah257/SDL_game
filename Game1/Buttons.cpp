#include "Buttons.h"
#include "EventHandler.h"
#include "GameObject.h"


MenuButton::MenuButton(const ObjectParam* params) : SDLGameObject(params)
{
    m_currentRow = MOUSE_OUT; // start at frame 0
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
        m_currentRow = MOUSE_OVER;

        if (TheEventHandler::Instance()->getMouseButtonState(LEFT))
        {
            m_currentRow = CLICKED;
        }
    }
    else
    {
        m_currentRow = MOUSE_OUT;
    }
}

void MenuButton::clean()
{
    SDLGameObject::clean();
}