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
#include "Paintable.h"

class Game : public Paintable {

    enum class Direction : int {
    left, right, up, down
    };

//    std::shared_ptr<SDL_Renderer> pRenderer;

//    std::shared_ptr<TTF_Font> pFont;
    std::shared_ptr<TTF_Font> pBoldFont;

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> pGameWonText{nullptr, &SDL_DestroyTexture};

    std::vector<std::unique_ptr<Utilities::NumberTexture>> pNumbers{};

    std::shared_ptr<Board> pBoard;

    std::pair<int, int> selectedSquare{-1,-1};

    bool isOnPauseButton{false};

    bool loadNumberTextures();

    bool loadText();

    void placeNumber(const int& number);

    void mouseClick(const int& xPos, const int& yPos);

    void moveSelectedSquare(const Direction& direction);

    void paintBoard();

    void paintNumbers();

    void paintSetNumberBoard() const;

    void paintUI();

public:

    Game(const std::shared_ptr<SDL_Renderer>& pRenderer, const std::shared_ptr<TTF_Font>& pFontMain64, const std::shared_ptr<TTF_Font> &pBoldFont, std::shared_ptr<Board>& pBoard);
    ~Game() = default;

    void paint();

    ViewType runEvent(const SDL_Event& event);

};

#endif //GAME_H
