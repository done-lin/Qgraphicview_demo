#ifndef MAINSETTINGWINDOW_H
#define MAINSETTINGWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QTimer>
#include <QLabel>
#include <QList>
#include "mylabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainSettingWindow; }
QT_END_NAMESPACE

class MainSettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainSettingWindow(QWidget *parent = nullptr);
    ~MainSettingWindow();

    int load_logos(void);
    void init_colors(void);
    void init_labels(void);

public slots:
    void slot_timeout_50ms(void);
    void slot_change_button_random_color(void);
protected:
    void keyPressEvent(QKeyEvent * e);

private:
    QList<QPushButton*> mbuttonList;
    QList<QLabel*> mLabelList;
    int gPosTimerCnt;
    int gScaleCnt;
    QTimer* baseTimer50ms;
    QGraphicsScene *mLogoSence;
    QGraphicsItem *mPicItem[256];
    QGraphicsRectItem* myRect;
    QGraphicsPixmapItem* myPix;

    Ui::MainSettingWindow *ui;
};
#endif // MAINSETTINGWINDOW_H
