#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "game.h"

extern Game *game;

class Pawn: public Piece
{
public:
    Pawn(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // PAWN_H
