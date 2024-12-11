//
// Created by Егор Томашев on 30.10.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginDialog.h" resolved

#include "logindialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>
#include <fstream>

using namespace std;

LoginDialog::LoginDialog(bool& isLogged,bool& permission,QWidget *parent) :
    QDialog(parent), ui(new Ui::LoginDialog), isLogged(isLogged), permission(permission) {
    ui->setupUi(this);
    connect(ui->loginbutton, &QPushButton::clicked, this, &LoginDialog::onLoginButtonClick);
    connect(ui->watchonlybutton, &QPushButton::clicked, this, &LoginDialog::onWatchOnlyButtonClick);
    connect(ui->login, &QLineEdit::textChanged, this, &LoginDialog::loginButtonActivation);
    connect(ui->password, &QLineEdit::textChanged, this, &LoginDialog::loginButtonActivation);
}

LoginDialog::~LoginDialog() {
    delete ui;
}

bool LoginDialog::credentialsCheck() {
    string bufLogin;
    size_t bufHash;
    size_t size;
    std::ifstream in("credentials.bin", std::ios::binary);
    if (in.is_open()) {
        in.read((char*)&size, sizeof(size));
        for(int i=0;i<size;i++) {
            std::getline(in, bufLogin, '\0');
            in.read((char*)&bufHash, sizeof(bufHash));
            if (bufLogin==login && bufHash==hash) {
                QMessageBox::information(this, "Success", "You are logged in");
                return true;
            }
        }
        QMessageBox::critical(this, "Error", "Invalid login or password");
        return false;
    }
    if (login==BASICLOGIN&& hash==std::hash<std::string>{}(BASICPASSWORD)) {
        QMessageBox::information(this, "Success", "You are logged in");
        return true;
    }
    QMessageBox::critical(this, "Error", "Invalid login or password");
    return false;
}
void LoginDialog::onLoginButtonClick() {
    login = ui->login->text().toStdString();
    hash = std::hash<std::string>{}(ui->password->text().toStdString());
    if (credentialsCheck()) {
        isLogged = true;
        permission = true;
        this->close();
    }
}

void LoginDialog::onWatchOnlyButtonClick() {
    QMessageBox::information(this, "Logged In", "You are logged in in only watch mode");
    isLogged = true;
    permission = false;
    this->close();
}

void LoginDialog::loginButtonActivation() {
    ui->loginbutton->setEnabled(!(ui->login->text().isEmpty() || ui->password->text().isEmpty()));
}
