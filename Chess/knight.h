#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Knight: public Piece
{
public:
    Knight(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();

private:
    bool isTileFreeToMove(int x, int y); // to make code clearer
};

#endif // KNIGHT_H
