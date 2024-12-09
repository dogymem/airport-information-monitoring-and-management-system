//
// Created by Егор Томашев on 20.11.24.
//

#ifndef CARGOARRIVEDFLIGHTSADDDIALOG_H
#define CARGOARRIVEDFLIGHTSADDDIALOG_H

#include <QDialog>

#include "clases.h"


QT_BEGIN_NAMESPACE
namespace Ui { class CargoArrivedFlightsAddDialog; }
QT_END_NAMESPACE

class CargoArrivedFlightsAddDialog : public QDialog {
Q_OBJECT

public:
    explicit CargoArrivedFlightsAddDialog(vector<ArrivingCargoFlight>& arrCargoFlights,bool isEditing,int row,QWidget *parent = nullptr);
    ~CargoArrivedFlightsAddDialog() override;

    private slots:
        void onAddButtonClick();
    void addButtonActivation();

private:
    bool isEditing;
    int row;
    vector<ArrivingCargoFlight>& arrCargoFlights;
    Ui::CargoArrivedFlightsAddDialog *ui;
};


#endif //CARGOARRIVEDFLIGHTSADDDIALOG_H
