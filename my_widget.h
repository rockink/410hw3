#include <qmainwindow.h>
#include <qmessagebox.h>
//#include <qpopupmenu.h>
#include <QMenu>
#include <qmenubar.h>
#include <qapplication.h>
#include <qpixmap.h>
#include "undoredostack.h"
#include <QStack>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QSlider>
#include "myqlinef.h"
#include "line.h"
#include "point.h"

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

    void mouseReleaseEvent(QMouseEvent *event) override;

	public slots:
	void OnLoadImage();
    void OnNewImage();
    void OnSaveImage();

    /** Color Selection */
    void OnForegroundColorSelectOptionClicked(bool);
    void OnBackgroundColorSelectOptionClicked(bool);

    //draw commands
    void drawLine(QPainter&, bool temp = true);
    void drawPoint(QPainter&, bool temp = true);
    void erasePoint(QPainter&, bool temp = true);


    //options
    void OnLineOptionClicked(bool);
    void OnPolygonOptionClicked(bool);
    void OnEraserOptionClicked(bool);
    void OnClearBoardOptionClicked(bool);
    void OnUndoOptionClicked(bool);
    void OnRedoOptionClicked(bool);


    //settings slots :)))
    void OnLineSettingsClicked();
    void OnPenSettingsClicked();
    void OnEraserSettingsClicked();
    void OnRectangleSettingsClicked();


    /** line Settings */
    void OnLineStyleSelectedSlot(int);
    void OnCapStyleSelected(int);
    void OnLineDrawTypeSelected(int);
    void OnLineThickness(int);

    /** Pen Settings */
    void OnPenSizeChanged(int val);

    /** Rectangle slots */
    void OnRectangeLineSizeChanged(int);
    void OnRectangleCurveSliderChanged(int);

    /** Eraser Slots */
    void OnEraserSizeChanged(int);


	private:

    QPixmap* image;
    QSize size;
    QPen* pen;

    /** Point positions */
    QPoint currentPosition;
    QPoint previousPosition;
    QPoint startingPosition;

    /** Eraser Pen... I Don't think its being used  */
    QPen* eraserPen;

    /** Background */
//    Qt::GlobalColor backgroundColor;
    QColor* backgroundColor;
    QColor* foregroundColor;


    /** Rectangles */
    int rectangleCurveSize;
    int rectangleLineSize;

    /** Lines  properties*/
    int lineThickness;
    Qt::PenStyle lineStyle;
    Qt::PenCapStyle lineCapStype;
    LineDrawType lineDrawType;

    /** Eraser properties */
    int eraserSize;


    /** Dialogs */
    QDialog* lineSettingDialog;
    QDialog* penSettingDialog;
    QDialog* rectangleDialog;
    QDialog* eraserDialog;

    /** ENUMS */
    MyCommand command;
    DrawType drawType;



    /** Pen DataStruct */
    //store the pen properties
    Qt::PenCapStyle penCapStyle;
    int penSize;



    /** Temporary data Structs */
    QLineF *tempLine;
    QPolygon* tempPolygon;
    QPolygon* tempErasedPoints;
    QRect* tempRectangle;


    /** Line DataStruct */
    QVector<Line> *savedLineVectors;

    /** Persisting data Structs */
    QVector<Point> savedPolygon;
    QVector<Point> savedErasedPoints;

    UndoRedoStack undoRedoStack;



    /**
     *
     * These when user clicks undo, it will be populated with what the
     * user has recently done, eg, if user drew line, line would be undoed!
     * when erased is undooed, it will stack up with undooed
     * when points is undooed, it will stack up in undoPoints
     *
     */
    QStack<Line> undidLineVectors;
    QStack<Point> undidErasedPoints;
    QStack<Point> undidPoints;

    QLabel *label;


    /** Helper for state maintenance */
    bool rightClicked;

    void createMenus();
    void initBasics();
    QPixmap createDefaultPixelMap();

    void createNewImage(QString& s);
    void blankImage();

    /** Reset functions */
    void resetTemporaries();
    void resetEverything();
    void resetSavedStates();

    void drawMouseMovePaint(QPainter& paint);

    /** Dialogs */
    void initDialogs();
    void initLineSettingDialog(QDialog *dialog);
    void initPenSettingDialog(QDialog* dialog);
    void initRectangleDialog(QDialog* dialog);
    void initEraserDialog(QDialog* dialog);

    /** Dialog creation Helpers */
    void populateCapStyleLayout(QBoxLayout *parent, QDialog* dialog);
    void populatePenSizeLayout(QBoxLayout *parent, QDialog* dialog);

    /** rectangle populators */
    void populateRectBoundaryStyleLayout(QBoxLayout* parent, QDialog* dialog);
    void populateRectRightTopLayout(QBoxLayout* parent, QDialog* dialog);
    void populateRectangleTopLayout(QBoxLayout* parentLayout, QDialog* dialog);
    void populateRectangleBottomLayout(QVBoxLayout* parentLayout, QDialog* dialog);

    /** line layout helpers */
    void createLineStylesInVerticalLayout(QBoxLayout*, QDialog*);
    void createCapStyleVerticalLayout(QBoxLayout* verticalLayout, QDialog* dialog);
    void createLineThicknessInLayout(QBoxLayout* parentLayout, QDialog* dialog);

    /** Eraser dialog helpers here */



    /** Helper for everyone!! */
    void addButton(QLayout* vLayout, QButtonGroup* buttonGroup, QRadioButton* button);


};


#endif
