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


class Board {

    std::vector<int> NUMBERS{1,2,3,4,5,6,7,8,9};

    std::array<std::array<Square, 9>, 9> board{};

    std::random_device rd;
    std::mt19937 gen{rd()};

    std::pair<int, int> getFirstEmptyCell();

    bool isSafe(const int& number, const std::pair<int, int>& coords) const;

    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> getEmptySquares();

    void reset();

    int removeValue(int maxNumbers, std::list<std::pair<int, int>>& positionsToRemove);

    bool isMoreThanOneSolution(std::pair<int, int> lastDeletedPosition, int lastDeletedNumber);


public:

    enum class DificultyLevel: int{
        easy,
        medium,
        hard
    };

    Board(const DificultyLevel& dificultyLevel);
    ~Board() = default;

    Square getSquare(const int& row, const int& column) const;
    void setSquare(const int& number, const int& row, const int& column);

    bool solveBoardRandom();
    bool solveBoardFast(std::vector<std::pair<std::pair<int, int>, std::vector<int>>>& emptySquares);

};



#endif //BOARD_H
