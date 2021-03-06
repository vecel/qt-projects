#include "king.h"
<<<<<<< HEAD
#include "rook.h"
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

King::King(COLOR col, int x, int y)
{
    // set piece's properties
    color = col;
    board_x = x;
    board_y = y;

    // set graphics
    if(color == WHITE) setPixmap(QPixmap(":/pieces/king_white-40.png"));
    else setPixmap(QPixmap(":/pieces/king_black-41.png"));
}

QList<Tile *> King::possibleMoves()
{
<<<<<<< HEAD
    QList<Tile *> moves;

    if(isTileFreeToMove(board_x - 1, board_y - 1)) moves.push_back(game->getTileAt(board_x - 1, board_y - 1));
    if(isTileFreeToMove(board_x, board_y - 1)) moves.push_back(game->getTileAt(board_x, board_y - 1));
    if(isTileFreeToMove(board_x + 1, board_y - 1)) moves.push_back(game->getTileAt(board_x + 1, board_y - 1));
    if(isTileFreeToMove(board_x - 1, board_y)) moves.push_back(game->getTileAt(board_x - 1, board_y));
    if(isTileFreeToMove(board_x + 1, board_y)) moves.push_back(game->getTileAt(board_x + 1, board_y));
    if(isTileFreeToMove(board_x - 1, board_y + 1)) moves.push_back(game->getTileAt(board_x - 1, board_y + 1));
    if(isTileFreeToMove(board_x, board_y + 1)) moves.push_back(game->getTileAt(board_x, board_y + 1));
    if(isTileFreeToMove(board_x + 1, board_y + 1)) moves.push_back(game->getTileAt(board_x + 1, board_y + 1));

    // castling
    bool castle = true;

    if(rightToCastling){
        // queen side castle
        if(game->getPieceAt(0, board_y) != nullptr){
            if(typeid(*(game->getPieceAt(0, board_y))) == typeid(Rook) && game->getPieceAt(0, board_y)->isAllowedToCastle()){
                for(int i = 3; i > 0; --i){
                    if(game->getPieceAt(i, board_y) != nullptr) castle = false;
                }
                if(castle) moves.push_back(game->getTileAt(0, board_y));
            }
        }
        // king side caslte
        castle = true;
        if(game->getPieceAt(7, board_y) != nullptr){
            if(typeid(*(game->getPieceAt(7, board_y))) == typeid(Rook) && game->getPieceAt(7, board_y)->isAllowedToCastle()){
                for(int i = 5; i < 7; ++i){
                    if(game->getPieceAt(i, board_y) != nullptr) castle = false;
                }
                if(castle) moves.push_back(game->getTileAt(7, board_y));
            }
        }
    }

    return moves;
}

bool King::isTileFreeToMove(int x, int y)
{
    // return false if tile is off the board
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;

    if(game->getPieceAt(x, y) == nullptr) return true;
    else if(game->getPieceAt(x, y)->getColor() != this->color) return true;
    return false;
=======

>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
}
