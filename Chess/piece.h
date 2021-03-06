#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include "tile.h"

#include <QDebug>

class Piece: public QGraphicsPixmapItem
{
public:
    enum COLOR {WHITE = 1, BLACK = 2};

    // return list of tiles which piece can move to
    virtual QList<Tile *> possibleMoves() = 0;

    COLOR getColor(){ return color; } // return piece's color

    // mouse press event for pieces
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // return true if piece is on selected tile, false otherwise
    bool isOnSelectedTile();

    void forbidCastle(); // set rightToCastling false
    bool isAllowedToCastle(); // return rightToCastling

    bool rightToCastling = true; // true if rook or king wasn't moved, false if so

    COLOR color; // color of the piece
    int board_x, board_y; // coordinates on the board

private:
    void setNewSelectedPiece();
};

#endif // PIECE_H
