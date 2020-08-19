#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = 0);

protected:
   virtual void mousePressEvent(QMouseEvent *event);// 重新声明 mousePressEvent 处理函数

protected:
   virtual bool event(QEvent *e);// 声明 event(）函数
};

#endif // MYLABEL_H
