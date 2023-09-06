#include <QApplication>

#include "core/image.h"
#include "ui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("Photo Editor");
    app.setOrganizationName("Juan Enterprises");

    MainWindow window;
    window.show();

    return app.exec();
}
