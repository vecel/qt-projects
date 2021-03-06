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
<<<<<<< HEAD
    QList<Tile *> moves;
    if(color == WHITE){
        // move up
        if(game->getPieceAt(board_x, board_y - 1) == nullptr){
            moves.push_back(game->getTileAt(board_x, board_y - 1));
            // move two squares if pawn is on its starting position
            if(board_y == 6 && game->getPieceAt(board_x, board_y - 2) == nullptr){
                moves.push_back(game->getTileAt(board_x, board_y - 2));
            }
        }
        // check if capture is possible
        // left
        if(board_x - 1 >= 0){
            if(game->getPieceAt(board_x - 1, board_y - 1) != nullptr){
                if(game->getPieceAt(board_x - 1, board_y - 1)->getColor() != this->color)
                    moves.push_back(game->getTileAt(board_x - 1, board_y - 1));
            }
        }
        // right
        if(board_x + 1 <= 7){
            if(game->getPieceAt(board_x + 1, board_y - 1) != nullptr){
                if(game->getPieceAt(board_x + 1, board_y - 1)->getColor() != this->color)
                    moves.push_back(game->getTileAt(board_x + 1, board_y - 1));
            }
        }
    } else {
        // move down the board
        if(game->getPieceAt(board_x, board_y + 1) == nullptr){
            moves.push_back(game->getTileAt(board_x, board_y + 1));
            // move two squares if pawn is on its starting position
            if(board_y == 1 && game->getPieceAt(board_x, board_y + 2) == nullptr){
                moves.push_back(game->getTileAt(board_x, board_y + 2));
            }
        }
        // check if capture is possible
        // left
        if(board_x - 1 >= 0){
            if(game->getPieceAt(board_x - 1, board_y + 1) != nullptr){
                if(game->getPieceAt(board_x - 1, board_y + 1)->getColor() != this->color)
                    moves.push_back(game->getTileAt(board_x - 1, board_y + 1));
            }
        }
        // right
        if(board_x + 1 <= 7){
            if(game->getPieceAt(board_x + 1, board_y + 1) != nullptr){
                if(game->getPieceAt(board_x + 1, board_y + 1)->getColor() != this->color)
                    moves.push_back(game->getTileAt(board_x + 1, board_y + 1));
            }
        }
    }

    return moves;
=======
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
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
}
