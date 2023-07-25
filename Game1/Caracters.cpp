#include "Caracters.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Game.h"
#include "EventHandler.h"
#include <iostream>


Player::Player(const ObjectParam* param) : SDLGameObject(param) {

}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    //std::cout << "update player";
    int m = (SDL_GetTicks() / 100) % 6;
    if (m >= 4) {
        m_currentRow = 1;
        m_currentFrame = m - 4;
    }
    else {
        m_currentRow = 0;
        m_currentFrame = m;
    }
    
    /*if (TheEventHandler::Instance()->getMouseButtonState(LEFT)) {
        m_position.setX(m_position.getX() - 10);
    }*/
    if (TheEventHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_position.setX(m_position.getX() + 2);
    }

    if (TheEventHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_position.setX(m_position.getX() - 2);
    }

    if (TheEventHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_position.setY(m_position.getY() - 2);
    }

    if (TheEventHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_position.setY(m_position.getY() + 2);
    }
}

void Player::clean()
{
    SDLGameObject::clean(); 
}

Enemy::Enemy(const ObjectParam* param) : SDLGameObject(param) {

}

void Enemy::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, m_position,
        m_size, m_currentRow, m_currentFrame, m_offset,
        TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
}


void Enemy::update()
{
    int m = (SDL_GetTicks() / 100) % 6;
    if (m >= 4) {
        m_currentRow = 1;
        m_currentFrame = m - 4;
    }
    else {
        m_currentRow = 0;
        m_currentFrame = m;
    }
    m_position.setX(m_position.getX()-1);
    
}
void Enemy::clean()
{
    
}