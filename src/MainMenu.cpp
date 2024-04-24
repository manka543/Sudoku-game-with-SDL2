//
// Created by manka on 24/04/2024.
//


#include "MainMenu.h"
#include "Constants.h"
#include "ErrorMessages.h"

#include <iostream>

bool MainMenu::loadTexts() {

    if(!createTitleTextTexture()){
        return false;
    }

    return true;
}

bool MainMenu::createTitleTextTexture() {
    SDL_Surface* pTitleTextSurface = TTF_RenderText_Blended( gFont, Constants::MAIN_MENU_TITLE_TEXT, Constants::MAIN_MENU_TITLE_TEXT_COLOR);
    if(pTitleTextSurface == nullptr){
        std::cerr<<ErrorMessages::TEXT_RENDERING_ERROR<<TTF_GetError()<<std::endl;
        return false;
    }

    pTitleText = SDL_CreateTextureFromSurface(pRenderer,pTitleTextSurface);
    SDL_FreeSurface(pTitleTextSurface);

    if(pTitleText == nullptr){
        std::cerr<<ErrorMessages::SURFACE_TO_TEXTURE_ERROR<<SDL_GetError()<<std::endl;
        return false;
    }

    return true;
}

MainMenu::MainMenu(SDL_Renderer *pRenderer, TTF_Font* pFontMain64) : pRenderer(pRenderer), gFont(pFontMain64) {
    loadTexts();
}

MainMenu::~MainMenu() {
    //free title text texture
    SDL_DestroyTexture(pTitleText);
    pTitleText = nullptr;

}

void MainMenu::paint() {
    SDL_RenderCopy(pRenderer, pTitleText,  nullptr, &Constants::MAIN_MENU_TITLE_POSITION);
}
