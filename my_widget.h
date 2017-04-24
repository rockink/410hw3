#include <qmainwindow.h>
#include <qmessagebox.h>
//#include <qpopupmenu.h>
#include <QMenu>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpixmap.h>

#ifndef _MY_WIDGET_H
#define _MY_WIDGET_H

class MyMainWindow: public QMainWindow {
	// All classes that contain signals or slots
	// must mention Q_OBJECT in their declaration.
	Q_OBJECT

	public:
	MyMainWindow(QWidget* parent = 0, const char* name = 0);
	~MyMainWindow();

	/** mouse event handler */
	void mousePressEvent (QMouseEvent *);

	/** paint handler */
	void paintEvent(QPaintEvent *);

    void mouseMoveEvent(QMouseEvent *event);

	public slots:
	void OnLoadImage();
    void OnNewImage();
    void OnSaveImage();


	private:
    enum MyCommand {
        NEW_PAINT, MOUSE_MOVE_EVENT, LOAD_NEW_IMAGE
    };


    QPixmap* image;
    QSize size;
    QPen* pen;
    QPoint currentPosition;
    QPoint previousPosition;
    MyCommand command;
    QVector<QLineF> *lineVectors;

    QPolygon polygon;

    QLabel *label;



    void createMenus();
    void initBasics();
    QPixmap createDefaultPixelMap();

    void createNewImage(QString& s);
    void blankImage();

    void drawMouseMovePaint(QPainter& paint);

};

#endif
