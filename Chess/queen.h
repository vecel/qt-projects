#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen: public Piece
{
public:
    Queen(COLOR col, int x, int y);
    QList<Tile*> possibleMoves();

private:
    //COLOR color;
};

#endif // QUEEN_H
