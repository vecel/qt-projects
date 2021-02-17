#include "rook.h"

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
    return QList<Tile*>();
}
