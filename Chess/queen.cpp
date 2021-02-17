#include "queen.h"
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

}
