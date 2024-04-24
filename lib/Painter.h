//
// Created by manka on 22/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_PAINTER_H
#define SUDOKU_GAME_WITH_SDL2_PAINTER_H

#include "SDL.h"

#include "Constants.h"
#include "MainMenu.h"

#include <iostream>


class Painter {
    MainMenu *pMainMenu;



    SDL_Window *pWindow{nullptr};
    SDL_Renderer *pRenderer{nullptr};

    TTF_Font* pFontMain64{nullptr};

    int createWindow();

    int createRenderer();

    bool loadFonts();

public:
    Painter();

    ~Painter();

    bool isSuccessfullyInitialized{true};

    void paintMainMenu();


};


#endif //SUDOKU_GAME_WITH_SDL2_PAINTER_H
