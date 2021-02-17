#include "board.h"
#include "tile.h"
#include "queen.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

Board::Board(int origin_x, int origin_y)
{
    // set board focusable
    setFlag(GraphicsItemFlag::ItemIsFocusable);

    // set up a chessboard
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            // create new tile and add it to group
            tileBoard[k][i] = new Tile();
            tileBoard[k][i]->setPos(64 * k, 64 * i);
            addToGroup(tileBoard[k][i]);
        }
    }

    // set board position to center
    setPos(origin_x, origin_y);
}

Tile *Board::getTile(int x, int y)
{
    return tileBoard[x][y];
}

void Board::setUpPieces()
{
    addPiece(new Rook(Piece::WHITE, 0, 7));
    addPiece(new Rook(Piece::WHITE, 7, 7));

    addPiece(new Knight(Piece::WHITE, 1, 7));
    addPiece(new Knight(Piece::WHITE, 6, 7));

    addPiece(new Bishop(Piece::WHITE, 2, 7));
    addPiece(new Bishop(Piece::WHITE, 5, 7));

    addPiece(new King(Piece::WHITE, 4, 7));
    addPiece(new Queen(Piece::WHITE, 3, 7));

    for(int i = 0; i < 8; ++i){
        addPiece(new Pawn(Piece::WHITE, i, 6));
    }

    addPiece(new Rook(Piece::BLACK, 0, 0));
    addPiece(new Rook(Piece::BLACK, 7, 0));

    addPiece(new Knight(Piece::BLACK, 1, 0));
    addPiece(new Knight(Piece::BLACK, 6, 0));

    addPiece(new Bishop(Piece::BLACK, 2, 0));
    addPiece(new Bishop(Piece::BLACK, 5, 0));

    addPiece(new King(Piece::BLACK, 4, 0));
    addPiece(new Queen(Piece::BLACK, 3, 0));

    for(int i = 0; i < 8; ++i){
        addPiece(new Pawn(Piece::BLACK, i, 1));
    }
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        qDebug() << "Board: tile at: " << (int) event->pos().x() / 64 << " " << (int) event->pos().y() / 64;
    }
}

Piece *Board::getPiece(int x, int y)
{
    return board[x][y];
}

void Board::addPiece(Piece *piece)
{
    // set board[x][y] pointer to the piece
    int x = piece->board_x;
    int y = piece->board_y;
    board[x][y] = piece;

    // set piece's position
    int pos_x = this->x() + 64 * x + (64 - piece->boundingRect().width()) / 2;
    int pos_y = this->y() + 64 * y + (64 - piece->boundingRect().height()) / 2;
    piece->setPos(pos_x, pos_y);

    scene()->addItem(piece);
}