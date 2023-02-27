#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <string>

#pragma once

class ObjectParam
{
public:
	ObjectParam(int x, int y, int width, int height, int frame, int row, std::string id) {
		m_x = x; m_y = y;
		m_width = width; m_height = height;
		m_currentFrame = frame; m_currentRow = row;
		m_textureID = id;
	}
	~ObjectParam() {}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getW() const { return m_width; }
	int getH() const { return m_height; }

	std::string getID() const { return m_textureID; }

private:

	int m_x;
	int m_y;

	std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_width;
	int m_height;
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

	int m_x, m_y;
	int m_width, m_height;
	int m_currentFrame, m_currentRow;

	std::string m_textureID;

};

#endif

