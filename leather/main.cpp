#include "mainwindow.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont appFont("Segoe UI", 10);
    appFont.setStyleStrategy(QFont::PreferAntialias);
    a.setFont(appFont);

    MainWindow w;
    w.show();
    return a.exec();
}
