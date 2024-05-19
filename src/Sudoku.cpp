//
// Created by manka on 17/04/2024.
//

#include <iostream>
#include <cmath>
#include "Sudoku.h"
#include "ErrorMessages.h"
#include "Constants.h"
#include <SDL.h>
#include "MouseButton.h"

Sudoku::Sudoku() {
    pPainter = std::make_unique<Painter>();
    if (!pPainter->isSuccessfullyInitialized) {
        return;
    }

   // pMainMenu = new MainMenu{pPainter->pRenderer, pPainter->pFontMain64};

    pMainMenu = std::make_shared<MainMenu>(pPainter->pRenderer, pPainter->pFontMain64);
    if (!pMainMenu->isSuccessfullyInitialized) {
        return;
    }

    pPainter->setMainMenu(pMainMenu);

    pGame = std::make_shared<Game>(pPainter->pRenderer, pPainter->pFontMain64, pPainter->pFontBold100);

    pPainter->setGame(pGame);



    mainLoop();
}

void Sudoku::mainLoop() {
    while (true) {
        Uint64 start = SDL_GetPerformanceCounter();
        SDL_Event event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }
            switch(currentView)
            {
            case ViewType::MAIN_MENU:
                {
                    currentView = pMainMenu->runEvent(event);
                    break;
                }
            case ViewType::GAME:
                {
                    currentView = pGame->runEvent(event);
                    break;
                }

            }

        }
        switch (currentView) {
            case ViewType::MAIN_MENU: {
                pPainter->paintMainMenu();
                break;
            }
            case ViewType::QUIT: {
                return;
            }
            case ViewType::GAME: {
                pPainter->paintGame();
                break;
            }
            case ViewType::GAME_ESCAPE: {
                return;
                break;
            }
        }

        Uint64 end = SDL_GetPerformanceCounter();

        float elapsed = static_cast<float>(end - start) / static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0f;
        if (elapsed < 16.666f) {
            SDL_Delay(floor(16.666f - elapsed));
        }
    }
}



int Sudoku::loadTextures() {
    return 1;
}

