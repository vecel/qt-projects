#include "pawn.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

Pawn::Pawn(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/pawn_white-30.png"));
    else setPixmap(QPixmap(":/pieces/pawn_black-29.png"));
}

QList<Tile *> Pawn::possibleMoves()
{
    QList<Tile *> tiles;
    if(color == WHITE){
//        tiles.push_back();
//        tiles.push_back();
    }
    return tiles;
}

void Pawn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        qDebug() << "pawn pressed";

        QList<Tile *> tilesToMove = possibleMoves();
        for(int i = 0; i < tilesToMove.size(); ++i){
            tilesToMove.at(i)->selectTile();
        }
    }
    qDebug() << game->mouseGrabberItem();
}
