//
// Created by manka543 on 6/15/24.
//

#include "../lib/Loading.h"

#include <Utilities.h>

#include "Board.h"

bool Loading::loadTexts()
{
    pLoadingText = Utilities::generateTextTexture(Constants::LOADING_TEXT,
                                                      Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                      pFont, pRenderer);
    if (pLoadingText == nullptr)
    {
        return false;
    }
    pLoadingIndicator = Utilities::generateTextTexture(Constants::LOADING_INDICATOR_SIGN,
                                                      Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                      pFont, pRenderer);
    if (pLoadingIndicator == nullptr)
    {
        return false;
    }
    return true;
}

Loading::Loading(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFont, std::shared_ptr<Board> pBoard): pRenderer(pRenderer), pFont(pFont), pLoadingText(nullptr, &SDL_DestroyTexture), pLoadingIndicator(nullptr, &SDL_DestroyTexture), pBoard(pBoard)
{
}

ViewType Loading::checkLoading()
{
    if(pBoard->hasBoardGenerationEnded())
    {
        return ViewType::GAME;
    }
    if(lastChange + std::chrono::milliseconds(500) < std::chrono::high_resolution_clock::now())
    {
        lastChange = std::chrono::high_resolution_clock::now();
        indicatorStatus++;
        if(indicatorStatus == 4)
        {
            indicatorStatus = 1;
        }
        {
        }
    }
    return ViewType::LOADING;
}

void Loading::paint()
{
    SDL_RenderCopy(pRenderer.get(), pLoadingText.get(), nullptr, &Constants::LOADING_TEXT_POSITION);

    SDL_Rect indicatorPosition = Constants::FIRST_LOADING_INDICATOR_SIGN_POSITION;
    for(int i = 0; i <indicatorStatus; i++)
    {
        SDL_RenderCopy(pRenderer.get(), pLoadingIndicator.get(), nullptr, &indicatorPosition);
        indicatorPosition.x+=30;
    }

}

