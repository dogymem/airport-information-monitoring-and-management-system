/********************************************************************************
** Form generated from reading UI file 'LoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *login;
    QLineEdit *password;
    QSpacerItem *verticalSpacer;
    QPushButton *watchonlybutton;
    QPushButton *loginbutton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(782, 506);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_2 = new QSpacerItem(758, 230, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 2);

        login = new QLineEdit(LoginDialog);
        login->setObjectName("login");
        login->setStyleSheet(QString::fromUtf8(""));
        login->setEchoMode(QLineEdit::EchoMode::Normal);

        gridLayout->addWidget(login, 1, 0, 1, 2);

        password = new QLineEdit(LoginDialog);
        password->setObjectName("password");
        password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(password, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(758, 229, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 2);

        watchonlybutton = new QPushButton(LoginDialog);
        watchonlybutton->setObjectName("watchonlybutton");

        gridLayout->addWidget(watchonlybutton, 4, 0, 1, 1);

        loginbutton = new QPushButton(LoginDialog);
        loginbutton->setObjectName("loginbutton");
        loginbutton->setEnabled(false);

        gridLayout->addWidget(loginbutton, 4, 1, 1, 1);


        retranslateUi(LoginDialog);

        loginbutton->setDefault(true);


        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Authorization", nullptr));
#if QT_CONFIG(accessibility)
        login->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        login->setInputMask(QString());
        login->setText(QString());
        login->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Login", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginDialog", "Password", nullptr));
        watchonlybutton->setText(QCoreApplication::translate("LoginDialog", "Watch only", nullptr));
        loginbutton->setText(QCoreApplication::translate("LoginDialog", "Log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
