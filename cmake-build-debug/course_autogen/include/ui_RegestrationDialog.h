/********************************************************************************
** Form generated from reading UI file 'RegestrationDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGESTRATIONDIALOG_H
#define UI_REGESTRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegestrationDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *password;
    QLineEdit *login;
    QPushButton *signup;

    void setupUi(QDialog *RegestrationDialog)
    {
        if (RegestrationDialog->objectName().isEmpty())
            RegestrationDialog->setObjectName("RegestrationDialog");
        RegestrationDialog->resize(600, 400);
        gridLayout = new QGridLayout(RegestrationDialog);
        gridLayout->setObjectName("gridLayout");
        password = new QLineEdit(RegestrationDialog);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(password, 1, 0, 1, 1);

        login = new QLineEdit(RegestrationDialog);
        login->setObjectName("login");
        login->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(login, 0, 0, 1, 1);

        signup = new QPushButton(RegestrationDialog);
        signup->setObjectName("signup");
        signup->setEnabled(false);

        gridLayout->addWidget(signup, 2, 0, 1, 1);


        retranslateUi(RegestrationDialog);

        QMetaObject::connectSlotsByName(RegestrationDialog);
    } // setupUi

    void retranslateUi(QDialog *RegestrationDialog)
    {
        RegestrationDialog->setWindowTitle(QCoreApplication::translate("RegestrationDialog", "Regestration", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("RegestrationDialog", "Password", nullptr));
        login->setPlaceholderText(QCoreApplication::translate("RegestrationDialog", "Login", nullptr));
        signup->setText(QCoreApplication::translate("RegestrationDialog", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegestrationDialog: public Ui_RegestrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGESTRATIONDIALOG_H
