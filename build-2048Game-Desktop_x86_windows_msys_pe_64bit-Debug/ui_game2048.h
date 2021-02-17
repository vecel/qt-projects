/********************************************************************************
** Form generated from reading UI file 'game2048.ui'
**
** Created by: Qt User Interface Compiler version 6.0.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME2048_H
#define UI_GAME2048_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game2048
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *boardLayout;
    QGraphicsView *tile5;
    QGraphicsView *tile2;
    QGraphicsView *tile9;
    QGraphicsView *tile1;
    QGraphicsView *tile3;
    QGraphicsView *tile4;
    QGraphicsView *tile13;
    QGraphicsView *tile6;
    QGraphicsView *tile11;
    QGraphicsView *tile14;
    QGraphicsView *tile10;
    QGraphicsView *tile15;
    QGraphicsView *tile16;
    QGraphicsView *tile7;
    QGraphicsView *tile8;
    QGraphicsView *tile12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Game2048)
    {
        if (Game2048->objectName().isEmpty())
            Game2048->setObjectName(QString::fromUtf8("Game2048"));
        Game2048->resize(800, 600);
        centralwidget = new QWidget(Game2048);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(200, 70, 363, 363));
        boardLayout = new QGridLayout(gridLayoutWidget);
        boardLayout->setObjectName(QString::fromUtf8("boardLayout"));
        boardLayout->setContentsMargins(0, 0, 0, 0);
        tile5 = new QGraphicsView(gridLayoutWidget);
        tile5->setObjectName(QString::fromUtf8("tile5"));

        boardLayout->addWidget(tile5, 1, 0, 1, 1);

        tile2 = new QGraphicsView(gridLayoutWidget);
        tile2->setObjectName(QString::fromUtf8("tile2"));

        boardLayout->addWidget(tile2, 0, 1, 1, 1);

        tile9 = new QGraphicsView(gridLayoutWidget);
        tile9->setObjectName(QString::fromUtf8("tile9"));

        boardLayout->addWidget(tile9, 2, 0, 1, 1);

        tile1 = new QGraphicsView(gridLayoutWidget);
        tile1->setObjectName(QString::fromUtf8("tile1"));
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        tile1->setBackgroundBrush(brush);
        QBrush brush1(QColor(100, 100, 100, 255));
        brush1.setStyle(Qt::SolidPattern);
        tile1->setForegroundBrush(brush1);

        boardLayout->addWidget(tile1, 0, 0, 1, 1);

        tile3 = new QGraphicsView(gridLayoutWidget);
        tile3->setObjectName(QString::fromUtf8("tile3"));

        boardLayout->addWidget(tile3, 0, 2, 1, 1);

        tile4 = new QGraphicsView(gridLayoutWidget);
        tile4->setObjectName(QString::fromUtf8("tile4"));

        boardLayout->addWidget(tile4, 0, 3, 1, 1);

        tile13 = new QGraphicsView(gridLayoutWidget);
        tile13->setObjectName(QString::fromUtf8("tile13"));

        boardLayout->addWidget(tile13, 3, 0, 1, 1);

        tile6 = new QGraphicsView(gridLayoutWidget);
        tile6->setObjectName(QString::fromUtf8("tile6"));

        boardLayout->addWidget(tile6, 1, 1, 1, 1);

        tile11 = new QGraphicsView(gridLayoutWidget);
        tile11->setObjectName(QString::fromUtf8("tile11"));

        boardLayout->addWidget(tile11, 2, 2, 1, 1);

        tile14 = new QGraphicsView(gridLayoutWidget);
        tile14->setObjectName(QString::fromUtf8("tile14"));

        boardLayout->addWidget(tile14, 3, 1, 1, 1);

        tile10 = new QGraphicsView(gridLayoutWidget);
        tile10->setObjectName(QString::fromUtf8("tile10"));

        boardLayout->addWidget(tile10, 2, 1, 1, 1);

        tile15 = new QGraphicsView(gridLayoutWidget);
        tile15->setObjectName(QString::fromUtf8("tile15"));

        boardLayout->addWidget(tile15, 3, 2, 1, 1);

        tile16 = new QGraphicsView(gridLayoutWidget);
        tile16->setObjectName(QString::fromUtf8("tile16"));

        boardLayout->addWidget(tile16, 3, 3, 1, 1);

        tile7 = new QGraphicsView(gridLayoutWidget);
        tile7->setObjectName(QString::fromUtf8("tile7"));

        boardLayout->addWidget(tile7, 1, 2, 1, 1);

        tile8 = new QGraphicsView(gridLayoutWidget);
        tile8->setObjectName(QString::fromUtf8("tile8"));

        boardLayout->addWidget(tile8, 1, 3, 1, 1);

        tile12 = new QGraphicsView(gridLayoutWidget);
        tile12->setObjectName(QString::fromUtf8("tile12"));

        boardLayout->addWidget(tile12, 2, 3, 1, 1);

        Game2048->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Game2048);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Game2048->setMenuBar(menubar);
        statusbar = new QStatusBar(Game2048);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Game2048->setStatusBar(statusbar);

        retranslateUi(Game2048);

        QMetaObject::connectSlotsByName(Game2048);
    } // setupUi

    void retranslateUi(QMainWindow *Game2048)
    {
        Game2048->setWindowTitle(QCoreApplication::translate("Game2048", "Game2048", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game2048: public Ui_Game2048 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME2048_H
