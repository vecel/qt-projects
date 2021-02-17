#include "enemyspawner.h"
#include <QTimer>
#include "enemy.h"
#include <QGraphicsScene>

EnemySpawner::EnemySpawner(QGraphicsScene *scene)
{
    this->scene = scene;
}

void EnemySpawner::start()
{
    // create a timer and connect to spawn() slot
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(1500);
}

void EnemySpawner::spawn()
{
    // spawn an enemy
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
}

