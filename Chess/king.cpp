#include "king.h"

King::King(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/king_white-40.png"));
    else setPixmap(QPixmap(":/pieces/king_black-41.png"));
}

QList<Tile *> King::possibleMoves()
{
    QList<Tile *> moves;

    return moves;
}
