#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "core/image.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);

    Image myImage(500, 500);
    myImage.setFixedSize(500, 500);

    myImage.show();

    return QApplication::exec();
}
