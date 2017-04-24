#include <iostream>
using namespace std;

#include "my_widget.h"

#include <qfiledialog.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <QMenuBar>
#include <QPixmap>
#include <QMouseEvent>
#include <QLabel>

MyMainWindow::MyMainWindow(QWidget* parent, const char* name)
:QMainWindow(parent)
{

    createMenus();
    initBasics();
}


void MyMainWindow::createMenus(){

    QMenu* file = new QMenu("File", this);
    file->addAction("New image...", this, SLOT(OnNewImage()));
    file->addAction("Load image...", this, SLOT(OnLoadImage()));
    file->addAction("Save image...", this, SLOT(OnSaveImage()));

    menuBar()->addMenu(file);


}


void MyMainWindow::initBasics(){
    label = new QLabel();
    image = new QPixmap();

    lineVectors = new QVector<QLineF>();

    size = QSize(300,300);
    label->setPixmap((*image));
    setFixedSize(size);
    pen = new QPen(Qt::black);
    pen->setWidth(3);

    command = MyCommand::NEW_PAINT;
    blankImage();

}


MyMainWindow::~MyMainWindow()
{
	delete image;
}

void MyMainWindow::paintEvent(QPaintEvent* e)
{
	QPainter paint(this);

    switch (this->command) {
    case NEW_PAINT:
        blankImage();
        break;
    case MOUSE_MOVE_EVENT:
        drawMouseMovePaint(paint);
    case LOAD_NEW_IMAGE:
        paint.drawPixmap(0, menuBar()->height(), (*image));

    default:
        paint.drawPixmap(0, menuBar()->height(), (*image));
        break;
    }


}

void MyMainWindow::drawMouseMovePaint(QPainter& paint){
    std::cout << "draw mouse move apint " << std::endl;

//    lineVectors->append(QLineF(previousPosition, currentPosition));

    polygon << currentPosition;
//    paint.drawLines((*lineVectors));
    paint.setPen((*pen));
    paint.drawPoints(polygon);
}


void MyMainWindow::OnNewImage()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.bmp)"));

    createNewImage(path);
}



/**
 * @brief MyMainWindow::createNewImage
 * Creates a new Image, based on the path location param s
 * @param path is the path here
 */
void MyMainWindow::createNewImage(QString& path){
    if (! path.isNull())
    {
        delete image;
        image = new QPixmap();
        image->load(path);
        command = MyCommand::LOAD_NEW_IMAGE;

    }

    else{

        command = MyCommand::NEW_PAINT;

    }

     this->repaint();

}


//blank image creates a new white background image
void MyMainWindow::blankImage(){


    QPainter paint(this);
    paint.fillRect(rect(), Qt::white);



}



void MyMainWindow::OnSaveImage(){
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "/home",

                                                    tr("Images (*.bmp)"));


    if(image->save("nirmal", "jpg", 100))
        std::cout << filePath.toStdString() << "  saved "  << endl;
    else {

        std::cout << filePath.toStdString() << "  not saved "  << endl;
    }

}


void MyMainWindow::OnLoadImage()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.bmp)"));
	if (! s.isNull())
	{
		image->load(s);
	}

     this->repaint();
}

void MyMainWindow::mousePressEvent(QMouseEvent * e)
{
    //QMessageBox::about( this, "bitmap", "Mouse click event!");
}


void MyMainWindow::mouseMoveEvent(QMouseEvent *event){
    previousPosition = currentPosition;
    currentPosition = event->pos();

    std::cout << "move event " << std::endl;

    command = MyCommand::MOUSE_MOVE_EVENT;
    this->update();

}
