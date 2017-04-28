#ifndef POINT_H
#define POINT_H

#include <QObject>

class Point
{
public:
    Point();

    Point(QColor* penColor, Qt::PenCapStyle capStyle, int penSize, QPolygon* points);
    Point(QColor* color, int penSize, QPolygon* points);

    //store the pen properties
    Qt::PenCapStyle capStyle;

    /** Line Thickness */
    int penSize;
    QPolygon* getPoints() const;
    QColor* getColor() const;

private:
    //store the vector here
    QPolygon* points;
    QColor* color;

};

#endif // POINT_H
