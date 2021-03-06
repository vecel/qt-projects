#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
<<<<<<< HEAD
#include "game.h"

extern Game *game;
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

class Knight: public Piece
{
public:
    Knight(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
<<<<<<< HEAD

private:
    bool isTileFreeToMove(int x, int y); // to make code clearer
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
};

#endif // KNIGHT_H
