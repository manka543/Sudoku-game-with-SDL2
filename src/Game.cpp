//
// Created by manka on 29/04/2024.
//

#include "Game.h"

#include <cmath>

#include "Constants.h"

#include <iostream>

Game::Game(const std::shared_ptr<SDL_Renderer>& pRenderer, const std::shared_ptr<TTF_Font>& pFont,
           const std::shared_ptr<TTF_Font>& pBoldFont, std::shared_ptr<Board> pBoard) : pRenderer(pRenderer), pFont(pFont), pBoldFont(pBoldFont), pBoard(pBoard)
{
    loadNumberTextures();
}


void Game::paint()
{
    paintBoard();

    paintNumbers();

    paintSetNumberBoard();

    paintUI();
}

ViewType Game::runEvent(const SDL_Event& event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_DOWN:
                {
                    moveSelectedSquare(Direction::down);
                    break;
                }
            case SDLK_UP:
                {
                    moveSelectedSquare(Direction::up);
                    break;
                }
            case SDLK_LEFT:
                {
                    moveSelectedSquare(Direction::left);
                    break;
                }
            case SDLK_RIGHT:
                {
                    moveSelectedSquare(Direction::right);
                    break;
                }
            default:
                {
                    int keyNumber = Utilities::decodeKey(event.key.keysym.sym);
                    if (keyNumber != -1)
                    {
                        placeNumber(keyNumber);
                    }
                    break;
                }
            }
        }
    case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == 1)
            {
                mouseClick(event.button.x, event.button.y);
            }
            break;
        }
    case SDL_MOUSEMOTION:
        {
            isOnPauseButton = Utilities::isContaining(Constants::GAME_PAUSE_BUTTON_HITBOX, event.motion.x, event.motion.y);
        }
    default:
        {
            break;
        }
    }
    return ViewType::GAME;
}

bool Game::loadNumberTextures()
{
    pNumbers.reserve(9);
    for (int number = 1; number < 10; number++)
    {
        pNumbers.push_back(std::make_unique<Utilities::NumberTexture>(number, pFont, pBoldFont, pRenderer));
    }
    return true;
}

void Game::placeNumber(const int& number)
{
    if(selectedSquare.first != -1)
    {
        pBoard->setSquare(number, selectedSquare.second, selectedSquare.first);
    }
}

void Game::mouseClick(const int& xPos, const int& yPos)
{
    if (Utilities::isContaining(Constants::GAME_BOARD_RECT, xPos, yPos))
    {
        int row = 0, column = 0;

        for (int i = 1; i < 10; i++)
        {
            if (xPos < Constants::GAME_BOARD_RECT.x + i * 56 + 12 + 12 * (int)std::floor(i / 9) + (int)std::floor(i / 3)
                * 3)
            {
                column = i - 1;
                break;
            }
        }
        for (int i = 1; i < 10; i++)
        {
            if (yPos < Constants::GAME_BOARD_RECT.y + i * 56 + 12 + 12 * (int)std::floor(i / 9) + (int)std::floor(i / 3)
                * 3)
            {
                row = i - 1;
                break;
            }
        }

        selectedSquare = std::make_pair(column, row);
        std::cout << "Clicked square(row: " << row << ", column: " << column << ")\n";
    } else if (Utilities::isContaining(Constants::GAME_SET_NUMBER_BOARD_RECT, xPos, yPos))
    {
        int number = std::floor((xPos - Constants::GAME_SET_NUMBER_BOARD_RECT.x - 3) / 56);
        if(number < 0)
        {
            number = 0;
        } else if(number > 9)
        {
            number = 8;
        }
        placeNumber(number);
    }
}

void Game::moveSelectedSquare(const Direction& direction)
{
    switch (direction)
    {
    case Direction::right:
        {
            if (selectedSquare.first == -1)
            {
                selectedSquare = std::make_pair(0, 0);
            }
            else if (selectedSquare.first == 8)
            {
                selectedSquare.first = 0;
            }
            else
            {
                selectedSquare.first += 1;
            }
            break;
        }
    case Direction::left:
        {
            if (selectedSquare.first == -1)
            {
                selectedSquare = std::make_pair(8, 0);
            }
            else if (selectedSquare.first == 0)
            {
                selectedSquare.first = 8;
            }
            else
            {
                selectedSquare.first -= 1;
            }
            break;
        }
    case Direction::down:
        {
            if (selectedSquare.first == -1)
            {
                selectedSquare = std::make_pair(0, 0);
            }
            else if (selectedSquare.second == 8)
            {
                selectedSquare.second = 0;
            }
            else
            {
                selectedSquare.second += 1;
            }
            break;
        }
    case Direction::up:
        {
            if (selectedSquare.first == -1)
            {
                selectedSquare = std::make_pair(0, 8);
            }
            else if (selectedSquare.second == 0)
            {
                selectedSquare.second = 8;
            }
            else
            {
                selectedSquare.second -= 1;
            }
            break;
        }
    }
}

void Game::paintBoard()
{
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_OUTER_FRAME_COLOR.r,
                           Constants::GAME_BOARD_OUTER_FRAME_COLOR.g, Constants::GAME_BOARD_OUTER_FRAME_COLOR.b,
                           Constants::GAME_BOARD_OUTER_FRAME_COLOR.a);

    SDL_RenderFillRect(pRenderer.get(), &Constants::GAME_BOARD_RECT);

    SDL_Rect innerFrameSquare{0, 0, 162, 162};

    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_INNER_FRAME_COLOR.r,
                           Constants::GAME_BOARD_INNER_FRAME_COLOR.g, Constants::GAME_BOARD_INNER_FRAME_COLOR.b,
                           Constants::GAME_BOARD_INNER_FRAME_COLOR.a);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            innerFrameSquare.x = Constants::GAME_BOARD_RECT.x + i * 171 + 12;
            innerFrameSquare.y = Constants::GAME_BOARD_RECT.y + j * 171 + 12;
            SDL_RenderFillRect(pRenderer.get(), &innerFrameSquare);
        }
    }
    if(selectedSquare.first != -1)
    {
        const SDL_Rect selectedSquareRect{
            Constants::GAME_BOARD_RECT.x + selectedSquare.first * 56 + 6 + (int)std::floor(selectedSquare.first / 3) * 3,
            Constants::GAME_BOARD_RECT.y + selectedSquare.second * 56 + 6 + (int)std::floor(selectedSquare.second / 3) * 3,
            62, 62
        };
        SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_SELECTED_SQUARE_COLOR.r,
                               Constants::GAME_BOARD_SELECTED_SQUARE_COLOR.g, Constants::GAME_BOARD_SELECTED_SQUARE_COLOR.b,
                               Constants::GAME_BOARD_SELECTED_SQUARE_COLOR.a);
        SDL_RenderFillRect(pRenderer.get(), &selectedSquareRect);
    }
    SDL_Rect boardSquare{0, 0, 50, 50};

    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_BACKGROUND_COLOR.r,
                           Constants::GAME_BOARD_BACKGROUND_COLOR.g, Constants::GAME_BOARD_BACKGROUND_COLOR.b,
                           Constants::GAME_BOARD_BACKGROUND_COLOR.a);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            boardSquare.x = Constants::GAME_BOARD_RECT.x + i * 56 + 12 + (int)std::floor(i / 3) * 3;
            boardSquare.y = Constants::GAME_BOARD_RECT.y + j * 56 + 12 + (int)std::floor(j / 3) * 3;
            SDL_RenderFillRect(pRenderer.get(), &boardSquare);
        }
    }
}

void Game::paintNumbers()
{
    SDL_Rect numberRect{0, 0, 20, 40};
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            if((pBoard->getSquare(row,column).value) != 0 )
            {
            numberRect.x = Constants::GAME_BOARD_RECT.x + column * 56 + 25 + (int)std::floor(column / 3) * 3;
            numberRect.y = Constants::GAME_BOARD_RECT.y + row * 56 + 20 + (int)std::floor(row / 3) * 3;
            SDL_RenderCopy(pRenderer.get(),
                           (*pNumbers[(pBoard->getSquare(row,column).value) - 1])[Utilities::NumberTextureVersion::Program].get(),
                           nullptr, &numberRect);
            }
        }
    }
}

void Game::paintSetNumberBoard() const
{
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_INNER_FRAME_COLOR.r, Constants::GAME_BOARD_INNER_FRAME_COLOR.g, Constants::GAME_BOARD_INNER_FRAME_COLOR.b, Constants::GAME_BOARD_INNER_FRAME_COLOR.a);
    SDL_RenderFillRect(pRenderer.get(), &Constants::GAME_SET_NUMBER_BOARD_RECT);

    SDL_Rect squareRect{83,664,50,50};
    SDL_Rect numberRect{98,670,20,40};
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_BACKGROUND_COLOR.r, Constants::GAME_BOARD_BACKGROUND_COLOR.g, Constants::GAME_BOARD_BACKGROUND_COLOR.b, Constants::GAME_BOARD_BACKGROUND_COLOR.a);
    for(int i = 0; i <10; i++)
    {
        SDL_RenderFillRect(pRenderer.get(), &squareRect);
        if(i!=0)
        {
            SDL_RenderCopy(pRenderer.get(), (*pNumbers[i-1])[Utilities::NumberTextureVersion::User].get(),nullptr, &numberRect);
        }
        squareRect.x += 56;
        numberRect.x += 56;
    }
}

void Game::paintUI()
{
    SDL_Rect pauseGameRect{10,10,15,40};
    if(isOnPauseButton)
    {
        SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_BACKGROUND_COLOR.r, Constants::GAME_BOARD_BACKGROUND_COLOR.g, Constants::GAME_BOARD_BACKGROUND_COLOR.b, Constants::GAME_BOARD_BACKGROUND_COLOR.a);
    } else
    {
        SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_OUTER_FRAME_COLOR.r, Constants::GAME_BOARD_OUTER_FRAME_COLOR.g, Constants::GAME_BOARD_OUTER_FRAME_COLOR.b, Constants::GAME_BOARD_OUTER_FRAME_COLOR.a);
    }
    SDL_RenderFillRect(pRenderer.get(), &pauseGameRect);
    pauseGameRect.x +=25;
    SDL_RenderFillRect(pRenderer.get(), &pauseGameRect);

}

