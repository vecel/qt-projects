#include "player.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "bullet.h"

Player::Player()
{
    setRect(0, 0, 100, 100);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "debug";
    if(event->key() == Qt::Key_Left){
        setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y() - 10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y() + 10);
    }
    else if(event->key() == Qt::Key_Space){
        // create a bullet
        if(level == 1){
            Bullet *bullet = new Bullet();
            bullet->setPos(x() + 45, y());
            scene()->addItem(bullet);
        }else if(level == 2){
            Bullet *bullet = new Bullet();
            bullet->setPos(x(), y());
            scene()->addItem(bullet);
            bullet = new Bullet();
            bullet->setPos(x() + 90, y());
            scene()->addItem(bullet);
        }
    }
    else if(event->key() == Qt::Key_Q){
        levelUp();
    }
}

void Player::levelUp()
{
    if(level != 2) level++;
}
