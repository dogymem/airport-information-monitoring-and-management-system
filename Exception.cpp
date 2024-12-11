#include "Exception.h"

#include <QMessageBox>

void Exception::showMessage() const {
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(message));
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}


