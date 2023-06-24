#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <string>
#include "lib.h"

#pragma once

class ObjectParam
{
public:
	ObjectParam(int x, int y, int width, int height, int frame, int row, std::string id) {
		m_position = vec2(x, y);
		m_size = vec2(width, height);
		m_currentFrame = frame; m_currentRow = row;
		m_textureID = id;
	}
	~ObjectParam() {}

	vec2 getPos() const { return m_position; }
	vec2 getSize() const { return m_size; }

	std::string getID() const { return m_textureID; }

private:

	vec2 m_position;

	vec2 m_size;

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

};

class GameObject
{
public:

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void clean() = 0;

protected:

	GameObject(const ObjectParam* param) {}
	virtual ~GameObject() {}

};

class SDLGameObject : public GameObject
{
public:

	SDLGameObject(const ObjectParam* param);

	virtual void update();
	virtual void draw();
	virtual void clean();

protected:

	vec2 m_position;
	vec2 m_size;
	int m_currentFrame, m_currentRow;

	std::string m_textureID;

};

#endif

