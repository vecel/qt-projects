#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "enemy.h"
#include "levelup.h"

Bullet::Bullet()
{
    // set bullet's rect
    setRect(0, 0, 10, 10);

    // create and connect timer to move() slot
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // if there is a collision
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for(int i = 0; i < collidingItemsList.size(); ++i){        
        if(typeid (*(collidingItemsList[i])) == typeid (Enemy)){
            qDebug() << "enemy collision";

            // create an upgrade
            LevelUp *levelUp = new LevelUp();
            levelUp->setPos(collidingItemsList[i]->x() + 10,
                            collidingItemsList[i]->y() + 10);
            scene()->addItem(levelUp);

            // remove both items
            scene()->removeItem(collidingItemsList[i]);
            scene()->removeItem(this);

            delete collidingItemsList[i];
            delete this;

            return;
        }
    }

    // move bullet left
    setPos(x() + 10, y());

    // remove when it reaches end of the scene
    if(x() > 810){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet destroyed";
    }
}
