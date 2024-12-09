//
// Created by Егор Томашев on 19.11.24.
//

#ifndef CARGODIALOG_H
#define CARGODIALOG_H

#include <QDialog>
#include "clases.h"
#include "StartWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CargoDialog; }
QT_END_NAMESPACE

class CargoDialog : public QDialog {
Q_OBJECT

public:
    explicit CargoDialog(vector<Cargo>& cargo,QWidget *parent = nullptr);
    ~CargoDialog() override;

private slots:
    void addActivation();
    void onAddButtonClick();
    void onUndoClick();


private:
    void vectorToTable();

void onDeleteButtonClicked();

bool yesNoButton();

Stack<vector<Cargo>> backUpCargo;
    Ui::CargoDialog *ui;
    vector<Cargo>& cargo;
};



#endif //CARGODIALOG_H
