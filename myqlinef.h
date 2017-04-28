#ifndef MYQLINEF_H
#define MYQLINEF_H
#include <QLineF>

class MyQLineF : public QLineF
{
public:
    MyQLineF(QPointF& f1, QPointF& f2, Qt::PenCapStyle p, Qt::PenStyle q, int r):QLineF(f1, f2){
          this->penCapStyle = p;
        this->penStyle = q;
        this->lineThickness = r;


    }

    MyQLineF() : QLineF(){

    }

    MyQLineF(const QLine &line):QLineF(line){
    }

    MyQLineF(qreal x1, qreal x2, qreal x3, qreal x4):
        QLineF(x1, x2, x3, x4){
    }

    MyQLineF(const QPoint &pt1, const QPoint &pt2):
        QLineF(pt1, pt2){
    }


    Qt::PenCapStyle penCapStyle;
    Qt::PenStyle penStyle;
    int lineThickness;
};

#endif // MYQLINEF_H
