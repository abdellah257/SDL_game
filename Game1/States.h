#include <vector>
#include "GameState.h"
#include "GameObject.h"

#pragma once

class MenuState : public GameState
{
public:

	MenuState() {
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:

	static const std::string s_menuID;
	std::vector<GameObject*> m_menuObjects;

	static void s_menuToPlay();
	static void s_exitFromMenu();
};

class PauseState : public GameState
{
public:

	PauseState() {
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

private:

	static const std::string s_pauseID;
	std::vector<GameObject*> m_menuObjects;

	static void s_pauseToMenu();
	static void s_pauseToPlay();
};


class PlayState : public GameState
{
public:

	PlayState() {
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	bool checkCollision(SDLGameObject* g1, SDLGameObject* g2);

	virtual std::string getStateID() const { return s_playID; }

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	
};

class OverState : public GameState
{
public:

	OverState() {
	};

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_overID; }

private:

	static const std::string s_overID;
	std::vector<GameObject*> m_gameObjects;

	static void s_overToMenu();
	static void s_overToPlay();

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