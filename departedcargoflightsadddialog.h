//
// Created by Егор Томашев on 25.11.24.
//

#ifndef DEPARTEDCARGOFLIGHTSADDDIALOG_H
#define DEPARTEDCARGOFLIGHTSADDDIALOG_H

#include <QDialog>
#include <QWidget>

#include "clases.h"


QT_BEGIN_NAMESPACE
namespace Ui { class DepartedCargoFlightsAddDialog; }
QT_END_NAMESPACE

class DepartedCargoFlightsAddDialog : public QDialog {
Q_OBJECT

public:
    explicit DepartedCargoFlightsAddDialog(vector<DepartingCargoFlight> &depCargoFlight,bool isEditing,int row,QWidget *parent = nullptr);
    ~DepartedCargoFlightsAddDialog() override;
private slots:
    void onAddButtonClick();
    void addButtonActivation();
private:
    bool isEditing;
    int row;
    Ui::DepartedCargoFlightsAddDialog *ui;
    vector<DepartingCargoFlight> &depCargoFlight;
};


#endif //DEPARTEDCARGOFLIGHTSADDDIALOG_H
