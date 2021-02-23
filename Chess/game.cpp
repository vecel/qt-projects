#include "game.h"
#include <QGraphicsView>
#include "board.h"
#include <QGraphicsSceneMouseEvent>
#include "piece.h"

#include <QDebug>

Game::Game()
{
    setSceneRect(0, 0, 800, 600);

    //create a board
    board = new Board();

    this->addItem(board);

    board->setUpPieces();

    selectedPiece = nullptr;

    // just for test
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            if(board->getPiece(i, k) == nullptr) qDebug() << "nullptr";
        }
    }

    // create a view
    QGraphicsView *view = new QGraphicsView(this);
    view->setFixedSize(800, 600);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
}

Board *Game::getBoard()
{
    return board;
}

Tile *Game::getTileAt(int x, int y)
{
    return board->getTile(x, y);
}

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
