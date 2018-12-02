#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

Bullet::Bullet()
{
    // draw the rect
    setRect(0, 0,10,50);

    // connect
    // Set a time, then every time goes to 0, signal will execute.
    // If you connect a slot to a timer, that slot(member function) will be called periodically.
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // move the bullet up (minus is up!)
    setPos(x(), y()-10);

    // check if it's out of the screen
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted!";
    }

}
