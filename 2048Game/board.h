#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>


class Board : public QGridLayout
{
public:
    Board(int size = 4);
    ~Board();

};

#endif // BOARD_H
