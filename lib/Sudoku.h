//
// Created by manka on 17/04/2024.
//

#ifndef PROJECT_NAME_SUDOKU_H
#define PROJECT_NAME_SUDOKU_H

#include <SDL.h>
#include "Painter.h"
#include "ViewType.h"


class Sudoku {
    MainMenu* pMainMenu;

    Painter* pPainter{nullptr};

    ViewType currentView = ViewType::MAIN_MENU;

    int loadTextures();

public:
    Sudoku();

    ~Sudoku();

    void mainLoop();
};


#endif //PROJECT_NAME_SUDOKU_H
