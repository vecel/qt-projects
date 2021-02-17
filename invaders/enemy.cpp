#include "enemy.h"
#include <QGraphicsScene>
#include <QDebug>
#include <cstdlib> // rand()
#include <QTimer>

Enemy::Enemy()
{
    qDebug() << "enemy spawned";
    setRect(0, 0, 70, 70);

    // set random position
    int random = rand() % 530;
    setPos(730, random);

    // create timer and connect to move() slot
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(100);
}

void Enemy::move()
{
    setPos(x() - 5, y());

    // remove enemy when reaches left side of scene
    if(x() + 70 < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy removed";
    }
}
