//
// Created by manka543 on 5/20/24.
//

#include "Board.h"
#include "Square.h"
#include <chrono>
#include <Constants.h>
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

bool Board::isSafe(const int& number, const std::pair<int, int>& coords)
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

void Board::copyBoard(int NOFullCells)
{
    for(int i = 0; i< 9; i++)
    {
        for(int j= 0; j< 9; j++)
        {
            bestBoard[i][j] = board[i][j].value;
        }
    }
    bestBoardNOFullCell = NOFullCells;
}

std::pair<bool, int> Board::removeValue(int maxNumbers, int minNumbers, std::vector<std::pair<int, int>>& positionsToRemove)
{
    // size_t bestResult = positionsToRemove.size();
    std::pair<bool, int> bestResult{true, positionsToRemove.size()};

    if(positionsToRemove.size() <= minNumbers)
    {
        bestResult.first = false;
        return bestResult;
    }

    // for(std::pair<int, int> position : positionsToRemove)
    for(int i = 0; i < positionsToRemove.size(); i++)
    {
        if(termianteBoardGeneration)
        {
            return bestResult;
        }
        positionsToRemove[i].first;
        int value = board[positionsToRemove[i].first][positionsToRemove[i].second].value;
        board[positionsToRemove[i].first][positionsToRemove[i].second].value = 0;

        if(isMoreThanOneSolution(positionsToRemove[i],value))
        {
            board[positionsToRemove[i].first][positionsToRemove[i].second].value = value;

        } else
        {
            bestResult.first = false;

            auto buffer = positionsToRemove[i];
            positionsToRemove[i] = positionsToRemove.back();
            positionsToRemove.pop_back();
            // positionsToRemove.erase(current);

            if(positionsToRemove.size() < bestBoardNOFullCell && positionsToRemove.size() > minNumbers && positionsToRemove.size() <= maxNumbers)
            {
                copyBoard(static_cast<int>(positionsToRemove.size()));
            }

            // positionsToRemove.erase(position);

            auto result = removeValue(maxNumbers, minNumbers, positionsToRemove);
            if(result.first == true && result.second >= minNumbers && result.second <= maxNumbers)
            {
                // positionsToRemove.insert(position, *current);
                // positionsToRemove.insert(position, *position);
                copyBoard(static_cast<int>(positionsToRemove.size()));
                return result;
            } if(result.second < bestResult.second)
            {
                bestResult = result;
            }

            board[positionsToRemove[i].first][positionsToRemove[i].second].value = value;
            // positionsToRemove.insert(position, *current);
            positionsToRemove.push_back(positionsToRemove[i]);
            positionsToRemove[i] = buffer;
        }
    }
    if(bestResult.second < bestBoardNOFullCell && bestResult.second > minNumbers && bestResult.second <= maxNumbers)
    {
        copyBoard(static_cast<int>(positionsToRemove.size()));
    }
    return bestResult;
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
        if(termianteBoardGeneration)
        {
            return false;
        }
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
            positions.emplace_back(i,j);
        }
    }
    return positions;
}

void Board::generateBoard(DificultyLevel dificulty_level)
{
    solveBoardRandom();
    auto fullSquares = getFullSquares();
    std::shuffle(fullSquares.begin(), fullSquares.end(), gen);

    switch (dificulty_level)
    {
    case DificultyLevel::easy:{
            removeValue(Constants::EASY_LEVEL_MAX_CLUES, Constants::MEDIUM_LEVEL_MAX_CLUES, fullSquares);
        }
    case DificultyLevel::medium:
        {
            removeValue(Constants::MEDIUM_LEVEL_MAX_CLUES, Constants::HARD_LEVEL_MAX_CLUES,fullSquares);
        }
    case DificultyLevel::hard:
        {
            removeValue(Constants::HARD_LEVEL_MAX_CLUES, 0, fullSquares);
        }
    }

    isBoardGenerationFinished = true;
}

void Board::checkBoard()
{
    isBoardCorrect = true;
    for(int i = 0; i < 9; i++)
    {
        for(int j =0; j < 9; j++)
        {
            if(board[i][j].value == 0)
            {
                isBoardCorrect = false;
                continue;
            }
            int buf = board[i][j].value;
            board[i][j].value = 0;
            if(!isSafe(buf, std::make_pair(i,j)))
            {
                isBoardCorrect = false;
                if(board[i][j].type == Square::User)
                {
                    board[i][j].type = Square::UserFault;
                } else if (board[i][j].type == Square::Program)
                {
                    board[i][j].type = Square::ProgramFault;
                }
            } else
            {
                if(board[i][j].type == Square::UserFault)
                {
                    board[i][j].type = Square::User;
                } else if (board[i][j].type == Square::ProgramFault)
                {
                    board[i][j].type = Square::Program;
                }
            }
            board[i][j].value = buf;
        }
    }
}


Board::Board(){}


Square Board::getSquare(const int& row, const int& column) const
{
    return board[row][column];
}

void Board::setSquare(const int& number, const Square::Type& type, const int& row, const int& column)
{
    if(board[row][column].type == Square::Type::Program || board[row][column].type == Square::Type::ProgramFault)
    {
        return;
    }
    board[row][column].value = number;
    board[row][column].type = type;
    checkBoard();

}

bool Board::solveBoardRandom()
{
    auto cordsOfEmptyCell = getFirstEmptyCell();
    if (cordsOfEmptyCell.first == -1 || cordsOfEmptyCell.second == -1)
    {
        return true;
    }
    std::vector<int> numbersQueue = NUMBERS;
    std::shuffle(numbersQueue.begin(), numbersQueue.end(), gen);
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
        if(termianteBoardGeneration)
        {
            return false;
        }
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

bool Board::hasBoardGenerationEnded()
{
    bool isDifficultyGoodEnough{false};
    switch (dificultyLevel)
    {
    case DificultyLevel::easy:
        {
            isDifficultyGoodEnough = bestBoardNOFullCell <= Constants::EASY_LEVEL_MAX_CLUES && bestBoardNOFullCell>=Constants::MEDIUM_LEVEL_MAX_CLUES;
            break;
        }
    case DificultyLevel::medium:
        {
            isDifficultyGoodEnough = bestBoardNOFullCell <= Constants::MEDIUM_LEVEL_MAX_CLUES && bestBoardNOFullCell>=Constants::HARD_LEVEL_MAX_CLUES;
            break;
        }
    case DificultyLevel::hard:
        {
            // isDifficultyGoodEnough = bestBoardNOFullCell <= Constants::HARD_LEVEL_MAX_CLUES;
            isDifficultyGoodEnough = bestBoardNOFullCell <25;
            break;
        }
    }

    if(isBoardGenerationFinished || isDifficultyGoodEnough)
    {
        termianteBoardGeneration = true;
        std::cout<<boardGeneration.joinable();
        boardGeneration.join();
        if(!isBoardGenerationFinished)
        {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                board[i][j].value = bestBoard[i][j];

            }
        }
        }
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(bestBoard[i][j]!=0)
                {
                    board[i][j].type = Square::Program;
                }
            }
        }
        return true;
    }
    return false;
}

void Board::runBoardGeneration(DificultyLevel dificultyLevel)
{
    this->dificultyLevel = dificultyLevel;
    boardGeneration = std::thread(&Board::generateBoard, this, dificultyLevel);
}
