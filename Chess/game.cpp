#include "game.h"
#include <QGraphicsView>
#include "board.h"
#include <QGraphicsSceneMouseEvent>
<<<<<<< HEAD
#include "piece.h"
=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d

#include <QDebug>

Game::Game()
{
    setSceneRect(0, 0, 800, 600);

    //create a board
    board = new Board();

    this->addItem(board);

    board->setUpPieces();

<<<<<<< HEAD
    selectedPiece = nullptr;

    turn = Piece::WHITE;

=======
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
    // create a view
    QGraphicsView *view = new QGraphicsView(this);
    view->setFixedSize(800, 600);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
<<<<<<< HEAD
=======

    qDebug() << mouseGrabberItem();
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
}

Board *Game::getBoard()
{
    return board;
}

<<<<<<< HEAD
Tile *Game::getTileAt(int x, int y)
=======
Tile *Game::getTile(int x, int y)
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
{
    return board->getTile(x, y);
}

<<<<<<< HEAD
Piece *Game::getPieceAt(int x, int y)
{
    return board->getPiece(x, y);
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // send event to proper item
    QGraphicsScene::mousePressEvent(event);

    if(mouseGrabberItem() == NULL){
        if(selectedPiece != nullptr){
            unselectTiles();
        }
    }
}

void Game::unselectTiles()
{
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            board->getTile(i, k)->unselect();
        }
    }
    selectedPiece = nullptr;
}

void Game::setSelectedPiece(Piece *piece)
{
    selectedPiece = piece;
}

Piece *Game::getSelectedPiece()
{
    return selectedPiece;
}

void Game::changeTurn()
{
    if(turn == Piece::WHITE) turn = Piece::BLACK;
    else turn = Piece::WHITE;
}

Piece::COLOR Game::getTurn()
{
    return turn;
}
=======
//void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if(event->type() == QEvent::GraphicsSceneMousePress){

//    }
//    qDebug() << "scene mouse pressed event";
//    qDebug() << mouseGrabberItem();
//}
>>>>>>> b0bc44a16b9cf6f07934d9f2d421a0f6c088a58d
