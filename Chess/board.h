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
    void move(Piece *piece, int x, int y);

    // undo move that was made, called when king isn't safe after making a move
    void undoMove(Piece *piece, int x, int y);

    // make castle
    void castle(int x, int y);

    // check if player's king is safe after making a move
    bool isKingSafe();

private:
    Tile *tileBoard[8][8]; // chessboard
    Piece *board[8][8]; // handle pieces pointers

    // pointer to piece that was captured, used in undoMove function, set in move function
    Piece *capturedPiece = nullptr;

    // set up chessboard
    void setUpChessboard();

    // place piece on the chessboard
    void addPiece(Piece *piece);

    // check wheter the king from [x,y] position is attacked by a knight, used in isKingSafe() function
    bool isAttackedByKnight(int pos_x, int pos_y);

    // check wheter the king from [x,y] position is attacked diagonally, used in isKingSafe() function
    bool isAttackedDiagonally(int pos_x, int pos_y);

    // check wheter the king from [x,y] position is attacked in a row or column, used in isKingSafe() function
    bool isAttackedInRow(int pos_x, int pos_y);

    // check wheter the king from [x,y] position is attacked by a pawn, used in isKingSafe() function
    bool isAttackedByPawn(int pos_x, int pos_y);

    // check wheter the king from [x,y] position is next to the other king, used in isKingSafe() function
    bool isNextToKing(int pos_x, int pos_y);

    // check if there is an enemy knight at [x,y] position if that position exists at all
    // used in isAttackedByKnight() function
    bool isEnemyKnightAt(int x, int y);

    // check if there is a king at [x,y] position if that position exists at all, used in isNextToKing() function
    bool isKingAt(int x, int y);
};

#endif // BOARD_H
