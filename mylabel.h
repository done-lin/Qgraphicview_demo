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
   virtual void mousePressEvent(QMouseEvent *event);// �������� mousePressEvent ������

protected:
   virtual bool event(QEvent *e);// ���� event(������
};

#endif // MYLABEL_H
