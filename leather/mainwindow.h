#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void connectSidebar();
    void setActiveButton(QPushButton *active);

    Ui::MainWindow *ui;
    QList<QPushButton*> sidebarButtons;
};

#endif // MAINWINDOW_H
