#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setBaseSize(500, 500);

    setCentralWidget(&stackedWidget);
    stackedWidget.addWidget(&wizard);

    connect(&wizard, &ProjectWizard::handleWindowChange,
            this, &MainWindow::handleWindowChange);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete workspace;
}

void MainWindow::handleWindowChange(std::string name, int height, int width) {
    workspace = new Workspace(height, width);
    workspace->setParent(&stackedWidget);

    stackedWidget.addWidget(workspace);
    stackedWidget.setCurrentIndex(1);
}
