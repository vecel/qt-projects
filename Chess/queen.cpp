#include "queen.h"
<<<<<<< HEAD
#include <QGraphicsSceneMouseEvent>
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
#include <QDebug>

Queen::Queen(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/queen_white-47.png"));
    else setPixmap(QPixmap(":/pieces/queen_black-47.png"));
}

QList<Tile *> Queen::possibleMoves()
{
<<<<<<< HEAD
    QList<Tile *> moves;

    // rook movement
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

    // bishop movement
    for(int i = board_x - 1, k = board_y - 1; i >= 0 && k >= 0; --i, --k){
        if(game->getPieceAt(i, k) == nullptr) moves.push_back(game->getTileAt(i, k));
        else{
            if(game->getPieceAt(i, k)->getColor() != this->color) moves.push_back(game->getTileAt(i, k));
            break;
        }
    }
    for(int i = board_x - 1, k = board_y + 1; i >= 0 && k <= 7; --i, ++k){
        if(game->getPieceAt(i, k) == nullptr) moves.push_back(game->getTileAt(i, k));
        else{
            if(game->getPieceAt(i, k)->getColor() != this->color) moves.push_back(game->getTileAt(i, k));
            break;
        }
    }
    for(int i = board_x + 1, k = board_y - 1; i <= 7 && k >= 0; ++i, --k){
        if(game->getPieceAt(i, k) == nullptr) moves.push_back(game->getTileAt(i, k));
        else{
            if(game->getPieceAt(i, k)->getColor() != this->color) moves.push_back(game->getTileAt(i, k));
            break;
        }
    }
    for(int i = board_x + 1, k = board_y + 1; i <= 7 && k <= 7; ++i, ++k){
        if(game->getPieceAt(i, k) == nullptr) moves.push_back(game->getTileAt(i, k));
        else{
            if(game->getPieceAt(i, k)->getColor() != this->color) moves.push_back(game->getTileAt(i, k));
            break;
        }
    }

    return moves;
=======

>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
}
