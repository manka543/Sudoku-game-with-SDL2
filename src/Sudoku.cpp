//
// Created by manka on 17/04/2024.
//

#include <iostream>
#include "../lib/Sudoku.h"
#include "../lib/ErrorMessages.h"
#include "../lib/Constants.h"
#include "SDL.h"

Sudoku::Sudoku() {
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr<<ErrorMessages::SDL_INIT_ERROR;
    } else if(!createWindow()) {
        return;
    } else if(!createRenderer()){
        return;
    } else if(!loadTextures()){

    }

}

void Sudoku::mainLoop() {

}

Sudoku::~Sudoku() {
    // destroy renderer
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;

    // destroy window
    SDL_DestroyWindow(window);
    window = nullptr;

    // quit SDL2
    SDL_Quit();
}

int Sudoku::createWindow() {
    window = SDL_CreateWindow(
         "Sudoku", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, SDL_WINDOW_SHOWN
         );
    if (window == nullptr){
        std::cerr<<ErrorMessages::WINDOW_INIT_ERROR;
        return 0;
    }
    return 1;
}

int Sudoku::createRenderer() {
    return 0;
}

int Sudoku::loadTextures() {
    return 0;
}

