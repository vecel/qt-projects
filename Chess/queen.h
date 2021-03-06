#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
<<<<<<< HEAD
#include "game.h"

extern Game *game;
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

class Queen: public Piece
{
public:
    Queen(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
<<<<<<< HEAD
=======

private:
    //COLOR color;
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
};

#endif // QUEEN_H
