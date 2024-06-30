//
// Created by manka on 17/04/2024.
//

#include <iostream>
#include <cmath>
#include "Sudoku.h"
#include "ErrorMessages.h"
#include "Constants.h"
#include <SDL.h>
#include <memory>
#include "MouseButton.h"

Sudoku::Sudoku()
{
    pPainter = std::make_unique<Painter>();
    if (!pPainter->isSuccessfullyInitialized)
    {
        return;
    }

    // pMainMenu = new MainMenu{pPainter->pRenderer, pPainter->pFontMain64};

    pMainMenu = std::make_shared<MainMenu>(pPainter->pRenderer, pPainter->pFontMain64);
    if (!pMainMenu->isSuccessfullyInitialized)
    {
        return;
    }

    pBoard = std::make_shared<Board>();

    pGame = std::make_shared<Game>(pPainter->pRenderer, pPainter->pFontMain64, pPainter->pFontBold100, pBoard);

    pLoading = std::make_shared<Loading>(pPainter->pRenderer, pPainter->pFontMain64, pBoard);

    mainLoop();
}

void Sudoku::mainLoop()
{
    while (true)
    {
        Uint64 start = SDL_GetPerformanceCounter();
        SDL_Event event{};
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }
            switch (currentView)
            {
            case ViewType::MAIN_MENU:
                {
                    currentView = pMainMenu->runEvent(event);
                    if (currentView == ViewType::LOADING)
                    {
                        pBoard->runBoardGeneration(pMainMenu->getSelectedDificultyLevel());
                        // pBoard-> generateBoard();
                    }
                    break;
                }
            case ViewType::GAME:
                {
                    currentView = pGame->runEvent(event);
                    break;
                }
            default:
                {
                    break;
                }
            }
        }
        switch (currentView)
        {
        case ViewType::MAIN_MENU:
            {
                pPainter->paint(pMainMenu.get());
                break;
            }
        case ViewType::LOADING:
            {
                currentView = pLoading->checkLoading();
                pPainter->paint(pLoading.get());
                break;
            }
        case ViewType::QUIT:
            {
                return;
            }
        case ViewType::GAME:
            {
                pPainter->paint(pGame.get());
                break;
            }
        case ViewType::GAME_ESCAPE:
            {
                return;
                break;
            }
        }

        Uint64 end = SDL_GetPerformanceCounter();

        float elapsed = static_cast<float>(end - start) / static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0f;
        if (elapsed < 16.666f)
        {
            SDL_Delay(floor(16.666f - elapsed));
        }
    }
}


int Sudoku::loadTextures()
{
    return 1;
}
