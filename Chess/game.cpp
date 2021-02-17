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

    // create a view
    QGraphicsView *view = new QGraphicsView(this);
    view->setFixedSize(800, 600);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    qDebug() << mouseGrabberItem();
}

Board *Game::getBoard()
{
    return board;
}

Tile *Game::getTile(int x, int y)
{
    return board->getTile(x, y);
}

//void Game::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    if(event->type() == QEvent::GraphicsSceneMousePress){

//    }
//    qDebug() << "scene mouse pressed event";
//    qDebug() << mouseGrabberItem();
//}
