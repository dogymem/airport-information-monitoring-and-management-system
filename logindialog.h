//
// Created by Егор Томашев on 30.10.24.
//

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#define BASICLOGIN "VLADIMIRPUTIN"
#define BASICPASSWORD "MOLODETS"

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class LoginDialog : public QDialog {
Q_OBJECT

public:
    explicit LoginDialog(bool& isLogged,bool& permission,QWidget *parent = nullptr);
    ~LoginDialog() override;
    bool credentialsCheck();

private slots:
    void onLoginButtonClick();
    void onWatchOnlyButtonClick();

void loginButtonActivation();

private:
    bool& isLogged;
    bool& permission;
    std::string login;
    size_t hash;
    Ui::LoginDialog *ui;
};


#endif //LOGINDIALOG_H
