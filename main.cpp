#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>

/*
Tutorial Topics:
- QGraphicsScene's sceneRect
- QGraphicsView's sceneRect
- QObject and Q_OBJECT macro
*/

const int WIDTH = 800;
const int HEIGHT = 600;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(0, 0, 100, 100);

    // add the item to the scene
    scene->addItem(player);

    // make rect item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // show the view
    view->show();
    view->setFixedSize(WIDTH, HEIGHT);
    scene->setSceneRect(0,0,WIDTH,HEIGHT);
    player->setPos((view->width() - player->rect().width()) / 2   , (view->height() - player->rect().height())/2);


    return a.exec();
}

/* Only one QGraphicsItem can respond to keyboard events at a time */
