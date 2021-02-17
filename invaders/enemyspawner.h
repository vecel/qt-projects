#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QObject>
#include <QGraphicsScene>

class EnemySpawner: public QObject
{
    Q_OBJECT
public:
    EnemySpawner(QGraphicsScene *scene);
    void start();

public slots:
    void spawn();

private:
    QGraphicsScene *scene;
};

#endif // ENEMYSPAWNER_H
