HEADERS += my_widget.h \
    undoredostack.h \
    myqlinef.h \
    line.h \
    point.h
SOURCES += my_widget.cpp main.cpp \
    undoredostack.cpp \
    myqlinef.cpp \
    line.cpp \
    point.cpp
CONFIG += qt warn_on
CONFIG += debug
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES +=
