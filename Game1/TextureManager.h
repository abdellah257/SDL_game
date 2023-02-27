#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SDL3/SDL.h>
#include <string>
#include <map>

#pragma once
class TextureManager
{
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip);
	
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}

		return s_pInstance;
	}

private:

	std::map<std::string, SDL_Texture*> m_textureMap;

	static TextureManager* s_pInstance;

	TextureManager() {}
};

typedef TextureManager TheTextureManager;

#endif
