#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>

/*
Tutorial Topics:
- QTimer
- signals and slots (connect function)
- QObject and Q_OBJECT macro
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect *rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(rect);

    // make rect item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();

    return a.exec();
}

/* Only one QGraphicsItem can respond to keyboard events at a time */
