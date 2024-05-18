//
// Created by manka on 29/04/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <vector>
#include "Utilities.h"



class Game {

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFont;
    std::shared_ptr<TTF_Font> pBoldFont;

    std::vector<std::unique_ptr<Utilities::NumberTexture>> pNumbers{};

    std::vector<std::vector<int>> board;

public:

    Game(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFontMain64, std::shared_ptr<TTF_Font> &pBoldFont);
    ~Game() = default;

    void paint();

    bool loadNumberTextures();

};



#endif //GAME_H
