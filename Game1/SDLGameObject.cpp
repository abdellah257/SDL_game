#include "GameObject.h"
#include "SDL3/SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

SDLGameObject::SDLGameObject(const ObjectParam* param): GameObject(param) {

	m_x = param->getX();
	m_y = param->getY();
	m_width = param->getW();
	m_height = param->getH();
	m_textureID = param->getID();

	m_currentRow = 0;
	m_currentFrame = 0;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
		m_width, m_height, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void SDLGameObject::clean() {

}

void SDLGameObject::update() {

}

