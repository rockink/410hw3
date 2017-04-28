#ifndef LINE_H
#define LINE_H
#include "undoredostack.h"

#include <QObject>

class Line
{
public:
    Line(QColor* color, Qt::PenStyle lineStyle, Qt::PenCapStyle lineCapStyle, int lineThickness, QLineF* lineVectors);
    Line();

    //store the line properties
    Qt::PenStyle lineStyle;
    Qt::PenCapStyle lineCapStype;
    LineDrawType lineDrawType;



    /** Line Thickness */
    int lineThickness;
    QLineF* getLineVectors() const;
    QColor* getColor() const;


private:
    //store the vector here
    QLineF* lineVectors;
    QColor* color;

};


#endif // LINE_H
