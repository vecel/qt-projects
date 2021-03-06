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

    // add diagonal tiles to the list
    // loops provide tiles from each diagonal
    // in each loop check if there is no piece at [i,k] add tile to the list
    // otherwise check piece's color.
    // if it has different color than this, add tile to the list
    // break whichever color piece has
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
}

//void Bishop::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if(event->type() == QEvent::GraphicsSceneMousePress){

//        // get tiles that piece can move to
//        QList<Tile *> moves = possibleMoves();

//        // paint these tiles
//        for(int i = 0; i < moves.size(); ++i){
//            moves.at(i)->select();
//        }

//        // write in the console color of pressed piece color
//        qDebug() << this->getColor();
//    }
//    qDebug() << typeid (this).name();
//}
