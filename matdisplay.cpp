#include "matdisplay.h"

matDisplay::matDisplay(QWidget* parent): QLabel(parent)
{

}

matDisplay::~matDisplay()
{

}

void matDisplay::MouseMoveEvent(QMouseEvent *mouse_event){
    QPoint mouse_pos = mouse_event->pos();

    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
        if(mouse_pos.x() > 0 && mouse_pos.y() > 0){
            emit sendMousePosition(mouse_pos);
        }
    }
}
