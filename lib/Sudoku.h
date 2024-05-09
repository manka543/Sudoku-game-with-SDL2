//
// Created by manka on 17/04/2024.
//

#ifndef PROJECT_NAME_SUDOKU_H
#define PROJECT_NAME_SUDOKU_H

#include <SDL.h>
#include "Painter.h"
#include "ViewType.h"
#include <memory>


class Sudoku {

    std::shared_ptr<MainMenu> pMainMenu;

    std::shared_ptr<Game> pGame;

    std::unique_ptr<Painter> pPainter;

    ViewType currentView = ViewType::MAIN_MENU;

    int loadTextures();

public:
    Sudoku();

    ~Sudoku();

    void mainLoop();
};


#endif //PROJECT_NAME_SUDOKU_H
