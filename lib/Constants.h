//
// Created by manka on 18/04/2024.
//

#ifndef PROJECT_NAME_PROGRAMCONSTANTS_H
#define PROJECT_NAME_PROGRAMCONSTANTS_H

#include <string_view>
#include <SDL.h>

class Constants
{
public:
    static constexpr int WINDOW_HEIGHT{720};
    static constexpr int WINDOW_WIDTH{720};

    static constexpr char WINDOW_TITLE[] = "Sudoku";

    static constexpr SDL_Color BACKGROUND_COLOR{0x0e, 0x46, 0xa3, 0xff};


    static constexpr char MAIN_MENU_TITLE_TEXT[] = "SUDOKU";
    static constexpr SDL_Color MAIN_MENU_TITLE_TEXT_COLOR{0x1e, 0x03, 0x42, 0xff};
    static constexpr SDL_Rect MAIN_MENU_TITLE_POSITION{85, 50, 550, 144};

    static constexpr SDL_Color MAIN_MENU_OPTIONS_TEXT_COLOR{0x9a, 0xc8, 0xcd, 0xff};
    static constexpr SDL_Color MAIN_MENU_OPTIONS_SELECTED_TEXT_COLOR{0xe1, 0xf7, 0xf5, 0xff};

    static constexpr char MAIN_MENU_PLAY_TEXT[] = "PLAY";
    static constexpr SDL_Rect MAIN_MENU_PLAY_POSITION{245, 250, 230, 100};

    static constexpr char MAIN_MENU_QUIT_TEXT[] = "QUIT";
    static constexpr SDL_Rect MAIN_MENU_QUIT_POSITION{245, 400, 230, 100};

    static constexpr char MAIN_MENU_EASY_LEVEL_TEXT[] = "EASY";
    static constexpr SDL_Rect MAIN_MENU_EASY_LEVEL_POSITION{245, 270, 225, 100};
    static constexpr char MAIN_MENU_MEDIUM_LEVEL_TEXT[] = "MEDIUM";
    static constexpr SDL_Rect MAIN_MENU_MEDIUM_LEVEL_POSITION{190, 370, 340, 100};
    static constexpr char MAIN_MENU_HARD_LEVEL_TEXT[] = "HARD";
    static constexpr SDL_Rect MAIN_MENU_HARD_LEVEL_POSITION{245, 470, 225, 100};

    static constexpr char MAIN_MENU_POINTER_TEXT[] = "->";
    static constexpr SDL_Rect MAIN_MENU_POINTER_POSITION_PLAY{180, 250, 60, 100};
    static constexpr SDL_Rect MAIN_MENU_POINTER_POSITION_QUIT{180, 400, 60, 100};

    static constexpr char LOADING_TEXT[] = "Loading board";
    static constexpr SDL_Rect LOADING_TEXT_POSITION{100,300,400,100};
    static constexpr char LOADING_INDICATOR_SIGN[] = ".";
    static constexpr SDL_Rect FIRST_LOADING_INDICATOR_SIGN_POSITION{515,385,15,15};

#ifdef __linux__
    static constexpr char FONT_MAIN_PATH[] = R"(assets/fonts/Lato-Black.ttf)";
    static constexpr char FONT_BOLD_PATH[] = R"(assets/fonts/Lato-Bold.ttf)";
#else
    static constexpr char FONT_MAIN_PATH[] = R"(assets\fonts\Lato-Black.ttf)";
    static constexpr char FONT_BOLD_PATH[] = R"(assets\fonts\Lato-Bold.ttf)";
#endif

    static constexpr int FONT_MAIN_SIZE_64{288};
    static constexpr int FONT_SIZE_100{100};

    static constexpr SDL_Rect GAME_TITLE_TEXT_POSITION{75,5,180,70};

    static constexpr SDL_Color GAME_BOARD_BACKGROUND_COLOR{0x12, 0x14, 0x81, 0xff};
    static constexpr SDL_Color GAME_BOARD_OUTER_FRAME_COLOR{0x1e, 0x03, 0x42, 0xff};
    static constexpr SDL_Color GAME_BOARD_INNER_FRAME_COLOR{0x2e, 0x13, 0x52, 0xff};
    static constexpr SDL_Color GAME_BOARD_SELECTED_SQUARE_COLOR{0x99,0x99,0x99,0xff};
    static constexpr SDL_Rect GAME_BOARD_RECT{96, 96, 528, 528};
    static constexpr SDL_Rect GAME_BOARD_SQUARE_RECT{0,0,50,50};

    static constexpr int GAME_BOARD_NUMBER_WIDTH{44};
    static constexpr int GAME_BOARD_NUMBER_HEIGHT{44};

    static constexpr SDL_Color GAME_BOARD_USER_NUMBER_COLOR{0xe1, 0xf7, 0xf5, 0xff};
    static constexpr SDL_Color GAME_BOARD_PROGRAM_NUMBER_COLOR{0xa1, 0xb7, 0xb5, 0xff};
    static constexpr SDL_Color GAME_BOARD_USER_NUMBER_ERROR_COLOR{0xfc,0x41,0x00,0xff};
    static constexpr SDL_Color GAME_BOARD_PROGRAM_NUMBER_ERROR_COLOR{0xcc,0x21,0x00,0xff};

    static constexpr SDL_Color GAME_NUMBER_COLOR{0xbb,0xbb,0xbb,0xff};
    static constexpr SDL_Color GAME_NUMBER_ERROR_COLOR{0xee,0x80,0x80,0xff};

    static constexpr SDL_Rect GAME_SET_NUMBER_BOARD_RECT{77,658,566,62};

    static constexpr SDL_Rect GAME_PAUSE_BUTTON_HITBOX{0,0,60,60};

    static constexpr char GAME_WON_TEXT[] = "You won!!!";
    static constexpr SDL_Rect GAME_WON_TEXT_POSITION{280,20,250,60};


    static constexpr int EASY_LEVEL_MAX_CLUES{46};
    static constexpr int MEDIUM_LEVEL_MAX_CLUES{35};
    static constexpr int HARD_LEVEL_MAX_CLUES{31};

    static constexpr int BOARD_GENERATING_TIMEOUT_MS{2000};


};

#endif //PROJECT_NAME_PROGRAMCONSTANTS_H
