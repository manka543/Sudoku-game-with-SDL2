//
// Created by manka on 24/04/2024.
//


#include "MainMenu.h"
#include "Constants.h"
#include "ErrorMessages.h"
#include "Utilities.h"

#include <iostream>

bool MainMenu::loadTexts()
{
    pTitleText = Utilities::generateTextTexture(Constants::MAIN_MENU_TITLE_TEXT, Constants::MAIN_MENU_TITLE_TEXT_COLOR,
                                                pFont, pRenderer);
    if (pTitleText == nullptr)
    {
        return false;
    }
    pPlayTextDefault = Utilities::generateTextTexture(Constants::MAIN_MENU_PLAY_TEXT,
                                                      Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                      pFont, pRenderer);
    if (pPlayTextDefault == nullptr)
    {
        return false;
    }
    pPlayTextSelected = Utilities::generateTextTexture(Constants::MAIN_MENU_PLAY_TEXT,
                                                       Constants::MAIN_MENU_OPTIONS_SELECTED_TEXT_COLOR,
                                                       pFont, pRenderer);
    if (pPlayTextSelected == nullptr)
    {
        return false;
    }
    pQuitTextDefault = Utilities::generateTextTexture(Constants::MAIN_MENU_QUIT_TEXT,
                                                      Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                      pFont, pRenderer);
    if (pQuitTextDefault == nullptr)
    {
        return false;
    }
    pQuitTextSelected = Utilities::generateTextTexture(Constants::MAIN_MENU_QUIT_TEXT,
                                                       Constants::MAIN_MENU_OPTIONS_SELECTED_TEXT_COLOR,
                                                       pFont, pRenderer);
    if (pQuitTextSelected == nullptr)
    {
        return false;
    }
    pPointerText = Utilities::generateTextTexture(Constants::MAIN_MENU_POINTER_TEXT,
                                                  Constants::MAIN_MENU_OPTIONS_SELECTED_TEXT_COLOR,
                                                  pFont, pRenderer);
    if (pPointerText == nullptr)
    {
        return false;
    }

    return true;
}

MainMenu::MainMenu(SDL_Renderer* pRenderer, TTF_Font* pFontMain64) : pRenderer(pRenderer), pFont(pFontMain64)
{
    loadTexts();
}

MainMenu::~MainMenu()
{
    //free title text texture
    SDL_DestroyTexture(pTitleText);
    pTitleText = nullptr;
    SDL_DestroyTexture(pPlayTextDefault);
    pPlayTextDefault = nullptr;
    SDL_DestroyTexture(pPlayTextSelected);
    pPlayTextSelected = nullptr;
    SDL_DestroyTexture(pQuitTextDefault);
    pQuitTextDefault = nullptr;
    SDL_DestroyTexture(pQuitTextSelected);
    pQuitTextSelected = nullptr;
    SDL_DestroyTexture(pPointerText);
    pPointerText = nullptr;
}

void MainMenu::paint()
{
    SDL_RenderCopy(pRenderer, pTitleText, nullptr, &Constants::MAIN_MENU_TITLE_POSITION);
    switch (selectedOption)
    {
    case MenuOption::NONE:
        {
            SDL_RenderCopy(pRenderer, pPlayTextDefault, nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer, pQuitTextDefault, nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    case MenuOption::PLAY:
        {
            SDL_RenderCopy(pRenderer, pPlayTextSelected, nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer, pPointerText, nullptr, &Constants::MAIN_MENU_POINTER_POSITION_PLAY);
            SDL_RenderCopy(pRenderer, pQuitTextDefault, nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    case MenuOption::QUIT:
        {
            SDL_RenderCopy(pRenderer, pPlayTextDefault, nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer, pPointerText, nullptr, &Constants::MAIN_MENU_POINTER_POSITION_QUIT);
            SDL_RenderCopy(pRenderer, pQuitTextSelected, nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    }
}

void MainMenu::setMousePosition(const int& xPos, const int& yPos)
{
    if (Utilities::isContaining(Constants::MAIN_MENU_PLAY_POSITION, xPos, yPos))
    {
        selectedOption = MenuOption::PLAY;
    }
    else if (Utilities::isContaining(Constants::MAIN_MENU_QUIT_POSITION, xPos, yPos))
    {
        selectedOption = MenuOption::QUIT;
    }
    else
    {
        selectedOption = MenuOption::NONE;
    }
}

ViewType MainMenu::click(const MouseButton& mouseButton)
{
    if(mouseButton == MouseButton::LEFT)
    {
        if(selectedOption == MenuOption::PLAY)
        {
            return ViewType::GAME;
        }
        if(selectedOption == MenuOption::QUIT)
        {
            return ViewType::QUIT;
        }
        return ViewType::MAIN_MENU;
    }
}
