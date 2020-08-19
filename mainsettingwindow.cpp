#include "mainsettingwindow.h"
#include "ui_mainsettingwindow.h"
#include "QImage"
#include <QPixmap>
#include <QSize>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QKeyEvent>
#include "mylabel.h"


MainSettingWindow::MainSettingWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSettingWindow)
{
    ui->setupUi(this);
    //使用qt滚动条显示区域
    ui->scrollAreaWidgetContents->resize(ui->label_4->width()*3, ui->label_3->height()*2); //多加这一行

    myPix = new QGraphicsPixmapItem();//使用QGraphicsItem，载入图片。
    myPix->setPixmap(QPixmap(":/aodi.jpg"));

    myRect = new QGraphicsRectItem();
    myRect->setRect(0, 0, 100, 100);
    myRect->setPos(200, 600);
    gPosTimerCnt = 0;gPosTimerCnt = 1;
    mbuttonList.clear();
    mLabelList.clear();

    QGraphicsScene* scene = new QGraphicsScene();
    scene->addItem(myRect);
    scene->addItem(myPix);

    load_logos();
    init_colors();
    init_labels();

    mLogoSence = new QGraphicsScene();
    mLogoSence->addItem(myPix);
    mLogoSence->addItem(myRect);
    ui->graphicsView->setScene(mLogoSence);
    ui->graphicsView->setAcceptDrops(true);
    baseTimer50ms = new QTimer();
    connect(baseTimer50ms, SIGNAL(timeout()), this, SLOT(slot_timeout_50ms()));
    baseTimer50ms->start(50);
}

MainSettingWindow::~MainSettingWindow()
{
    delete ui;
}

int MainSettingWindow::load_logos()
{
    QPixmap *img=new QPixmap; //新建一个image对象
    img->load(":/fengtian.jpg"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_3->setPixmap(*img);
    ui->label_3->setScaledContents(true);


    img->load(":/aodi.jpg"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_4->setPixmap(*img);
    ui->label_4->setScaledContents(true);


    img->load(":/baoma.jpg"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_5->setPixmap(*img);
    ui->label_5->setScaledContents(true);


    img->load(":/benchi.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_6->setPixmap(*img);
    ui->label_6->setScaledContents(true);


    img->load(":/xuetielong.png"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_7->setPixmap(*img);
    ui->label_7->setScaledContents(true);


    img->load(":/chuanqi.jpg"); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
    img->scaled(QSize(ui->label_3->width(), ui->label_3->height()), Qt::KeepAspectRatio);
    ui->label_8->setPixmap(*img);
    ui->label_8->setScaledContents(true);

}

void MainSettingWindow::init_colors()
{

    mbuttonList.append(ui->pushButton_0);
    mbuttonList.append(ui->pushButton_1);
    mbuttonList.append(ui->pushButton_2);
    mbuttonList.append(ui->pushButton_3);
    mbuttonList.append(ui->pushButton_4);
    mbuttonList.append(ui->pushButton_5);
    mbuttonList.append(ui->pushButton_6);
    mbuttonList.append(ui->pushButton_7);
    mbuttonList.append(ui->pushButton_8);
    mbuttonList.append(ui->pushButton_9);
    mbuttonList.append(ui->pushButton_10);
    mbuttonList.append(ui->pushButton_11);
    mbuttonList.append(ui->pushButton_12);
    mbuttonList.append(ui->pushButton_13);
    mbuttonList.append(ui->pushButton_14);
    mbuttonList.append(ui->pushButton_15);

    QListIterator<QPushButton*> iter(mbuttonList);
    while (iter.hasNext()) {
      QPushButton *pb = iter.next();
      QString tmpColorStr = QString().sprintf("QPushButton{background-color:#%06x}", rand());
      pb->setStyleSheet(tmpColorStr);
    }

}

void MainSettingWindow::init_labels()
{
    mLabelList.append(ui->label_3);
    mLabelList.append(ui->label_4);
    mLabelList.append(ui->label_5);
    mLabelList.append(ui->label_6);
    mLabelList.append(ui->label_7);
    mLabelList.append(ui->label_8);
}

void MainSettingWindow::slot_change_button_random_color()
{
    QListIterator<QPushButton*> iter(mbuttonList);
    while (iter.hasNext()) {
      QPushButton *pb = iter.next();
      QString tmpColorStr = QString().sprintf("QPushButton{background-color:#%06x}", rand());
      pb->setStyleSheet(tmpColorStr);
      pb->update();
      pb->show();
    }
}

void MainSettingWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_A:
        ui->graphicsView->scale(0.5, 0.5);
        break;

    case Qt::Key_S:
        ui->graphicsView->scale(2.0, 2.0);
        break;
    default:
            QWidget::keyPressEvent(e);
        break;
    }
}

void MainSettingWindow::slot_timeout_50ms()
{
    gPosTimerCnt++;
    if(gPosTimerCnt>10){
        gPosTimerCnt = 0;
        myRect->setX(qrand()%600);
        myRect->setY(qrand()%500);

        myPix->setX(qrand()%400);
        myPix->setY(qrand()%300);

        slot_change_button_random_color();
    }

    gScaleCnt++;
    if(gScaleCnt<5){
        ui->graphicsView->scale(4.0f/5.0f, 4.0f/5.0f);
    }else if(gScaleCnt>4 && gScaleCnt<9){
        ui->graphicsView->scale(5.0f/4.0f, 5.0f/4.0f);
    }else{
        gScaleCnt = 0;
    }


}


