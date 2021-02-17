#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "bullet.h"
//#include "enemy.h"
#include <ctime>
#include "enemyspawner.h"

int main(int argc, char *argv[])
{
    srand(time(NULL)); // rand() in enemy class

    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // create a player and make it focusable
    Player *player = new Player();

    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // add player to the scene and focus on it
    scene->addItem(player);
    scene->setFocusItem(player);

    // create EnemySpawner
    EnemySpawner *spawner = new EnemySpawner(scene);
    spawner->start();

    // create a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return a.exec();
}
