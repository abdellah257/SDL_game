#include "TextureManager.h"
#include "SDL3/SDL.h"
#include "SDL_image.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer) {

    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());

    if (tempSurface == 0)
    {
        return false;
    }

    SDL_Texture* texture =
        SDL_CreateTextureFromSurface(renderer, tempSurface);

    SDL_DestroySurface(tempSurface);

    // everything went ok, add the texture to our list
    if (texture != 0)
    {
        m_textureMap[id] = texture;
        return true;
    }

    // reaching here means something went wrong
    return false;

}

void TextureManager::draw(std::string id, vec2 pos, vec2 size, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_FRect destRect;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = size.getX();
    srcRect.h = destRect.h = size.getY();
    destRect.x = pos.getX();
    destRect.y = pos.getY();

    SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect,
        &destRect, 0, 0, flip);

}

void TextureManager::drawFrame(std::string id, vec2 pos, vec2 size, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_FRect destRect;
    srcRect.x = size.getX() * currentFrame;
    srcRect.y = size.getY() * currentRow;
    srcRect.w = destRect.w = size.getX();
    srcRect.h = destRect.h = size.getY();
    destRect.x = pos.getX();
    destRect.y = pos.getY();

    SDL_RenderTextureRotated(pRenderer, m_textureMap[id], &srcRect,
        &destRect, 0, 0, flip);
}

