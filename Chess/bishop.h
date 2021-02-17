#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Bishop: public Piece
{
public:
    Bishop(COLOR col, int x, int y);

    // return a list of tiles that piece can move to
    QList<Tile*> possibleMoves();

    // for the moment paint tiles from possibleMoves() to red
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BISHOP_H
