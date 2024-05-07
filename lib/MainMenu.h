//
// Created by manka on 24/04/2024.
//

#ifndef SUDOKU_GAME_WITH_SDL2_MAINMENU_H
#define SUDOKU_GAME_WITH_SDL2_MAINMENU_H

#include <SDL_ttf.h>
#include <MouseButton.h>
#include <ViewType.h>
#include <memory>

class MainMenu {

    enum class MenuOption : int {
        NONE = 0,
        PLAY,
        QUIT
    };

    bool loadTexts();

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pTitleText{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPlayTextDefault{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPlayTextSelected{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pQuitTextDefault{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pQuitTextSelected{nullptr, &SDL_DestroyTexture};
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pPointerText{nullptr, &SDL_DestroyTexture};

    std::shared_ptr<TTF_Font> pFont;

    MenuOption selectedOption = MenuOption::NONE;

    std::shared_ptr<SDL_Renderer> pRenderer;


public:

    MainMenu(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFontMain64);

    ~MainMenu() = default;

    bool isSuccessfullyInitialized{true};

    void paint();

    void setMousePosition(const int &xPos, const int &yPos);

    ViewType click(const MouseButton& mouseButton);

};


#endif //SUDOKU_GAME_WITH_SDL2_MAINMENU_H
