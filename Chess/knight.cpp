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

}
