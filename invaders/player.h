#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
//#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    //Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);

private:
    int ammo = 10;
};

#endif // PLAYER_H
