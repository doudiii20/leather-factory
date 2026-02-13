#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Hide default menubar / statusbar
    menuBar()->hide();
    statusBar()->hide();

    // Stretch table columns to fill
    ui->employeeTable->horizontalHeader()->setStretchLastSection(true);
    ui->employeeTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connectSidebar();

    // Start on Accueil (page 0)
    ui->contentStack->setCurrentIndex(0);
    setActiveButton(ui->btnAccueil);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSidebar()
{
    // Only Employes button switches to employee page (index 1).
    // All other sidebar buttons go to placeholder (index 2).
    // Accueil goes to home (index 0).

    connect(ui->btnAccueil, &QPushButton::clicked, this, [this]() {
        ui->contentStack->setCurrentIndex(0);
        setActiveButton(ui->btnAccueil);
    });

    connect(ui->btnEmployes, &QPushButton::clicked, this, [this]() {
        ui->contentStack->setCurrentIndex(1);
        setActiveButton(ui->btnEmployes);
    });

    // Disable other module buttons (not yet implemented)
    ui->btnFournisseurs->setEnabled(false);
    ui->btnProduits->setEnabled(false);
    ui->btnCommandes->setEnabled(false);
    ui->btnParametres->setEnabled(false);
}

void MainWindow::setActiveButton(QPushButton *active)
{
    QString defaultStyle = R"(
        background: transparent;
        color: rgb(248, 241, 227);
        text-align: left;
        padding: 12px 16px;
        border: none;
        border-left: 4px solid transparent;
        font-size: 13px;
    )";

    QString activeStyle = R"(
        background-color: rgb(255, 205, 185);
        color: rgb(88, 41, 0);
        text-align: left;
        padding: 12px 16px;
        border: none;
        border-left: 4px solid rgb(255, 205, 185);
        font-size: 13px;
        font-weight: bold;
    )";

    QList<QPushButton*> allBtns = {
        ui->btnAccueil, ui->btnEmployes, ui->btnFournisseurs,
        ui->btnProduits, ui->btnCommandes, ui->btnParametres
    };

    for (QPushButton *btn : allBtns) {
        btn->setStyleSheet(btn == active ? activeStyle : defaultStyle);
    }
}
