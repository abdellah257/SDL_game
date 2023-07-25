#include "States.h"
#include "Game.h"
#include "Buttons.h"
#include "Caracters.h"
#include "EventHandler.h"
#include "TextureManager.h"

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
		e->draw();
	}
	return;
}

bool MenuState::onEnter() {

	bool texloaded2 = TheTextureManager::Instance()->load("spritelib_gpl/exit11.png", "exit", TheGame::Instance()->getRenderer());
	bool texloaded3 = TheTextureManager::Instance()->load("spritelib_gpl/play11.png", "play", TheGame::Instance()->getRenderer());

	if (!texloaded2 || !texloaded3) {
		std::cout << "Textures Loading Failed\n";
		std::cout << "---------------------------\n";
		return false;
	}

	m_menuObjects.push_back(new MenuButton(new ObjectParam(200, 300, 233, 68, 0, 0, 0, "exit"), s_exitFromMenu));
	m_menuObjects.push_back(new MenuButton(new ObjectParam(200, 150, 233, 68, 0, 0, 0, "play"), s_menuToPlay));

	std::cout << "Entering MenuState\n";

	return true; 
}

bool MenuState::onExit() {
	
	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->clean();
	}
	m_menuObjects.clear();

	/*
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	*/

	std::cout << "Exiting MenuState\n";
	std::cout << "-----------------\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}




const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update() {
	for (auto e : m_menuObjects) {
		e->update();
	}
	return;
}

void PauseState::render() {
	for (auto e : m_menuObjects) {
		e->draw();
	}
	return;
}

bool PauseState::onEnter() {
	std::cout << "entering PauseState\n";

	bool texloaded2 = TheTextureManager::Instance()->load("spritelib_gpl/menu11.png", "main", TheGame::Instance()->getRenderer());
	bool texloaded3 = TheTextureManager::Instance()->load("spritelib_gpl/resume11.png", "resume", TheGame::Instance()->getRenderer());

	if (!texloaded2 || !texloaded3) {
		std::cout << "Textures Loading Failed\n";
		std::cout << "---------------------------\n";
		return false;
	}

	m_menuObjects.push_back(new MenuButton(new ObjectParam(200, 300, 233, 68, 0, 0, 0, "main"), s_pauseToMenu));
	m_menuObjects.push_back(new MenuButton(new ObjectParam(200, 150, 233, 68, 0, 0, 0, "resume"), s_pauseToPlay));


	return true;
}

bool PauseState::onExit() {

	for (int i = 0; i < m_menuObjects.size(); i++)
	{
		m_menuObjects[i]->clean();
	}
	m_menuObjects.clear();

	/*
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	*/

	std::cout << "exiting PauseState\n";
	std::cout << "------------------\n";
	return true;
}

void PauseState::s_pauseToPlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::s_pauseToMenu()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}


const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheEventHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	m_gameObjects[0]->update();

	for (int i = 1; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();

		if (checkCollision(dynamic_cast<SDLGameObject*>
			(m_gameObjects[0]), dynamic_cast<SDLGameObject*>
			(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->pushState(new
				OverState());
		}
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

	bool texloaded1 = TheTextureManager::Instance()->load("spritelib_gpl/platform/char9-bg.png", "1", TheGame::Instance()->getRenderer());

	if (!texloaded1) {
		std::cout << "Textures Loading Failed !\n";
		std::cout << "------------------------\n";
		return false;
	}

	m_gameObjects.push_back(new Player(new ObjectParam(0, 0, 128, 130, 0, 0, 0, "1")));
	m_gameObjects.push_back(new Enemy(new ObjectParam(300, 100, 128, 130, 0, 0, 0, "1")));
	m_gameObjects.push_back(new Enemy(new ObjectParam(300, 200, 128, 130, 0, 0, 0, "1")));
	m_gameObjects.push_back(new Enemy(new ObjectParam(300, 300, 128, 130, 0, 0, 0, "1")));


	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	std::cout << "exiting PlayState\n";
	std::cout << "-----------------\n";
	return true;
}


bool PlayState::checkCollision( SDLGameObject* g1, SDLGameObject* g2) {

	int left1 = g1->getPosition().getX();
	int right1 = left1 + g1->getSize().getX();
	int top1 = g1->getPosition().getY();
	int bottom1 = top1 + g1->getSize().getY();

	int left2 = g2->getPosition().getX();
	int right2 = left2 + g2->getSize().getX();
	int top2 = g2->getPosition().getY();
	int bottom2 = top2 + g2->getSize().getY();

	if (bottom1 <= top2 || top1 >= bottom2 || left1 >= right2 || right1 <= left2) {
		return false;
	}

	return true;
}

const std::string OverState::s_overID = "OVER";

void OverState::update() {
	for (auto e : m_gameObjects) {
		e->update();
	}
	return;
}

void OverState::render() {
	for (auto e : m_gameObjects) {
		e->draw();
	}
	return;
}

bool OverState::onEnter() {

	bool texloaded2 = TheTextureManager::Instance()->load("spritelib_gpl/exit11.png", "exit", TheGame::Instance()->getRenderer());
	bool texloaded3 = TheTextureManager::Instance()->load("spritelib_gpl/play11.png", "play", TheGame::Instance()->getRenderer());

	if (!texloaded2 || !texloaded3) {
		std::cout << "Textures Loading Failed\n";
		std::cout << "---------------------------\n";
		return false;
	}

	m_gameObjects.push_back(new MenuButton(new ObjectParam(200, 300, 233, 68, 0, 0, 0, "exit"), s_overToMenu));
	m_gameObjects.push_back(new MenuButton(new ObjectParam(200, 150, 233, 68, 0, 0, 0, "play"), s_overToPlay));

	std::cout << "Entering OverState\n";

	return true;
}

bool OverState::onExit() {

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	/*
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	*/

	std::cout << "Exiting OverState\n";
	std::cout << "-----------------\n";
	return true;
}

void OverState::s_overToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void OverState::s_overToMenu()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
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