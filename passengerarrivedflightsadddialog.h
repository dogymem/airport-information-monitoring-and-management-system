//
// Created by Егор Томашев on 11.11.24.
//

#ifndef PASSENGERFLIGHTSADDDIALOG_H
#define PASSENGERFLIGHTSADDDIALOG_H

#include <QDialog>

#include "clases.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PassengerFlightsAddDialog; }
QT_END_NAMESPACE

class PassengerFlightsAddDialog : public QDialog {
Q_OBJECT

public:
    explicit PassengerFlightsAddDialog(vector<ArrivingPassengerFlight>& arrPassFlights,bool isEditing,int row,QWidget *parent = nullptr);
    ~PassengerFlightsAddDialog() override;

private slots:
    void onAddButtonClick();
    void addButtonActivation();

private:
    int row;
    bool isEditing;
    Ui::PassengerFlightsAddDialog *ui;
    vector<ArrivingPassengerFlight>& arrPassFlights;
};


#endif //PASSENGERFLIGHTSADDDIALOG_H
