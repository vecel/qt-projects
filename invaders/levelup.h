#ifndef LEVELUP_H
#define LEVELUP_H

#include <QGraphicsEllipseItem>
#include <QObject>

class LevelUp: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    LevelUp();
};

#endif // LEVELUP_H
