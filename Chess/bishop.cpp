#include "bishop.h"
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

Bishop::Bishop(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/bishop_white-42.png"));
    else setPixmap(QPixmap(":/pieces/bishop_black-42.png"));
}

QList<Tile *> Bishop::possibleMoves()
{
    QList<Tile *> moves;

    /* take into account if tile is occupied and color of occupying piece */

    // add diagonal tiles to the list
    // loops provide tiles from each diagonal
    for(int i = board_x - 1, k = board_y - 1; i >= 0 && k >= 0; --i, --k){
        moves.push_back(game->getTile(i, k));
    }
    for(int i = board_x - 1, k = board_y + 1; i >= 0 && k <= 7; --i, ++k){
        moves.push_back(game->getTile(i, k));
    }
    for(int i = board_x + 1, k = board_y - 1; i <= 7 && k >= 0; ++i, --k){
        moves.push_back(game->getTile(i, k));
    }
    for(int i = board_x + 1, k = board_y + 1; i <= 7 && k <= 7; ++i, ++k){
        moves.push_back(game->getTile(i, k));
    }
    return moves;
}

void Bishop::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){

        // get tiles that piece can move to
        QList<Tile *> moves = possibleMoves();

        // paint these tiles
        for(int i = 0; i < moves.size(); ++i){
            moves.at(i)->selectTile();
        }

        // write in the console color of pressed piece color
        qDebug() << this->getColor();
    }
}
