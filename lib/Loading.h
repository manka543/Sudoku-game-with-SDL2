//
// Created by manka543 on 6/15/24.
//

#ifndef LOADING_H
#define LOADING_H

#include <memory>
#include "Constants.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <ViewType.h>

#include "Board.h"


class Loading {

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pLoadingText;
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pLoadingIndicator;

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<Board> pBoard;

    bool loadTexts();

    std::shared_ptr<TTF_Font> pFont;

    int indicatorStatus = 1;

    std::chrono::time_point<std::chrono::high_resolution_clock> lastChange{};

public:
    Loading(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFont, std::shared_ptr<Board>& pBoard);
    ~Loading() = default;

    ViewType checkLoading();

    void paint();
};



#endif //LOADING_H
