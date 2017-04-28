#include "undoredostack.h"

/**
 * @brief UndoRedoStack::UndoRedoStack
 * Construction actually doesn't need to do anything.
 */
UndoRedoStack::UndoRedoStack()
{    
    capacity = 50;
}


/**
 * @brief UndoRedoStack::addToUndo
 * @param type
 * This involves adding the latest drawtype into the stack
 */
void UndoRedoStack::addToUndo(DrawType &type){
    int itemCount = undoStack.size();

    //remove the oldest item in the count
    if(itemCount >= capacity)
        undoStack.removeFirst();

    capacity++;

    //add it to the stack here!!
    undoStack.append(type);
}


/**
 * @brief UndoRedoStack::doRedo
 * @return the undo Element
 * This involves removing the newly added(last) elem from redoStack, and again adding to the undoStack
 */
DrawType UndoRedoStack::doRedo(){

    if(redoStack.size() == 0){
        return NULL_DRAW;
    }

    addToUndo(redoStack.last());


    redoStack.removeLast();;
    return undoStack.last();
}




/**
 * @brief UndoRedoStack::doUndo
 * @return
 * This involves removing undo's last elem and adding to the redo
 */
DrawType UndoRedoStack::doUndo(){
    int itemCount = undoStack.size();

    if(itemCount == 0)
        return DrawType::NULL_DRAW;


    //if the elem is too old, remove the first elem in the stack
    if(itemCount >= capacity)
        redoStack.removeFirst();

    //append and then return the elem
    redoStack.append(undoStack.last());
    undoStack.removeLast();
    return redoStack.last();

}

void UndoRedoStack::clear(){
    redoStack.clear();
    undoStack.clear();
}


UndoRedoStack::~UndoRedoStack(){
//    delete redoStack;
//    delete undoStack;
}
