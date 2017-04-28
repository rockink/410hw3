#ifndef UNDOREDOSTACK_H
#define UNDOREDOSTACK_H

#include <QLinkedList>

enum MyCommand {
    NEW_PAINT, MOUSE_MOVE_EVENT, LOAD_NEW_IMAGE, IMAGE_LOADED
};

enum DrawType {
    DRAW_POINT, DRAW_LINE, ERASER, NULL_DRAW
};


enum LineStyle {
    SOLID_LINE, DASHED_LINE, DOTTED_LINE, DASHED_DOTTED_LINE, DASH_DOT_DOTTED_LINE, NULL_LINE
};

enum LineCapStyle {
    FLAT_CAP, SQUARE_CAP, ROUND_CAP
};

enum LineDrawType {
    SINGLE, POLY
};


class UndoRedoStack
{
public:
    UndoRedoStack();
    void addToUndo(DrawType&);
    DrawType doUndo();
    DrawType doRedo();
    ~UndoRedoStack();
    void clear();

private:
    QLinkedList<DrawType> undoStack;
    QLinkedList<DrawType> redoStack;
    int capacity;

};


#endif // UNDOREDOSTACK_H
