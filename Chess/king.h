#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece
{
public:
    King(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
};

#endif // KING_H
