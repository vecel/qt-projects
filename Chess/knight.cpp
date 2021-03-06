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
    QList<Tile *> moves;

    if(isTileFreeToMove(board_x - 2, board_y - 1)) moves.push_back(game->getTileAt(board_x - 2, board_y - 1));
    if(isTileFreeToMove(board_x - 2, board_y + 1)) moves.push_back(game->getTileAt(board_x - 2, board_y + 1));
    if(isTileFreeToMove(board_x + 2, board_y - 1)) moves.push_back(game->getTileAt(board_x + 2, board_y - 1));
    if(isTileFreeToMove(board_x + 2, board_y + 1)) moves.push_back(game->getTileAt(board_x + 2, board_y + 1));
    if(isTileFreeToMove(board_x - 1, board_y - 2)) moves.push_back(game->getTileAt(board_x - 1, board_y - 2));
    if(isTileFreeToMove(board_x - 1, board_y + 2)) moves.push_back(game->getTileAt(board_x - 1, board_y + 2));
    if(isTileFreeToMove(board_x + 1, board_y - 2)) moves.push_back(game->getTileAt(board_x + 1, board_y - 2));
    if(isTileFreeToMove(board_x + 1, board_y + 2)) moves.push_back(game->getTileAt(board_x + 1, board_y + 2));

    return moves;
}

bool Knight::isTileFreeToMove(int x, int y)
{
    // return false if tile is off the board
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;

    if(game->getPieceAt(x, y) == nullptr) return true;
    else if(game->getPieceAt(x, y)->getColor() != this->color) return true;
    return false;
}
