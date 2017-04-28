#include "point.h"
#include <QPolygon>

Point::Point()
{

}

Point::Point(QColor* color, Qt::PenCapStyle capStyle, int penSize, QPolygon* points){
    this->capStyle = capStyle;
    this->penSize = penSize;
    this->points = points;
    this->color = color;
}


QPolygon* Point::getPoints() const{
    return points;
}

QColor* Point::getColor() const {
    return color;
}


Point::Point(QColor* color, int penSize, QPolygon* points){
    this->penSize = penSize;
    this->capStyle = Qt::RoundCap;
    this->points = points;
    this->color = color;

}
