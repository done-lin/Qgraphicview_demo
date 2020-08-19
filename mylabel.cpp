#include "mylabel.h"
#include <QMessageBox>

// 重写鼠标点击事件 mousePressEvent()
myLabel::myLabel(QWidget *parent)
{

}

void myLabel::mousePressEvent(QMouseEvent *event)
{
    //Qt::LeftButton
    //Qt::RightButton
    if(event->button()== Qt::LeftButton)
    {
        QMessageBox::information(NULL,tr("click"),tr("mouse clicked!"), QMessageBox::Yes);
    }
}
// 重写鼠标事件处理 event()
bool myLabel::event(QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            QMessageBox::information(NULL,tr("click"),tr("mouse clicked!"), QMessageBox::Yes);
            return true;
        }
    }
    return QLabel::event(e);
}
