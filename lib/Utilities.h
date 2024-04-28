//
// Created by manka on 26/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_UTILITIES_H
#define SUDOKU_GAME_WITH_SDL2_UTILITIES_H

#include <SDL.h>
#include <string>

namespace Utilities {
    SDL_Texture* generateTextTexture(const std::string &text, const SDL_Color& color, TTF_Font* pFont, SDL_Renderer* pRenderer);

    bool isContaining(const SDL_Rect& rect, const int &pointX, const int &pointY);
}


#endif //SUDOKU_GAME_WITH_SDL2_UTILITIES_H
