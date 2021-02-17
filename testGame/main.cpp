#include <QApplication>
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene(0, 0, 800, 600);

    // create a player
    Player *player = new Player();

    scene->addItem(player);

    // make item focusable and focus on it
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // set player position
    player->setPos(scene->width() / 2 - player->rect().width() / 2,
                   scene->height() - player->rect().height());

    // create a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return a.exec();
}
