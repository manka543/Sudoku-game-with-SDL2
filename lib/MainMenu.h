//
// Created by manka on 24/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_MAINMENU_H
#define SUDOKU_GAME_WITH_SDL2_MAINMENU_H

#include <SDL_ttf.h>

class MainMenu {

    enum class MenuOption : int {
        NONE = 0,
        PLAY,
        QUIT
    };

    bool loadTexts();

    SDL_Texture* pTitleText = nullptr;
    SDL_Texture* pPlayTextDefault = nullptr;
    SDL_Texture* pPlayTextSelected = nullptr;
    SDL_Texture* pQuitTextDefault = nullptr;
    SDL_Texture* pQuitTextSelected = nullptr;
    SDL_Texture* pPointerText = nullptr;

    TTF_Font* pFont = nullptr;

    MenuOption selectedOption = MenuOption::NONE;

    SDL_Renderer* pRenderer = nullptr;


public:



    MainMenu(SDL_Renderer* pRenderer, TTF_Font* pFontMain64);

    ~MainMenu();

    bool isSuccessfullyInitialized{true};

    void paint();

    void setMousePosition(const int &xPos, const int &yPos);


};


#endif //SUDOKU_GAME_WITH_SDL2_MAINMENU_H
