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

    static constexpr SDL_Color BACKGROUND_COLOR{0x40, 0x40, 0x40, 0xff};


    static constexpr char MAIN_MENU_TITLE_TEXT[] = "SUDOKU";
    static constexpr SDL_Color MAIN_MENU_TITLE_TEXT_COLOR{ 0xff, 0xff, 0x0, 0xff};
    static constexpr SDL_Rect MAIN_MENU_TITLE_POSITION{85,50,550,144};

    static constexpr SDL_Color MAIN_MENU_OPTIONS_TEXT_COLOR{ 0xff, 0xcc, 0x0, 0xff};
    static constexpr SDL_Color MAIN_MENU_OPTIONS_SELECTED_TEXT_COLOR{0x65, 0x35, 0x0f, 0xff};

    static constexpr char MAIN_MENU_PLAY_TEXT[] = "PLAY";
    static constexpr SDL_Rect MAIN_MENU_PLAY_POSITION{245,250,230,100};

    static constexpr char MAIN_MENU_QUIT_TEXT[] = "QUIT";
    static constexpr SDL_Rect MAIN_MENU_QUIT_POSITION{245,400,230,100};

    static constexpr char MAIN_MENU_POINTER_TEXT[] = "->";
    static constexpr SDL_Rect MAIN_MENU_POINTER_POSITION_PLAY{180,250,60,100};
    static constexpr SDL_Rect MAIN_MENU_POINTER_POSITION_QUIT{180,400,60,100};

    static constexpr char FONT_MAIN_PATH[] = R"(Z:\projekty\studia\Sudoku-game-with-SDL2\assets\fonts\Lato-Black.ttf)";

    static constexpr int FONT_MAIN_SIZE_64{288};
};

#endif //PROJECT_NAME_PROGRAMCONSTANTS_H
