//
// Created by manka on 18/04/2024.
//

#ifndef PROJECT_NAME_PROGRAMCONSTANTS_H
#define PROJECT_NAME_PROGRAMCONSTANTS_H

#include <string_view>

class Constants{
public:
    static constexpr int WINDOW_HEIGHT{720};
    static constexpr int WINDOW_WIDTH{720};

    static constexpr char WINDOW_TITLE[] = "Sudoku";

    static constexpr SDL_Color BACKGROUND_COLOR{0x90, 0x90, 0x90, 0xff};


    static constexpr char MAIN_MENU_TITLE_TEXT[] = "SUDOKU";
    static constexpr SDL_Color MAIN_MENU_TITLE_TEXT_COLOR{ 0xff, 0xff, 0xff, 0xff};
    static constexpr SDL_Rect MAIN_MENU_TITLE_POSITION{100,100,550,144};


    static constexpr char FONT_MAIN_PATH[] = R"(Z:\projekty\studia\Sudoku-game-with-SDL2\assets\fonts\Lato-Black.ttf)";

    static constexpr int FONT_MAIN_SIZE_64{288};
};

#endif //PROJECT_NAME_PROGRAMCONSTANTS_H
