//
// Created by manka on 29/04/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <vector>



class Game {

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFont;

    std::vector<std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>> pNumbers;

//    std::vector<std::>;

public:

    Game(std::shared_ptr<SDL_Renderer>& pRenderer, std::shared_ptr<TTF_Font>& pFontMain64);
    ~Game() = default;

    void paint();

    bool loadNumberTextures();

};



#endif //GAME_H
