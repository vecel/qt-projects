#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Rook: public Piece
{
public:
    Rook(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
};

#endif // ROOK_H
