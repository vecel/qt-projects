#include "bullet.h"

#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet()
{
    setRect(0, 0, 10, 30);

    // create a timer
    QTimer *timer = new QTimer();

    // connect timer signals to call move() member function
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    setPos(x(), y() - 10);

    // remove the bullet if it's off the scene
    if(y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}



