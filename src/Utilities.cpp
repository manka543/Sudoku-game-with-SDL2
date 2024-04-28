//
// Created by manka on 26/04/2024.
//

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Utilities.h"
#include "ErrorMessages.h"


SDL_Texture* Utilities::generateTextTexture(const std::string &text, const SDL_Color& color, TTF_Font* pFont, SDL_Renderer* pRenderer) {
    SDL_Surface* pTextSurface = TTF_RenderText_Blended(pFont, text.c_str(), color);
    if(pTextSurface == nullptr){
        std::cerr<<ErrorMessages::TEXT_RENDERING_ERROR<<TTF_GetError()<<std::endl;
        return nullptr;
    }

    SDL_Texture* pTextTexture = SDL_CreateTextureFromSurface(pRenderer,pTextSurface);
    SDL_FreeSurface(pTextSurface);

    if(pTextTexture == nullptr){
        std::cerr<<ErrorMessages::SURFACE_TO_TEXTURE_ERROR<<SDL_GetError()<<std::endl;
    }

    return pTextTexture;
}

bool Utilities::isContaining(const SDL_Rect &rect, const int &pointX, const int &pointY) {
    return (pointX >= rect.x && pointX <= rect.x + rect.w) && (pointY >= rect.y && pointY <= rect.y + rect.h);
}
