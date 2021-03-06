#include "board.h"
#include "tile.h"
#include "queen.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

Board::Board(int origin_x, int origin_y)
{
    setUpChessboard();
    // set board position to center
    setPos(origin_x, origin_y);
}

Tile *Board::getTile(int x, int y)
{
    return tileBoard[x][y];
}

Piece *Board::getPiece(int x, int y)
{
    return board[x][y];
}

void Board::setUpPieces()
{
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            qDebug() << typeid(board[i][k]).name() << " " << i << " " << k;
        }
    }
    addPiece(new Rook(Piece::WHITE, 0, 7));
    addPiece(new Rook(Piece::WHITE, 7, 7));

    addPiece(new Knight(Piece::WHITE, 1, 7));
    addPiece(new Knight(Piece::WHITE, 6, 7));

    addPiece(new Bishop(Piece::WHITE, 2, 7));
    addPiece(new Bishop(Piece::WHITE, 5, 7));

    addPiece(new King(Piece::WHITE, 4, 7));
    addPiece(new Queen(Piece::WHITE, 3, 7));

    for(int i = 0; i < 8; ++i){
        addPiece(new Pawn(Piece::WHITE, i, 6));
    }

    addPiece(new Rook(Piece::BLACK, 0, 0));
    addPiece(new Rook(Piece::BLACK, 7, 0));

    addPiece(new Knight(Piece::BLACK, 1, 0));
    addPiece(new Knight(Piece::BLACK, 6, 0));

    addPiece(new Bishop(Piece::BLACK, 2, 0));
    addPiece(new Bishop(Piece::BLACK, 5, 0));

    addPiece(new King(Piece::BLACK, 4, 0));
    addPiece(new Queen(Piece::BLACK, 3, 0));

    for(int i = 0; i < 8; ++i){
        addPiece(new Pawn(Piece::BLACK, i, 1));
    }

    // test
    addPiece(new Bishop(Piece::WHITE, 4, 4));
    addPiece(new Rook(Piece::BLACK, 5, 5));
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress){
        int x = (int) event->pos().x() / 64;
        int y = (int) event->pos().y() / 64;

        qDebug() << "Board: tile at: " << x << " " << y;

        // check if chosen tile is selected
        if(getTile(x, y)->isSelected()){
            if(game->getPieceAt(x, y) == nullptr){
                move(game->getSelectedPiece(), x, y);
            } else {
                if(game->getPieceAt(x, y)->getColor() != game->getSelectedPiece()->getColor()){
                    move(game->getSelectedPiece(), x, y);
                } else {
                    // piece at [x,y] has the same color as selectedPiece
                    // such a case may occur only when selectedPiece is a king with right to castling
                    // make a castle
                    castle(x, y);
                }
            }
        }
        game->unselectTiles();
    }
}

void Board::move(Piece *piece, int x, int y)
{
    // set capturedPiece pointer to piece that is on the [x,y] position
    capturedPiece = board[x][y];

    // update pointer from position where piece moves to
    board[x][y] = piece;

    // set pointer from previous position to nullptr, because there is no piece there anymore
    board[piece->board_x][piece->board_y] = nullptr;

    if(!isKingSafe()){
        undoMove(piece, x, y);
    } else {
        delete capturedPiece;
        capturedPiece = nullptr;

        // move the piece
        piece->moveBy(64 * (x - piece->board_x), 64 * (y - piece->board_y));

        // update piece's coordinates
        piece->board_x = x;
        piece->board_y = y;

        // change player turn
        game->changeTurn();

        // forbid castling if rook or king is moved
        if(typeid(*piece) == typeid(Rook) || typeid(*piece) == typeid(King)){
            piece->forbidCastle();
        }
    }
}

void Board::undoMove(Piece *piece, int x, int y)
{
    // set pointer from previous position to piece that was in it
    board[piece->board_x][piece->board_y] = piece;

    board[x][y] = capturedPiece;

    capturedPiece = nullptr;
}

void Board::castle(int x, int y)
{
    // move pressed rook and then king
    // due to calling move() function twice change additionally turn's color
    if(x == 0){
        move(game->getPieceAt(x, y), 3, y);
        game->changeTurn();
        move(game->getSelectedPiece(), 2, y);
    } else if(x == 7) {
        move(game->getPieceAt(x, y), 5, y);
        game->changeTurn();
        move(game->getSelectedPiece(), 6, y);
    } else {
        qDebug() << "Illegal castling!!!";
    }
}

bool Board::isKingSafe()
{
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            if(board[i][k] != nullptr){
                if(typeid (*board[i][k]) == typeid (King)){
                    if(board[i][k]->getColor() == game->getTurn()){
                        qDebug() << i << " / " << k;
                        // check if king is safe
                        if(isAttackedByKnight(i, k)) return false;
                        if(isAttackedDiagonally(i, k)) return false;
                        if(isAttackedInRow(i, k)) return false;
                        if(isAttackedByPawn(i, k)) return false;
                        if(isNextToKing(i, k)) return false;

                        return true;
                    }
                }
            }
        }
    }
    return true;
}

void Board::setUpChessboard()
{
    // set up a chessboard
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            // create new tile, set it's color and add it to the group
            if((i + k) % 2 == 0) tileBoard[k][i] = new Tile(QBrush(Qt::white));
            else tileBoard[k][i] = new Tile(QBrush(Qt::gray));

            tileBoard[k][i]->setPos(64 * k, 64 * i);

            addToGroup(tileBoard[k][i]);
        }
    }
}

void Board::addPiece(Piece *piece)
{
    // set board[x][y] pointer to the piece
    int x = piece->board_x;
    int y = piece->board_y;
    board[x][y] = piece;

    // set piece's position
    int pos_x = this->x() + 64 * x + (64 - piece->boundingRect().width()) / 2;
    int pos_y = this->y() + 64 * y + (64 - piece->boundingRect().height()) / 2;
    piece->setPos(pos_x, pos_y);

    scene()->addItem(piece);
}

bool Board::isAttackedByKnight(int pos_x, int pos_y)
{
    if(isEnemyKnightAt(pos_x - 2, pos_y - 1)) return true;
    if(isEnemyKnightAt(pos_x - 2, pos_y + 1)) return true;
    if(isEnemyKnightAt(pos_x + 2, pos_y - 1)) return true;
    if(isEnemyKnightAt(pos_x + 2, pos_y + 1)) return true;
    if(isEnemyKnightAt(pos_x - 1, pos_y - 2)) return true;
    if(isEnemyKnightAt(pos_x - 1, pos_y + 2)) return true;
    if(isEnemyKnightAt(pos_x + 1, pos_y - 2)) return true;
    if(isEnemyKnightAt(pos_x + 1, pos_y + 2)) return true;
    return false;
}

bool Board::isAttackedDiagonally(int pos_x, int pos_y)
{
    for(int i = pos_x - 1, k = pos_y - 1; i >= 0 && k >= 0; --i, --k){
        if(board[i][k] != nullptr){
            if(board[i][k]->getColor() != game->getTurn()){
                if(typeid (*board[i][k]) == typeid (Bishop) || typeid (*board[i][k]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_x - 1, k = pos_y + 1; i >= 0 && k <= 7; --i, ++k){
        if(board[i][k] != nullptr){
            if(board[i][k]->getColor() != game->getTurn()){
                if(typeid (*board[i][k]) == typeid (Bishop) || typeid (*board[i][k]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_x + 1, k = pos_y - 1; i <= 7 && k >= 0; ++i, --k){
        if(board[i][k] != nullptr){
            if(board[i][k]->getColor() != game->getTurn()){
                if(typeid (*board[i][k]) == typeid (Bishop) || typeid (*board[i][k]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_x + 1, k = pos_y + 1; i <= 7 && k <= 7; ++i, ++k){
        if(board[i][k] != nullptr){
            if(board[i][k]->getColor() != game->getTurn()){
                if(typeid (*board[i][k]) == typeid (Bishop) || typeid (*board[i][k]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    return false;
}

bool Board::isAttackedInRow(int pos_x, int pos_y)
{
    for(int i = pos_x - 1; i >= 0; --i){
        if(board[i][pos_y] != nullptr){
            if(board[i][pos_y]->getColor() != game->getTurn()){
                if(typeid (*board[i][pos_y]) == typeid (Rook) || typeid (*board[i][pos_y]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_x + 1; i <= 7; ++i){
        if(board[i][pos_y] != nullptr){
            if(board[i][pos_y]->getColor() != game->getTurn()){
                if(typeid (*board[i][pos_y]) == typeid (Rook) || typeid (*board[i][pos_y]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_y - 1; i >= 0; --i){
        if(board[pos_x][i] != nullptr){
            if(board[pos_x][i]->getColor() != game->getTurn()){
                if(typeid (*board[pos_x][i]) == typeid (Rook) || typeid (*board[pos_x][i]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    for(int i = pos_y + 1; i <= 7; ++i){
        if(board[pos_x][i] != nullptr){
            if(board[pos_x][i]->getColor() != game->getTurn()){
                if(typeid (*board[pos_x][i]) == typeid (Rook) || typeid (*board[pos_x][i]) == typeid (Queen)) return true;
                else break;
            } else break;
        }
    }
    return false;
}

bool Board::isAttackedByPawn(int pos_x, int pos_y)
{
    if(game->getTurn() == Piece::WHITE){
        if(pos_x - 1 >= 0 && pos_y > 1){
            if(board[pos_x - 1][pos_y - 1] != nullptr){
                if(board[pos_x - 1][pos_y - 1]->getColor() == Piece::BLACK){
                    if(typeid (*board[pos_x - 1][pos_y - 1]) == typeid (Pawn)) return true;
                }
            }
        }
        if(pos_x + 1 <= 7 && pos_y > 1){
            if(board[pos_x + 1][pos_y - 1] != nullptr){
                if(board[pos_x + 1][pos_y - 1]->getColor() == Piece::BLACK){
                    if(typeid (*board[pos_x + 1][pos_y - 1]) == typeid (Pawn)) return true;
                }
            }
        }
    } else {
        if(pos_x - 1 >= 0 && pos_y < 6){
            if(board[pos_x - 1][pos_y + 1] != nullptr){
                if(board[pos_x - 1][pos_y + 1]->getColor() == Piece::WHITE){
                    if(typeid (*board[pos_x - 1][pos_y + 1]) == typeid (Pawn)) return true;
                }
            }
        }
        if(pos_x + 1 <= 7 && pos_y < 6){
            if(board[pos_x + 1][pos_y + 1] != nullptr){
                if(board[pos_x + 1][pos_y + 1]->getColor() == Piece::WHITE){
                    if(typeid (*board[pos_x + 1][pos_y + 1]) == typeid (Pawn)) return true;
                }
            }
        }
    }
    return false;
}

bool Board::isNextToKing(int pos_x, int pos_y)
{
    if(isKingAt(pos_x - 1, pos_y - 1)) return true;
    if(isKingAt(pos_x - 1, pos_y)) return true;
    if(isKingAt(pos_x - 1, pos_y + 1)) return true;
    if(isKingAt(pos_x, pos_y - 1)) return true;
    if(isKingAt(pos_x, pos_y + 1)) return true;
    if(isKingAt(pos_x + 1, pos_y - 1)) return true;
    if(isKingAt(pos_x + 1, pos_y)) return true;
    if(isKingAt(pos_x + 1, pos_y + 1)) return true;
    return false;
}

bool Board::isEnemyKnightAt(int x, int y)
{
    // check if position [x,y] exists at all
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;

    if(board[x][y] != nullptr){
        if(typeid (*board[x][y]) == typeid (Knight)){
            qDebug() << "Knight attacks the king";
            // check the color of found knight
            if(board[x][y]->getColor() != game->getTurn()) return true;
        }
    }
    return false;
}

bool Board::isKingAt(int x, int y)
{
    if(x < 0 || x > 7 || y < 0 || y > 7) return false;

    if(board[x][y] != nullptr){
        if(typeid (*board[x][y]) == typeid (King)) return true;
    }
    return false;
}
