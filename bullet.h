#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Bullet();
/* signals & slots
 * DEFINITION
 *  signal   :  the signal that you know
 *  slots    :  member function supposed to react to a specific signal.
 *              unlike other member function, put it onto public slots: instead of just public:
 * INCLUDES
 *  1. If you want to use slots and signals, you have to include <QObject> and,
 *     any class that uses signals and slots have to derived from QObject.
 *  2. Add Q_OBJECT macro in the class.
 *     When you adding Q_OBJECT, You have to run [Build-Run qmake]
 */
public slots:
    void move();

};

#endif // BULLET_H
