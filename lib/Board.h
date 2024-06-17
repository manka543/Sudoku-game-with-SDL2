//
// Created by manka543 on 5/20/24.
//

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <vector>
#include <random>
#include <algorithm>
#include <list>
#include "Square.h"
#include <thread>


class Board {

public:

    enum class DificultyLevel: int{
        easy,
        medium,
        hard
    };

private:

    std::vector<int> NUMBERS{1,2,3,4,5,6,7,8,9};

    std::array<std::array<Square, 9>, 9> board{};

    std::array<std::array<int, 9>, 9> bestBoard{};
    int bestBoardNOFullCell{81};

    std::random_device rd;
    std::mt19937 gen{rd()};

    bool termianteBoardGeneration{false};

    bool isBoardGenerationFinished{false};

    DificultyLevel dificultyLevel{DificultyLevel::easy};

    std::pair<int, int> getFirstEmptyCell();

    std::thread boardGeneration;

    bool isSafe(const int& number, const std::pair<int, int>& coords);

    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> getEmptySquares();

    void reset();
    void copyBoard(int NOFullCells);

    std::pair<bool, int> removeValue(int maxNumbers, int minNumbers, std::list<std::pair<int, int>>& positionsToRemove);

    bool isMoreThanOneSolution(std::pair<int, int> lastDeletedPosition, int lastDeletedNumber);

    std::vector<std::pair<int, int>> getFullSquares();

    void generateBoard(DificultyLevel dificultyLevel);

public:


    Board();
    ~Board() = default;

    Square getSquare(const int& row, const int& column) const;
    void setSquare(const int& number, const int& row, const int& column);

    bool solveBoardRandom();
    bool solveBoardFast(std::vector<std::pair<std::pair<int, int>, std::vector<int>>>& emptySquares);

    bool hasBoardGenerationEnded();

    void runBoardGeneration(DificultyLevel dificultyLevel);

};



#endif //BOARD_H
