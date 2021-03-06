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
<<<<<<< HEAD
=======
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
};

#endif // PAWN_H
