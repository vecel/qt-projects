#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>

Player::Player()
{
    setRect(0, 0, 80, 80);  
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Down){
        if(pos().y() < 520) setPos(x(), y() + 20);
    }
    if(event->key() == Qt::Key_Up){
        if(pos().y() > 0) setPos(x(), y() - 20);
    }
    if(event->key() == Qt::Key_Right){
        if(pos().x() < 720) setPos(x() + 20, y());
    }
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0) setPos(x() - 20, y());
    }
    if(event->key() == Qt::Key_Space){
        if(ammo > 0){
            // create bullet(s)
            Bullet *bullet = new Bullet();
            bullet->setPos(x() + 80, y() + 35);
            scene()->addItem(bullet);
            ammo--;
        }
        else{
            qDebug() << "Out of ammo!";
        }
    }
}
