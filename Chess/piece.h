#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include "tile.h"

class Piece: public QGraphicsPixmapItem
{
public:
    enum COLOR {WHITE = 1, BLACK = 2};
    virtual QList<Tile *> possibleMoves() = 0;
    COLOR getColor()
    {
        return color;
    }

    COLOR color; // color of the piece
    int board_x, board_y; // coordinates on the board
};

#endif // PIECE_H
