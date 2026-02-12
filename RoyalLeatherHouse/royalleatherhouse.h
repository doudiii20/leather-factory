#ifndef ROYALLEATHERHOUSE_H
#define ROYALLEATHERHOUSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RoyalLeatherHouse;
}
QT_END_NAMESPACE

class RoyalLeatherHouse : public QMainWindow
{
    Q_OBJECT

public:
    RoyalLeatherHouse(QWidget *parent = nullptr);
    ~RoyalLeatherHouse();

private:
    Ui::RoyalLeatherHouse *ui;
};
#endif // ROYALLEATHERHOUSE_H
