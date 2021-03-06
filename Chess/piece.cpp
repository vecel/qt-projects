#include "piece.h"
#include <QGraphicsSceneMouseEvent>
#include "king.h"
#include "rook.h"

#include "game.h"

extern Game *game;

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        // if there is no selected piece
        if(game->getSelectedPiece() == nullptr) setNewSelectedPiece();
        else if(game->getSelectedPiece()->getColor() != this->color){

            // capture piece if true, otherwise unselect tiles and set selectedPiece to pressed one
            if(isOnSelectedTile()){
                game->getBoard()->move(game->getSelectedPiece(), this->board_x, this->board_y);
                game->unselectTiles();
            } else{
                setNewSelectedPiece();
            }

        } else {
            // selectedPiece has the same color as pressed piece
            if(typeid (*(game->getSelectedPiece())) == typeid (King) && typeid (*this) == typeid (Rook)){
                game->getBoard()->castle(board_x, board_y);
                game->unselectTiles();
            } else {
                setNewSelectedPiece();
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

void Piece::setNewSelectedPiece()
{
    // unselect tiles if there any are selected
    game->unselectTiles();

    // set this selected piece
    if(this->color == game->getTurn()){
        game->setSelectedPiece(this);

        // get tiles that piece can move to
        QList<Tile *> moves = possibleMoves();

        // select these tiles
        for(int i = 0; i < moves.size(); ++i){
            moves.at(i)->select();
        }
    }
}
