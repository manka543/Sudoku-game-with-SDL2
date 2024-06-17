//
// Created by manka on 24/04/2024.
//


#include "MainMenu.h"
#include "Constants.h"
#include "ErrorMessages.h"
#include "Utilities.h"

#include <iostream>


MainMenu::MainMenu(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFontMain64) : pRenderer(
        pRenderer), pFont(pFontMain64)
{
    loadTexts();
}


void MainMenu::paintMainScreen()
{
    switch (selectedOption)
    {
    case MenuOption::NONE:
        {
            SDL_RenderCopy(pRenderer.get(), pPlayTextDefault.get(), nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer.get(), pQuitTextDefault.get(), nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    case MenuOption::PLAY:
        {
            SDL_RenderCopy(pRenderer.get(), pPlayTextSelected.get(), nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer.get(), pPointerText.get(), nullptr, &Constants::MAIN_MENU_POINTER_POSITION_PLAY);
            SDL_RenderCopy(pRenderer.get(), pQuitTextDefault.get(), nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    case MenuOption::QUIT:
        {
            SDL_RenderCopy(pRenderer.get(), pPlayTextDefault.get(), nullptr, &Constants::MAIN_MENU_PLAY_POSITION);
            SDL_RenderCopy(pRenderer.get(), pPointerText.get(), nullptr, &Constants::MAIN_MENU_POINTER_POSITION_QUIT);
            SDL_RenderCopy(pRenderer.get(), pQuitTextSelected.get(), nullptr, &Constants::MAIN_MENU_QUIT_POSITION);
            break;
        }
    }
}

void MainMenu::paintDificultyLevelSelection()
{
    SDL_RenderCopy(pRenderer.get(), pEasyLevelText.get(), nullptr, &Constants::MAIN_MENU_EASY_LEVEL_POSITION);
    SDL_RenderCopy(pRenderer.get(), pMediumLevelText.get(), nullptr, &Constants::MAIN_MENU_MEDIUM_LEVEL_POSITION);
    SDL_RenderCopy(pRenderer.get(), pHardLevelText.get(), nullptr, &Constants::MAIN_MENU_HARD_LEVEL_POSITION);
}

void MainMenu::paint()
{
    switch (state)
    {
    case MenuState::MAIN_SCREEN:
        {
            paintMainScreen();
            break;
        }
    case MenuState::DIFFICULTY_LEVEL_SELECTION:
        {
            paintDificultyLevelSelection();
            break;
        }
    case MenuState::PAUSE_MENU:
        {
            break;
        }
    }
}

ViewType MainMenu::runEvent(const SDL_Event& event)
{
    if (event.type == SDL_MOUSEMOTION)
    {
        setMousePosition(event.motion.x, event.motion.y);
    }
    else if (event.type == SDL_MOUSEBUTTONDOWN &&
        static_cast<MouseButton>(event.button.button) == MouseButton::LEFT)
    {
        setMousePosition(event.motion.x, event.motion.y);
        return click(MouseButton::LEFT);
    }
    return ViewType::MAIN_MENU;
}

void MainMenu::setMousePositionMainScreen(const int& xPos, const int& yPos)
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

void MainMenu::setMousePositionDifficultyLevelSelection(const int& xPos, const int& yPos)
{
    if (Utilities::isContaining(Constants::MAIN_MENU_EASY_LEVEL_POSITION, xPos, yPos))
    {
        selectedOption = MenuOption::EASY;
    }
    else if (Utilities::isContaining(Constants::MAIN_MENU_MEDIUM_LEVEL_POSITION, xPos, yPos))
    {
        selectedOption = MenuOption::MEDIUM;
    }
    else if (Utilities::isContaining(Constants::MAIN_MENU_HARD_LEVEL_POSITION, xPos, yPos))
    {
        selectedOption = MenuOption::HARD;
    }
    else
    {
        selectedOption = MenuOption::NONE;
    }
}

void MainMenu::setMousePosition(const int& xPos, const int& yPos)
{
    switch (state)
    {
    case MenuState::MAIN_SCREEN:
        {
            setMousePositionMainScreen(xPos, yPos);
            break;
        }
    case MenuState::DIFFICULTY_LEVEL_SELECTION:
        {
            setMousePositionDifficultyLevelSelection(xPos, yPos);
            break;
        }
    }
}

ViewType MainMenu::click(const MouseButton& mouseButton)
{
    if (mouseButton == MouseButton::LEFT)
    {
        switch (selectedOption)
        {
        case MenuOption::PLAY:
            {
                state = MenuState::DIFFICULTY_LEVEL_SELECTION;
                return ViewType::MAIN_MENU;
            }
        case MenuOption::QUIT:
            {
                return ViewType::QUIT;
            }
        case MenuOption::EASY:
            {
                selectedDifficultyLevel = Board::DificultyLevel::easy;
                return ViewType::LOADING;
            }
        case MenuOption::MEDIUM:
            {
                selectedDifficultyLevel = Board::DificultyLevel::medium;
                return ViewType::LOADING;
            }
        case MenuOption::HARD:
            {
                selectedDifficultyLevel = Board::DificultyLevel::hard;
                return ViewType::LOADING;
            }
        default:
            {
                return ViewType::MAIN_MENU;
            }
        }
    }
}

Board::DificultyLevel MainMenu::getSelectedDificultyLevel()
{
    return selectedDifficultyLevel;
}

bool MainMenu::loadTexts()
{

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
    pEasyLevelText = Utilities::generateTextTexture(Constants::MAIN_MENU_EASY_LEVEL_TEXT,
                                                    Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                    pFont, pRenderer);
    if (pEasyLevelText == nullptr)
    {
        return false;
    }
    pMediumLevelText = Utilities::generateTextTexture(Constants::MAIN_MENU_MEDIUM_LEVEL_TEXT,
                                                      Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                      pFont, pRenderer);
    if (pMediumLevelText == nullptr)
    {
        return false;
    }
    pHardLevelText = Utilities::generateTextTexture(Constants::MAIN_MENU_HARD_LEVEL_TEXT,
                                                    Constants::MAIN_MENU_OPTIONS_TEXT_COLOR,
                                                    pFont, pRenderer);
    if (pHardLevelText == nullptr)
    {
        return false;
    }

    return true;
}
