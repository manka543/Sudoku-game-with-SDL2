//
// Created by manka on 29/04/2024.
//

#include "Game.h"
#include "Constants.h"

Game::Game(std::shared_ptr<SDL_Renderer> &pRenderer, std::shared_ptr<TTF_Font> &pFont) : pRenderer(pRenderer), pFont(pFont) {

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
}

bool Game::loadNumberTextures() {
    return false;
}
