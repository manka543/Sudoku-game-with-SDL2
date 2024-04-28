//
// Created by manka on 17/04/2024.
//

#include <iostream>
#include "Sudoku.h"
#include "ErrorMessages.h"
#include "Constants.h"
#include <SDL.h>

Sudoku::Sudoku() {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cerr<<ErrorMessages::SDL_INIT_ERROR << SDL_GetError() << std::endl;
    }
    pPainter = new Painter();

//    else if( || !loadTextures()) {
//        return;
//    }

    mainLoop();

}

void Sudoku::mainLoop() {
    while(!quit){
        Uint64 start = SDL_GetPerformanceCounter();
        SDL_Event event{};
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            } else if (event.type == SDL_MOUSEMOTION){
                pPainter->pMainMenu->setMousePosition(event.motion.x, event.motion.y);
            }
        }

        pPainter->paintMainMenu();

        Uint64 end = SDL_GetPerformanceCounter();

        float elapsed = (float)(end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        if (elapsed < 16.666f) {
            SDL_Delay(floor(16.666f - elapsed));
        }
    }
}

Sudoku::~Sudoku() {
    delete pPainter;
    pPainter = nullptr;

    // quit SDL2
    SDL_Quit();
}


int Sudoku::loadTextures() {
    return 1;
}

