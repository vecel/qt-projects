#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "board.h"
#include "piece.h"

class Game: public QGraphicsScene
{
public:
    Game();
    Board * getBoard(); // return pointer to the board that is displayed
    Tile * getTileAt(int x, int y); // return pointer to a tile from [x,y] coordinates
    Piece * getPieceAt(int x, int y); // return pointer to a piece from [x,y] coordinates

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    // set every tile unselected and set selectedPiece to nullptr
    void unselectTiles();

    void setSelectedPiece(Piece *piece); // set selectedPiece pointer to pressed piece
    Piece * getSelectedPiece(); // return selectedPiece pointer

private:
    Board *board; // pointer to a chessboard

    // pointer to the piece that player can move, pressing the piece set it selected
    // selectedPiece can be moved by pressing target tile or a piece on it
    // pressing anywhere else sets selectedPiece to nullptr
    Piece *selectedPiece;
};

#endif // GAME_H
