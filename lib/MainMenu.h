//
// Created by manka on 24/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_MAINMENU_H
#define SUDOKU_GAME_WITH_SDL2_MAINMENU_H

#include <SDL_ttf.h>
#include <MouseButton.h>
#include <ViewType.h>
#include <memory>
#include <Board.h>
#include "Paintable.h"

class MainMenu : public Paintable {

    enum class MenuOption : int {
        NONE = 0,
        PLAY,
        QUIT,
        EASY,
        MEDIUM,
        HARD
    };
    enum class MenuState : int {
        MAIN_SCREEN,
        DIFFICULTY_LEVEL_SELECTION,
        PAUSE_MENU
    };

    bool loadTexts();

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPlayTextDefault{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPlayTextSelected{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pQuitTextDefault{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pQuitTextSelected{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPointerText{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pEasyLevelText{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pMediumLevelText{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pHardLevelText{nullptr, &SDL_DestroyTexture};


//    std::shared_ptr<TTF_Font> pFont;

    MenuOption selectedOption = MenuOption::NONE;

//    std::shared_ptr<SDL_Renderer> pRenderer;

    MenuState state{MenuState::MAIN_SCREEN};

    Board::DificultyLevel selectedDifficultyLevel{Board::DificultyLevel::easy};


public:

    MainMenu(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFontMain64);
    void paintMainScreen();
    void paintDificultyLevelSelection();

    ~MainMenu() override = default;

    bool isSuccessfullyInitialized{true};

    void paint();

    ViewType runEvent(const SDL_Event& event);
    void setMousePositionMainScreen(const int& xPos, const int& yPos);
    void setMousePositionDifficultyLevelSelection(const int& xPos, const int& yPos);

    void setMousePosition(const int &xPos, const int &yPos);

    ViewType click(const MouseButton& mouseButton);

    Board::DificultyLevel getSelectedDificultyLevel();

};


#endif //SUDOKU_GAME_WITH_SDL2_MAINMENU_H
