#include "mainsettingwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSettingWindow w;
    w.show();
    w.showFullScreen();
    return a.exec();
}
