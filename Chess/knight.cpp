#include "knight.h"

Knight::Knight(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/knight_white-40.png"));
    else setPixmap(QPixmap(":/pieces/knight_black-40.png"));
}

QList<Tile *> Knight::possibleMoves()
{
    QList<Tile *> moves;

    int x, y;

    if(board_x - 2 >= 0 && board_y - 1 >= 0){
        x = board_x - 2;
        y = board_y - 1;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_x - 2 >= 0 && board_y + 1 <= 7){
        x = board_x - 2;
        y = board_y + 1;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_x + 2 <= 7 && board_y - 1 >= 0){
        x = board_x + 2;
        y = board_y - 1;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_x + 2 <= 7 && board_y + 1 <= 7){
        x = board_x + 2;
        y = board_y + 1;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_y - 2 >= 0 && board_x - 1 >= 0){
        x = board_x - 1;
        y = board_y - 2;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_y - 2 >= 0 && board_x + 1 <= 7){
        x = board_x + 1;
        y = board_y - 2;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_y + 2 <= 7 && board_x - 1 >= 0){
        x = board_x - 1;
        y = board_y + 2;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }
    if(board_y + 2 <= 7 && board_x + 1 <= 7){
        x = board_x + 1;
        y = board_y + 2;
        if(game->getPieceAt(x, y) == nullptr) moves.push_back(game->getTileAt(x, y));
        else if(game->getPieceAt(x, y)->getColor() != this->color) moves.push_back(game->getTileAt(x, y));
    }

    return moves;
}
