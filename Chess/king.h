#ifndef KING_H
#define KING_H

#include "piece.h"
#include "game.h"

extern Game *game;

class King: public Piece
{
public:
    King(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();

private:
    bool isTileFreeToMove(int x, int y); // to make code clearer
};

#endif // KING_H
