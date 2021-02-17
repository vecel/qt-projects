#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight: public Piece
{
public:
    Knight(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
};

#endif // KNIGHT_H
