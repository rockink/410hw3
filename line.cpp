#include "line.h"
#include <QVector>
#include <QLineF>

Line::Line(QColor *color, Qt::PenStyle lineStyle, Qt::PenCapStyle lineCapStyle, int lineThickness, QLineF* lineVectors)
{
    this->lineStyle = lineStyle;
    this->lineCapStype = lineCapStyle;
    this->lineThickness = lineThickness;
    this->lineVectors = lineVectors;
    this->color = color;

}

Line::Line(){

}

QLineF* Line::getLineVectors() const {
    return lineVectors;
}

QColor* Line::getColor() const {
    return color;
}
