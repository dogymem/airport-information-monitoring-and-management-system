//
// Created by Егор Томашев on 12.11.24.
//

#ifndef REGESTRATIONDIALOG_H
#define REGESTRATIONDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class RegestrationDialog; }
QT_END_NAMESPACE

class RegestrationDialog : public QDialog {
Q_OBJECT

public:
    explicit RegestrationDialog(QWidget *parent = nullptr);
    ~RegestrationDialog() override;

private slots:
    void onSignUpButtonClick();
    void signUpButtonActivation();

private:
    Ui::RegestrationDialog *ui;
std::string login;
    size_t hash;
};


#endif //REGESTRATIONDIALOG_H
