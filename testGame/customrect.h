#ifndef CUSTOMRECT_H
#define CUSTOMRECT_H

#include <QGraphicsRectItem>

class CustomRect: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent *event); // member func from QGraphicsItem
};

#endif // CUSTOMRECT_H
