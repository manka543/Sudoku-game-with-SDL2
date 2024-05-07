//
// Created by manka on 26/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_UTILITIES_H
#define SUDOKU_GAME_WITH_SDL2_UTILITIES_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <memory>

namespace Utilities {
    SDL_Texture* generateTextTexture(const std::string &text, const SDL_Color& color, std::shared_ptr<TTF_Font> pFont, std::shared_ptr<SDL_Renderer>& pRenderer);

    bool isContaining(const SDL_Rect& rect, const int &pointX, const int &pointY);

    bool initLibraries();

    void runGame();

    void quitLibraries();
}


#endif //SUDOKU_GAME_WITH_SDL2_UTILITIES_H
