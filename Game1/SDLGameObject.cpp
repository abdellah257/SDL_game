#include "GameObject.h"
#include "SDL3/SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>

SDLGameObject::SDLGameObject(const ObjectParam* param): GameObject(param) {

	m_position = param->getPos();
	m_size = param->getSize();
	m_textureID = param->getID();

	m_currentRow = 0;
	m_currentFrame = 0;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_position,
		m_size, m_currentRow, m_currentFrame,
		TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void SDLGameObject::clean() {

}

void SDLGameObject::update() {

}

