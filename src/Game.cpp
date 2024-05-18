//
// Created by manka on 29/04/2024.
//

#include "Game.h"

#include <cmath>

#include "Constants.h"

Game::Game(std::shared_ptr<SDL_Renderer> &pRenderer, std::shared_ptr<TTF_Font> &pFont, std::shared_ptr<TTF_Font> &pBoldFont) : pRenderer(pRenderer), pFont(pFont), pBoldFont(pBoldFont) {
    for (int positionY = 0; positionY < 9; positionY++) {
        board.emplace_back();
        board[positionY].reserve(9);
        for (int positionX = 0; positionX < 9; positionX++){
            board[positionY].emplace_back((positionY+positionX)%10);
        }
    }
    loadNumberTextures();
}

void Game::paint() {
    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_OUTER_FRAME_COLOR.r, Constants::GAME_BOARD_OUTER_FRAME_COLOR.g, Constants::GAME_BOARD_OUTER_FRAME_COLOR.b, Constants::GAME_BOARD_OUTER_FRAME_COLOR.a);
//    SDL_RenderDrawRect(pRenderer.get(), &Constants::GAME_BOARD_RECT);
    SDL_RenderFillRect(pRenderer.get(), &Constants::GAME_BOARD_RECT);

    SDL_Rect innerFrameSquare{0,0,162,162};

    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_INNER_FRAME_COLOR.r, Constants::GAME_BOARD_INNER_FRAME_COLOR.g, Constants::GAME_BOARD_INNER_FRAME_COLOR.b, Constants::GAME_BOARD_INNER_FRAME_COLOR.a);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            innerFrameSquare.x = Constants::GAME_BOARD_RECT.x + i * 171 + 12;
            innerFrameSquare.y = Constants::GAME_BOARD_RECT.y + j * 171 + 12;
            SDL_RenderFillRect(pRenderer.get(), &innerFrameSquare);
        }
    }

    SDL_Rect boardSquare{0,0,50,50};

    SDL_SetRenderDrawColor(pRenderer.get(), Constants::GAME_BOARD_BACKGROUND_COLOR.r,Constants::GAME_BOARD_BACKGROUND_COLOR.g,Constants::GAME_BOARD_BACKGROUND_COLOR.b,Constants::GAME_BOARD_BACKGROUND_COLOR.a);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            boardSquare.x = Constants::GAME_BOARD_RECT.x + i*56 + 12 + (int)std::floor(i/3)*3;
            boardSquare.y = Constants::GAME_BOARD_RECT.y + j*56 + 12 + (int)std::floor(j/3)*3;
            SDL_RenderFillRect(pRenderer.get(), &boardSquare);
        }
    }

    SDL_Rect numberRect{0,0,20,40};
    for(int row = 0;  row < 9; row++){
        for(int column = 0; column < 9; column++){
            numberRect.x = Constants::GAME_BOARD_RECT.x + column * 56 + 25 + (int)std::floor(column/3)*3;
            numberRect.y = Constants::GAME_BOARD_RECT.y + row * 56 + 20 + (int)std::floor(row/3)*3;
            SDL_RenderCopy(pRenderer.get(), (*pNumbers[board[row][column]])[Utilities::NumberTextureVersion::Program].get(),
                           nullptr, &numberRect);
        }
    }
}

bool Game::loadNumberTextures() {
    pNumbers.reserve(10);
    for(int number = 0; number < 10; number++){
        pNumbers.push_back(std::make_unique<Utilities::NumberTexture>(number, pFont, pBoldFont, pRenderer));
    }
    return true;
}
