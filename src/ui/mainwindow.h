#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "ui/projectwizard.h"
#include "ui/workspace.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void handleWindowChange(std::string name, int height, int width);

private:
    Ui::MainWindow *ui;

    ProjectWizard wizard;
    Workspace* workspace;

    QStackedWidget stackedWidget;
};

#endif // MAINWINDOW_H
