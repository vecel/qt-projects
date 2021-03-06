#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
<<<<<<< HEAD
#include "game.h"

extern Game *game;
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

class Rook: public Piece
{
public:
    Rook(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
};

#endif // ROOK_H
