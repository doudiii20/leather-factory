#include "royalleatherhouse.h"
#include "ui_royalleatherhouse.h"

RoyalLeatherHouse::RoyalLeatherHouse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RoyalLeatherHouse)
{
    ui->setupUi(this);
}

RoyalLeatherHouse::~RoyalLeatherHouse()
{
    delete ui;
}
