//
// Created by manka on 29/04/2024.
//

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <vector>
#include "Board.h"
#include "ViewType.h"
#include "Utilities.h"

class Game {

    enum class Direction : int {
    left, right, up, down
    };

    std::shared_ptr<SDL_Renderer> pRenderer;

    std::shared_ptr<TTF_Font> pFont;
    std::shared_ptr<TTF_Font> pBoldFont;

    std::vector<std::unique_ptr<Utilities::NumberTexture>> pNumbers{};

    Board board;

    std::pair<int, int> selectedSquare{-1,-1};

    bool isOnPauseButton{false};

    bool loadNumberTextures();

    void placeNumber(const int& number);

    void mouseClick(const int& xPos, const int& yPos);

    void moveSelectedSquare(const Direction& direction);

    void paintBoard();

    void paintNumbers();

    void paintSetNumberBoard() const;

    void paintUI();

public:

    Game(const std::shared_ptr<SDL_Renderer>& pRenderer, const std::shared_ptr<TTF_Font>& pFontMain64, const std::shared_ptr<TTF_Font> &pBoldFont);
    ~Game() = default;

    void paint();

    ViewType runEvent(const SDL_Event& event);

};

#endif //GAME_H
