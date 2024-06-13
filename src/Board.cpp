//
// Created by manka543 on 5/20/24.
//

#include "Board.h"
#include "Square.h"
#include <chrono>
#include <iostream>


std::pair<int, int> Board::getFirstEmptyCell()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j].value == 0)
            {
                return std::make_pair(i,j);
            }
        }
    }
    return std::make_pair<int, int>(-1,-1);
}

bool Board::isSafe(const int& number, const std::pair<int, int>& coords) const
{
    for (const Square& square : board[coords.first])
    {
        if (square.value == number)
        {
            return false;
        }
    }
    for (auto row : board)
    {
        if (row[coords.second].value == number)
        {
            return false;
        }
    }
    auto [y, x] = std::make_pair(static_cast<int>(coords.first / 3), static_cast<int>(coords.second / 3));
    for (int i = y * 3; i < (y + 1) * 3; i++)
    {
        if (i == coords.first)
        {
            continue;
        }
        for (int j = x * 3; j < (x + 1) * 3; j++)
        {
            if (j == coords.second)
            {
                continue;
            }
            if (board[i][j].value == number)
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::pair<std::pair<int, int>, std::vector<int>>> Board::getEmptySquares()
{
    std::vector<std::pair<std::pair<int, int>, std::vector<int>>> result{};
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j].value != 0)
            {
                continue;
            }
            std::vector<int> possibilities{};
            for(int num : NUMBERS)
            {
                if(isSafe(num, std::make_pair(i,j)))
                {
                    possibilities.push_back(num);
                }
            }
            result.emplace_back(std::make_pair(i,j), possibilities);
        }
    }
    std::sort(result.begin(), result.end(), [](std::pair<std::pair<int, int>, std::vector<int>> item, std::pair<std::pair<int, int>, std::vector<int>> item2){return item.second.size() > item2.second.size();});
    return result;
}

void Board::reset()
{
    std::vector<std::vector<int>> hard {
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, //6
        {0,0,0,8,6,0,2,0,0},
        {0,0,3,9,0,0,0,0,8},
        {0,2,0,0,0,0,0,7,0},
        {6,8,9,0,0,0,0,0,0},
        {0,3,0,0,0,0,0,2,5},
        {0,0,0,0,0,5,1,4,0},
        {9,0,0,0,0,3,0,0,0},
        {0,0,1,0,2,0,0,0,0}
    };
    // std::vector<std::vector<int>> hard{
    //     {0, 9, 0, 0, 0, 0, 0, 0, 3},
    //     {0, 2, 0, 0, 6, 0, 0, 0, 5},
    //     {0, 1, 0, 0, 9, 2, 7, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {5, 0, 0, 0, 2, 0, 0, 0, 7},
    //     {0, 6, 0, 0, 4, 0, 0, 1, 0},
    //     {0, 0, 0, 9, 0, 3, 0, 0, 0},
    //     {6, 0, 0, 4, 0, 0, 3, 0, 0},
    //     {8, 0, 0, 0, 7, 0, 0, 0, 4}
    // };
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[j][i].value = hard[j][i];
        }
    }
}

int Board::removeValue(int maxNumbers, std::list<std::pair<int, int>>& positionsToRemove)
{
    size_t bestResult = positionsToRemove.size();
    // for(std::pair<int, int> position : positionsToRemove)
    for(auto position = positionsToRemove.begin(); position != positionsToRemove.end(); ++position)
    {

        int value = board[position->first][position->second].value;
        board[position->first][position->second].value = 0;

        if(isMoreThanOneSolution(*position,value))
        {
            if(positionsToRemove.size() <= maxNumbers)
            {
                board[position->first][position->second].value = value;
                continue;
            }
        } else
        {
            positionsToRemove.erase(position);
            int result = removeValue(maxNumbers, positionsToRemove);
            if(result < bestResult)
            {
                bestResult = result;
            }
            if(result < maxNumbers)
            {
                return result;
            }
            board[position->first][position->second].value = value;
            positionsToRemove.insert(position, *position);
        }
    }
    return static_cast<int>(bestResult);
}

bool Board::isMoreThanOneSolution(std::pair<int, int> lastDeletedPosition, int lastDeletedNumber)
{
    auto emptySquares = getEmptySquares();
    std::vector<int> possibilities;
    for(int i = 0; i<emptySquares.size(); i++)
    {
        if(emptySquares[i].first == lastDeletedPosition)
        {
            possibilities = emptySquares[i].second;
            emptySquares.erase(emptySquares.begin()+i);
        }
    }

    for(int num : possibilities)
    {
        if(num == lastDeletedNumber)
        {
            continue;
        }
        if(isSafe(num, lastDeletedPosition))
        {
            board[lastDeletedPosition.first][lastDeletedPosition.second].value = num;
            if(solveBoardFast(emptySquares))
            {
                board[lastDeletedPosition.first][lastDeletedPosition.second].value = 0;
                return true;
            }
            board[lastDeletedPosition.first][lastDeletedPosition.second].value = 0;
        }
    }
    return false;
}

std::vector<std::pair<int, int>> Board::getFullSquares()
{
    std::vector<std::pair<int, int>> positions{};
    positions.reserve(81);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            positions.emplace_back(std::make_pair(i,j));
        }
    }
    return positions;
}


Board::Board(const DificultyLevel& dificultyLevel)
{
    // Get the starting point
    auto start = std::chrono::high_resolution_clock::now();

    // Call the function to be timed
    // for(int i = 0; i < 10; i++)
    // {
    //     reset();
    //     auto possibilities = getEmptySquares();
    //     solveBoardFast(possibilities);
    // }

    // Get the ending point
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output the duration
    std::cout << "myFunction() took " << duration.count() << " milliseconds." << std::endl;
    // Get the starting point
    start = std::chrono::high_resolution_clock::now();

    // Call the function to be timed
    // for(int i = 0; i < 10; i++)
    {
        solveBoardRandom();
        auto fullSquares = getFullSquares();
        std::ranges::shuffle(fullSquares.begin(), fullSquares.end(), gen);
        std::list<std::pair<int, int>> fullSquaresList{fullSquares.begin(), fullSquares.end()};

        removeValue(60, fullSquaresList);
    }


    // Get the ending point
    end = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Output the duration
    std::cout << "myFunction() took " << duration.count() << " milliseconds." << std::endl;
}

Square Board::getSquare(const int& row, const int& column) const
{
    return board[row][column];
}

void Board::setSquare(const int& number, const int& row, const int& column)
{
    board[row][column].value = number;
}

bool Board::solveBoardRandom()
{
    auto cordsOfEmptyCell = getFirstEmptyCell();
    if (cordsOfEmptyCell.first == -1 || cordsOfEmptyCell.second == -1)
    {
        return true;
    }
    std::vector<int> numbersQueue = NUMBERS;
    std::ranges::shuffle(numbersQueue.begin(), numbersQueue.end(), gen);
    for (int& number : numbersQueue)
    {
        if(!isSafe(number, cordsOfEmptyCell))
        {
            continue;
        }
        board[cordsOfEmptyCell.first][cordsOfEmptyCell.second].value = number;
        if(solveBoardRandom())
        {
            return true;
        }
    }
    board[cordsOfEmptyCell.first][cordsOfEmptyCell.second].value = 0;
    return false;
}

bool Board::solveBoardFast(std::vector<std::pair<std::pair<int, int>, std::vector<int>>>& emptySquares)
{
    if(emptySquares.empty())
    {
        return true;
    }
    // std::vector<int> numbersQueue = NUMBERS;
    // std::ranges::shuffle(numbersQueue.begin(), numbersQueue.end(), gen);
    auto square = emptySquares.back();
    emptySquares.pop_back();

    for (int& number : square.second)
    {
        if(!isSafe(number, square.first))
        {
            continue;
        }
        board[square.first.first][square.first.second].value = number;
        if(solveBoardFast(emptySquares))
        {
            board[square.first.first][square.first.second].value = 0;
            return true;
        }
    }
    board[square.first.first][square.first.second].value = 0;
    emptySquares.push_back(square);
    return false;
}
