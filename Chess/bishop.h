#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Bishop: public Piece
{
public:
    Bishop(COLOR col, int x, int y);

    QList<Tile*> possibleMoves();

};

#endif // BISHOP_H
