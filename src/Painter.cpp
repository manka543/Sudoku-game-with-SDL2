//
// Created by manka on 22/04/2024.
//

#include "Painter.h"
#include <iostream>
#include "ErrorMessages.h"


Painter::Painter() {

    if (TTF_Init() == -1) {
        std::cerr << ErrorMessages::TTF_INIT_ERROR << TTF_GetError() << std::endl;
        isSuccessfullyInitialized = false;
    } else if (!createWindow() || !createRenderer() || !loadFonts()) {
        isSuccessfullyInitialized = false;
    }

    if (isSuccessfullyInitialized) {
        pMainMenu = new MainMenu(pRenderer, pFontMain64);
        if (!pMainMenu->isSuccessfullyInitialized) {
            isSuccessfullyInitialized = false;
        }
    }

}

Painter::~Painter() {
    // free main menu
    delete pMainMenu;


    // Close font
    TTF_CloseFont(pFontMain64);
    pFontMain64 = nullptr;

    // destroy pRenderer
    SDL_DestroyRenderer(pRenderer);
    pRenderer = nullptr;

    // destroy pWindow
    SDL_DestroyWindow(pWindow);
    pWindow = nullptr;

    TTF_Quit();
}

int Painter::createWindow() {
    pWindow = SDL_CreateWindow(
            Constants::WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::WINDOW_WIDTH,
            Constants::WINDOW_HEIGHT, SDL_WINDOW_SHOWN
    );
    if (pWindow == nullptr) {
        std::cerr << ErrorMessages::WINDOW_INIT_ERROR << SDL_GetError() << std::endl;
        return 0;
    }
    return 1;
}

int Painter::createRenderer() {
    pRenderer = SDL_CreateRenderer(pWindow, 0, SDL_RENDERER_ACCELERATED);
    if (pRenderer == nullptr) {
        std::cerr << ErrorMessages::RENDERER_CREATE_ERROR << SDL_GetError() << std::endl;
        return 0;
    }
    return 1;
}

void Painter::paintMainMenu() {
    SDL_SetRenderDrawColor(pRenderer, Constants::BACKGROUND_COLOR.r, Constants::BACKGROUND_COLOR.g,
                           Constants::BACKGROUND_COLOR.b, Constants::BACKGROUND_COLOR.a);

    pMainMenu->paint();

    SDL_RenderPresent(pRenderer);
}

bool Painter::loadFonts() {
    pFontMain64 = TTF_OpenFont(Constants::FONT_MAIN_PATH, Constants::FONT_MAIN_SIZE_64);

    if (pFontMain64 == nullptr) {
        std::cerr << ErrorMessages::FONT_OPENING_ERROR << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}
