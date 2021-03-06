#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Bishop: public Piece
{
public:
    Bishop(COLOR col, int x, int y);

<<<<<<< HEAD
    QList<Tile*> possibleMoves();

=======
    // return a list of tiles that piece can move to
    QList<Tile*> possibleMoves();

    // for the moment paint tiles from possibleMoves() to red
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
};

#endif // BISHOP_H
