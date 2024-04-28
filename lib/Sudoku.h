//
// Created by manka on 17/04/2024.
//

#ifndef PROJECT_NAME_SUDOKU_H
#define PROJECT_NAME_SUDOKU_H

#include <SDL.h>
#include "Painter.h"

class Sudoku {
    bool quit{false};

    Painter* pPainter{nullptr};

    int loadTextures();

public:
    Sudoku();

    ~Sudoku();

    void mainLoop();
};


#endif //PROJECT_NAME_SUDOKU_H
