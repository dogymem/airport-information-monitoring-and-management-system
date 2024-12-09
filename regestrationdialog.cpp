//
// Created by Егор Томашев on 12.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RegestrationDialog.h" resolved

#include "regestrationdialog.h"
#include "ui_RegestrationDialog.h"
#include <fstream>
#include <QMessageBox>
using namespace std;

RegestrationDialog::RegestrationDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::RegestrationDialog) {
    ui->setupUi(this);
    connect(ui->signup, &QPushButton::clicked, this, &RegestrationDialog::onSignUpButtonClick);
    connect(ui->login, &QLineEdit::textChanged, this, &RegestrationDialog::signUpButtonActivation);
    connect(ui->password, &QLineEdit::textChanged, this, &RegestrationDialog::signUpButtonActivation);
}

RegestrationDialog::~RegestrationDialog() {
    delete ui;
}
void RegestrationDialog::onSignUpButtonClick() {
    if(ui->login->text().toStdString().empty() || ui->password->text().toStdString().empty()) {
        QMessageBox::critical(this, "Error", "Login or password is empty");
    }
    else {
        login = ui->login->text().toStdString();
        hash = std::hash<std::string>{}(ui->password->text().toStdString());
        std::ifstream in("/Users/egortomasev/Desktop/credentials.bin", std::ios::binary | std::ios::ate);
        int num = 0;
        if (in.tellg()==EOF) {
            in.close();
            size_t size = 1;
            std::ofstream out("/Users/egortomasev/Desktop/credentials.bin", std::ios::binary | ios::out);
            out.write((const char*) &size, sizeof(size));
            out.close();
        }
        else {
            size_t size;
            in.close();
            std::ifstream in("/Users/egortomasev/Desktop/credentials.bin", ios::binary | ios::in);
            in.read((char*)&size, sizeof(size));
            in.close();
            size++;
            std::fstream out("/Users/egortomasev/Desktop/credentials.bin", std::ios::binary | ios::in | ios::out);
            out.seekp(0,ios_base::beg);
            out.write((const char*) &size, sizeof(size));
            out.close();
        }
        std::ofstream out("/Users/egortomasev/Desktop/credentials.bin", std::ios::binary | ios::app);
        out.seekp(0,ios_base::end);
        out.write(login.c_str(), login.size());
        out.write("\0", 1);
        out.write((const char*) &hash, sizeof(hash));
        out.close();
        QMessageBox::information(this, "Success", "You have successfully signed up");
        this->close();
    }
}

void RegestrationDialog::signUpButtonActivation() {
    ui->signup->setEnabled(!(ui->login->text().isEmpty() || ui->password->text().isEmpty()));
}
