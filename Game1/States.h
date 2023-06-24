#include <vector>
#include "GameState.h"
#include "GameObject.h"

#pragma once

class MenuState : public GameState
{
public:

	MenuState(std::vector<GameObject*> m_menuObjects) {
		this->m_menuObjects = m_menuObjects;
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:

	static const std::string s_menuID;
	std::vector<GameObject*> m_menuObjects;
};


class PlayState : public GameState
{
public:

	PlayState(std::vector<GameObject*> m_menuObjects) {
		this->m_gameObjects = m_menuObjects;
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	
};

class GameStateMachine
{
public:

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();

private:

	std::vector<GameState*> m_gameStates;
};