#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include "Constants.h"

class Bitboard
{
public:
    Bitboard();

    // Play a move in a column (assumes column is valid)
    void play(int column);

    // Undo move
    void undo(int column);

    // Returns true if a move in this column is valid
    bool isValidMove(int column) const;

    // Get all valid move columns
    std::vector<int> getValidMoves() const;

    // Returns:
    //  1 - if position is winning for last player that played
    //  0 - if it's not terminal
    static bool checkWin(uint64_t position);

    // Converts to a printable string for debugging
    // std::string toString() const;

    // Construct from ConnectFour (optional, if integrating with GUI/CLI)
    // static Bitboard fromConnectFour(const class ConnectFour& game);
private:
    uint64_t playerMask; // First player moves mask
    uint64_t occupancy;  // All occupied cells
    int currentPlayer;   // 0 if first to move, 1 if second to move
    uint64_t allBottomMask;
    uint64_t allTopMask;

    static constexpr int COL_HEIGHT = Constants::rows + 1; // 6 + 1 sentinel
    static constexpr int WIDTH = Constants::columns;

    // Masks
    static uint64_t topMask(int col);
    static uint64_t bottomMask(int col);
    static uint64_t columnMask(int col);

    // Get current player's bitboard
    // uint64_t currentPosition() const;
};
