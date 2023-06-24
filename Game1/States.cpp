#include "States.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (auto e : m_menuObjects) {
		e->update();
	}
	return;
}

void MenuState::render() {
	for (auto e : m_menuObjects) {
		// TODO
	}
	return;
}

bool MenuState::onEnter() {
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit() {
	std::cout << "exiting MenuState\n";
	return true;
}


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (auto e : m_gameObjects) {
		e->update();
	}
	return;
}

void PlayState::render()
{
	for (auto e : m_gameObjects) {
		e->draw();
	}
	return;
}

bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}


void GameStateMachine::pushState(GameState* pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}

		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	// push back our new state
	m_gameStates.push_back(pState);

	// initialise it
	m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
	return;
}

void GameStateMachine::render() 
{
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
	return;
}