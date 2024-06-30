//
// Created by manka on 22/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_PAINTER_H
#define SUDOKU_GAME_WITH_SDL2_PAINTER_H

#include <SDL.h>

#include "Constants.h"
#include "MainMenu.h"

#include <iostream>
#include "Game.h"
#include <memory>

#include "Loading.h"

class Painter {

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> pWindow;

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pTitleText;

    int createWindow();

    int createRenderer();

    bool loadFonts();

    bool loadTextures();

public:

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFontMain64;
    std::shared_ptr<TTF_Font> pFontMain100;
    std::shared_ptr<TTF_Font> pFontBold100;

    Painter();

    ~Painter();

    bool isSuccessfullyInitialized{true};

    void paint(Paintable* paintable);

};


#endif //SUDOKU_GAME_WITH_SDL2_PAINTER_H
