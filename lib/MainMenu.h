//
// Created by manka on 24/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_MAINMENU_H
#define SUDOKU_GAME_WITH_SDL2_MAINMENU_H

#include "SDL_ttf.h"

class MainMenu {
    bool loadTexts();

    bool createTitleTextTexture();

    SDL_Texture* pTitleText = nullptr;

    TTF_Font* gFont = nullptr;

    SDL_Renderer* pRenderer = nullptr;


public:
    MainMenu(SDL_Renderer* pRenderer, TTF_Font* pFontMain64);

    ~MainMenu();

    bool isSuccessfullyInitialized{true};

    void paint();


};


#endif //SUDOKU_GAME_WITH_SDL2_MAINMENU_H
