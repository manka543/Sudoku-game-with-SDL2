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

class Painter {

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> pWindow;

    int createWindow();

    int createRenderer();

    bool loadFonts();

public:
    std::weak_ptr<MainMenu> pMainMenu;

    std::shared_ptr<Game> pGame;

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFontMain64;
    std::shared_ptr<TTF_Font> pFontMain100;

    Painter();

    ~Painter();

    bool isSuccessfullyInitialized{true};

    void paintMainMenu();

    void paintGame();

    void setMainMenu(std::shared_ptr<MainMenu>& pMainMenu);

    void setGame(std::shared_ptr<Game>& pGame);

};


#endif //SUDOKU_GAME_WITH_SDL2_PAINTER_H
