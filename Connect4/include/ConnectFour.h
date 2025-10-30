#pragma once
#include <array>
#include <string>
#include "math2DVector.h"
#include "Constants.h"

class ConnectFour
{
public:
    enum class GameState
    {
        ONGOING,
        WIN,
        DRAW
    };
    ConnectFour();
    void resetGame();
    void play(int col);
    std::string toString() const;
    void start();

private:
    enum class Player
    {
        ONE = 0,
        TWO = 1
    };

    std::array<std::array<char, Constants::columns>, Constants::rows> board;
    std::array<int, Constants::columns> nextAvailableRow;
    Player currentPlayer;
    math2DVector lastMove;

    bool isValidMove(int col) const;
    void makeMove(int col);
    GameState checkGameState() const;
    int countInDirection(const math2DVector &direction) const;
    bool isWithinBounds(const math2DVector &point) const;
    char getCurrentSymbol() const;
};