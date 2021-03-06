#include "rook.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Rook::Rook(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/rook_white-33.png"));
    else setPixmap(QPixmap(":/pieces/rook_black-33.png"));
}

QList<Tile *> Rook::possibleMoves()
{
    QList<Tile *> moves;

    for(int i = board_x - 1; i >= 0; --i){
        if(game->getPieceAt(i, board_y) == nullptr) moves.push_back(game->getTileAt(i, board_y));
        else{
            if(game->getPieceAt(i, board_y)->getColor() != this->color) moves.push_back(game->getTileAt(i, board_y));
            break;
        }
    }
    for(int i = board_x + 1; i <= 7; ++i){
        if(game->getPieceAt(i, board_y) == nullptr) moves.push_back(game->getTileAt(i, board_y));
        else{
            if(game->getPieceAt(i, board_y)->getColor() != this->color) moves.push_back(game->getTileAt(i, board_y));
            break;
        }
    }
    for(int i = board_y - 1; i >= 0; --i){
        if(game->getPieceAt(board_x, i) == nullptr) moves.push_back(game->getTileAt(board_x, i));
        else{
            if(game->getPieceAt(board_x, i)->getColor() != this->color) moves.push_back(game->getTileAt(board_x, i));
            break;
        }
    }
    for(int i = board_y + 1; i <= 7; ++i){
        if(game->getPieceAt(board_x, i) == nullptr) moves.push_back(game->getTileAt(board_x, i));
        else{
            if(game->getPieceAt(board_x, i)->getColor() != this->color) moves.push_back(game->getTileAt(board_x, i));
            break;
        }
    }

    return moves;
}
