#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsItemGroup>
#include "tile.h"
#include "piece.h"

// Board class represents chessboard as group of tiles
// and handle piece's pointers array
class Board: public QGraphicsItemGroup
{
public:
    Board(int origin_x = 144, int origin_y = 44);

    // return tile at x, y coordinates
    Tile *getTile(int x, int y);

    // place pieces to their correct positions
    void setUpPieces();

private:
    Tile *tileBoard[8][8]; // chessboard
    Piece *board[8][8]; // handle pieces pointers

    // place piece on the chessboard
    void addPiece(Piece *piece);
};

#endif // BOARD_H
