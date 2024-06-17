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
    std::weak_ptr<MainMenu> pMainMenu;

    std::shared_ptr<Game> pGame;

    std::shared_ptr<Loading> pLoading;

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFontMain64;
    std::shared_ptr<TTF_Font> pFontMain100;
    std::shared_ptr<TTF_Font> pFontBold100;

    Painter();

    ~Painter();

    bool isSuccessfullyInitialized{true};

    void paintMainMenu();

    void paintGame();

    void paintLoading();

    void setMainMenu(std::shared_ptr<MainMenu>& pMainMenu);

    void setGame(std::shared_ptr<Game>& pGame);

    void setLoading(std::shared_ptr<Loading>& pLoading);

};


#endif //SUDOKU_GAME_WITH_SDL2_PAINTER_H
