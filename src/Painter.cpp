//
// Created by manka on 22/04/2024.
//

#include "Painter.h"
#include <iostream>
#include "ErrorMessages.h"


Painter::Painter():pWindow(nullptr, SDL_DestroyWindow) {

    if (!createWindow() || !createRenderer() || !loadFonts()) {
        isSuccessfullyInitialized = false;
    }

}

Painter::~Painter() {

//    // Close font
//    TTF_CloseFont(pFontMain64);
//    pFontMain64 = nullptr;

//    // destroy pRenderer
//    SDL_DestroyRenderer(pRenderer);
//    pRenderer = nullptr;


}

int Painter::createWindow() {

    pWindow.reset(SDL_CreateWindow(
            Constants::WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::WINDOW_WIDTH,
            Constants::WINDOW_HEIGHT, SDL_WINDOW_SHOWN
    ));

    if (pWindow == nullptr) {
        std::cerr << ErrorMessages::WINDOW_INIT_ERROR << SDL_GetError() << std::endl;
        return 0;
    }
    return 1;
}

int Painter::createRenderer() {
    pRenderer.reset((SDL_CreateRenderer(pWindow.get(), -1, SDL_RENDERER_ACCELERATED)), &SDL_DestroyRenderer);
    if (pRenderer == nullptr) {
        std::cerr << ErrorMessages::RENDERER_CREATE_ERROR << SDL_GetError() << std::endl;
        return 0;
    }
    return 1;
}

void Painter::paintMainMenu() {
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::BACKGROUND_COLOR.r, Constants::BACKGROUND_COLOR.g,
                           Constants::BACKGROUND_COLOR.b, Constants::BACKGROUND_COLOR.a);

    SDL_RenderClear(pRenderer.get());

    auto pMainMenuCP = pMainMenu.lock();
    pMainMenuCP->paint();

    SDL_RenderPresent(pRenderer.get());
}



void Painter::setMainMenu(std::shared_ptr<MainMenu>& pMainMenu) {
    this->pMainMenu = pMainMenu;
}

bool Painter::loadFonts() {

    pFontMain64 = std::shared_ptr<TTF_Font>(TTF_OpenFont(Constants::FONT_MAIN_PATH, Constants::FONT_MAIN_SIZE_64), &TTF_CloseFont);
    if (pFontMain64 == nullptr) {
        std::cerr << ErrorMessages::FONT_OPENING_ERROR << TTF_GetError() << std::endl;
        return false;
    }

    pFontMain100 = std::shared_ptr<TTF_Font>(TTF_OpenFont(Constants::FONT_MAIN_PATH, Constants::FONT_SIZE_100), &TTF_CloseFont);
    if (pFontMain100 == nullptr) {
        std::cerr << ErrorMessages::FONT_OPENING_ERROR << TTF_GetError() << std::endl;
        return false;
    }

    pFontBold100 = std::shared_ptr<TTF_Font>(TTF_OpenFont(Constants::FONT_BOLD_PATH, Constants::FONT_SIZE_100), &TTF_CloseFont);
    if(pFontBold100 == nullptr)
    {
        std::cerr << ErrorMessages::FONT_OPENING_ERROR << TTF_GetError() << std::endl;
    }
    return true;
}

void Painter::setGame(std::shared_ptr<Game> &pGame) {
    this->pGame = pGame;
}

void Painter::paintGame() {
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::BACKGROUND_COLOR.r, Constants::BACKGROUND_COLOR.g,
                           Constants::BACKGROUND_COLOR.b, Constants::BACKGROUND_COLOR.a);

    SDL_RenderClear(pRenderer.get());

    pGame->paint();

    SDL_RenderPresent(pRenderer.get());
}


