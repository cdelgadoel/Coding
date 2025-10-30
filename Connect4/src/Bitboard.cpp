#include "Bitboard.h"

Bitboard::Bitboard()
{
    playerMask = occupancy = 0;
    int currentPlayer = 0;

    allBottomMask = 0;
    for (int i = 0; i < Constants::columns; ++i)
    {
        allBottomMask += 1LL << (COL_HEIGHT * i);
    }
}

void Bitboard::play(int column)
{
    uint64_t move = occupancy + bottomMask(column);
    occupancy |= move;
    if (currentPlayer == 0)
        playerMask |= move & columnMask(column);
    currentPlayer ^= 1;
}

void Bitboard::undo(int column)
{
    currentPlayer ^= 1; // now we have the player that did the move
    uint64_t nextMoveMask = (occupancy & columnMask(column)) + bottomMask(column);
    uint64_t lastMoveMask = nextMoveMask >> 1;
    occupancy ^= lastMoveMask; // toggle bit of last move
    if (currentPlayer == 0)
        playerMask ^= lastMoveMask;
}

bool Bitboard::isValidMove(int column) const
{
    return !(topMask(column) & (occupancy + bottomMask(column)));
}

std::vector<int> Bitboard::getValidMoves() const
{
    std::vector<int> resp;
    uint64_t nextMovesIndicator = occupancy + allBottomMask;
    for (int i = 0; i < Constants::columns; ++i)
    {
        if (!(topMask(i) & nextMovesIndicator))
            resp.push_back(i);
    }
}

bool Bitboard::checkWin(uint64_t playerMask)
{
    // 1 checks vertical winning
    // 7 checks horizontal winning
    // 6 checks downwards diagonal winning
    // 8 check upper diagonal winning
    for (int dir : {1, 7, 6, 8})
    {
        uint64_t twoConnectedMask = playerMask & (playerMask >> dir);
        uint64_t fourConnectedMask = twoConnectedMask & (twoConnectedMask >> (2 * dir));
        if (fourConnectedMask != 0)
            return true;
    }
}

uint64_t Bitboard::bottomMask(int col)
{
    return uint64_t(1) << (col * COL_HEIGHT);
}

uint64_t Bitboard::topMask(int col)
{
    return 1LL << ((col + 1) * COL_HEIGHT - 1);
}

uint64_t Bitboard::columnMask(int col)
{
    // first calculates first column mask, then it shifts it
    // to wherever column
    return ((1LL << COL_HEIGHT) - 1) << (col * COL_HEIGHT);
}
