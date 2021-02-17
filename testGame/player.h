#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player: public QGraphicsRectItem
{
public:
    Player();
    void keyPressEvent(QKeyEvent *event); // member func from QGraphicsItem
    void levelUp();
private:
    int level = 1;
};

#endif // PLAYER_H
