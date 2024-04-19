//
// Created by manka on 17/04/2024.
//

#ifndef PROJECT_NAME_SUDOKU_H
#define PROJECT_NAME_SUDOKU_H

#include "SDL.h"


class Sudoku {
    SDL_Window *window{nullptr};
    SDL_Renderer *renderer{nullptr};

    int createWindow();
    int createRenderer();
    int loadTextures();

public:
    Sudoku();

    ~Sudoku();

    void mainLoop();
};


#endif //PROJECT_NAME_SUDOKU_H
