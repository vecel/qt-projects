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

    Tile *getTile(int x, int y); // return tile from [x,y] coordinates
    Piece * getPiece(int x, int y); // return piece from [x,y] coordinates

    // place pieces to their correct positions
    void setUpPieces();

    // mouse press event for board and its tiles
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // move the piece to x,y destination coordinates
    void move(Piece* piece, int x, int y);

private:
    Tile *tileBoard[8][8]; // chessboard
    Piece *board[8][8]; // handle pieces pointers

    // place piece on the chessboard
    void addPiece(Piece *piece);
};

#endif // BOARD_H
