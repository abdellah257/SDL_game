#include "Caracters.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Game.h"
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
    m_x += 1;
}

void Player::clean()
{
    SDLGameObject::clean(); 
}

Enemy::Enemy(const ObjectParam* param) : SDLGameObject(param) {

}

void Enemy::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
        m_width, m_height, m_currentRow, m_currentFrame,
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
    m_x -= 1;
    
}
void Enemy::clean()
{
    
}