#include "piece.h"
#include <QGraphicsSceneMouseEvent>

#include "game.h"

extern Game *game;

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        // if there is no selected piece
        if(game->getSelectedPiece() == nullptr){

            // set this selected piece
            game->setSelectedPiece(this);

            // get tiles that piece can move to
            QList<Tile *> moves = possibleMoves();

            // select these tiles
            for(int i = 0; i < moves.size(); ++i){
                moves.at(i)->select();
            }
        } else {
            // capture piece if true, otherwise unselect tiles and set selectedPiece to pressed one
            if(isOnSelectedTile()){
                game->getBoard()->move(game->getSelectedPiece(), this->board_x, this->board_y);
                game->unselectTiles();
            } else {
                game->unselectTiles();
                game->setSelectedPiece(this);

                QList<Tile *> moves = possibleMoves();

                for(int i = 0; i < moves.size(); ++i){
                    moves.at(i)->select();
                }
            }
        }
    }
}

bool Piece::isOnSelectedTile()
{
    if(game->getTileAt(this->board_x, this->board_y)->isSelected()) return true;
    return false;
}

void Piece::forbidCastle()
{
    rightToCastling = false;
}

bool Piece::isAllowedToCastle()
{
    return rightToCastling;
}
