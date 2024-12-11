#include <QApplication>
#include <filesystem>

#include "clases.h"
#include "StartWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StartWindow startWindow;
    startWindow.show();
    return QApplication::exec();
}