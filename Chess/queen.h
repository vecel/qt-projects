#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Queen: public Piece
{
public:
    Queen(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
};

#endif // QUEEN_H
