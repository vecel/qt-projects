#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "board.h"

class Game: public QGraphicsScene
{
public:
    Game();
    Board * getBoard();
    Tile * getTile(int x, int y);
    Piece * getPiece(int x, int y);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    Board *board;
    void unselectTiles();
};

#endif // GAME_H
