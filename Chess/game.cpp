#include "game.h"
#include <QGraphicsView>
#include "board.h"
#include <QGraphicsSceneMouseEvent>

#include <QDebug>

Game::Game()
{
    setSceneRect(0, 0, 800, 600);

    //create a board
    board = new Board();

    this->addItem(board);

    board->setUpPieces();

    setFocusItem(board);

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

Tile *Game::getTile(int x, int y)
{
    return board->getTile(x, y);
}

Piece *Game::getPiece(int x, int y)
{
    return board->getPiece(x, y);
}

void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // send event to proper item
    QGraphicsScene::mousePressEvent(event);
    qDebug() << "Game: mouseGrabberItem: " << mouseGrabberItem();

    if(mouseGrabberItem() == NULL){
        qDebug() << "Game: mouseGrabberItem NULL";
        // unselect tiles
        unselectTiles();
    }
}

void Game::unselectTiles()
{
    for(int i = 0; i < 8; ++i){
        for(int k = 0; k < 8; ++k){
            board->getTile(i, k)->unselect();
        }
    }
}
