#include <iostream>
#include <algorithm>
#include "math2DVector.h"
#include "ConnectFour.h"
#include "Constants.h"

ConnectFour::ConnectFour()
{
    resetGame();
}

void ConnectFour::resetGame()
{
    for (auto &row : board)
    {
        row.fill('.');
    }
    nextAvailableRow.fill(0);
    currentPlayer = Player::ONE;
}

std::string ConnectFour::toString() const
{
    std::string output = "0123456\n";
    for (int i = 0; i < Constants::rows; ++i)
    {
        for (int j = 0; j < Constants::columns; ++j)
        {
            output += board[i][j];
        }
        output += '\n';
    }
    return output;
}

bool ConnectFour::isValidMove(int col) const
{
    return col >= 0 && col < Constants::columns && nextAvailableRow[col] < Constants::rows;
}

char ConnectFour::getCurrentSymbol() const
{
    return currentPlayer == Player::ONE ? Constants::playerSymbol[0] : Constants::playerSymbol[1];
}

void ConnectFour::makeMove(int col)
{
    int row = nextAvailableRow[col];
    board[row][col] = getCurrentSymbol();
    lastMove = math2DVector(row, col);
    ++nextAvailableRow[col];
    currentPlayer = currentPlayer == Player::ONE ? Player::TWO : Player::ONE;
}

bool ConnectFour::isWithinBounds(const math2DVector &point) const
{
    return point.x >= 0 && point.x < Constants::rows && point.y >= 0 && point.y < Constants::columns;
}

int ConnectFour::countInDirection(const math2DVector &dir) const
{
    char symbol = board[lastMove.x][lastMove.y];
    int count = 1;

    // Forward
    math2DVector pos = lastMove + dir;
    while (isWithinBounds(pos) && board[pos.x][pos.y] == symbol)
    {
        ++count;
        pos = pos + dir;
    }

    // Backward
    pos = lastMove - dir;
    while (isWithinBounds(pos) && board[pos.x][pos.y] == symbol)
    {
        ++count;
        pos = pos - dir;
    }

    return count;
}

ConnectFour::GameState ConnectFour::checkGameState() const
{
    if (countInDirection({1, 0}) >= Constants::winCount ||
        countInDirection({0, 1}) >= Constants::winCount ||
        countInDirection({1, 1}) >= Constants::winCount ||
        countInDirection({1, -1}) >= Constants::winCount)
    {
        return GameState::WIN;
    }

    // Check for draw
    for (int col : nextAvailableRow)
    {
        if (col < Constants::rows)
            return GameState::ONGOING;
    }

    return GameState::DRAW;
}

void ConnectFour::start()
{
    std::cout << "Welcome to Connect Four!\n";
    GameState state = GameState::ONGOING;
    std::cout << toString();

    while (state == GameState::ONGOING)
    {
        int col;
        std::cout << "Player " << (currentPlayer == Player::ONE ? "1 (X)" : "2 (O)") << ", choose a column (0-6): ";
        while (!(std::cin >> col) || !isValidMove(col))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid move. Try again: ";
        }

        makeMove(col);
        std::cout << toString();
        state = checkGameState();
    }

    if (state == GameState::WIN)
    {
        currentPlayer = currentPlayer == Player::ONE ? Player::TWO : Player::ONE;
        std::cout << "Player " << (currentPlayer == Player::ONE ? "1 (X)" : "2 (O)") << " wins!\n";
    }
    else
    {
        std::cout << "It's a draw!\n";
    }
}