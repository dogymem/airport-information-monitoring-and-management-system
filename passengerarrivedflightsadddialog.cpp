//
// Created by Егор Томашев on 11.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PassengerFlightsAddDialog.h" resolved

#include "passengerarrivedflightsadddialog.h"

#include "Exception.h"
#include "ui_PassengerFlightsAddDialog.h"


PassengerFlightsAddDialog::PassengerFlightsAddDialog(vector<ArrivingPassengerFlight>& arrPassFlights, bool isEditing,int row,QWidget *parent) :
    QDialog(parent), ui(new Ui::PassengerFlightsAddDialog), isEditing(isEditing), arrPassFlights(arrPassFlights), row(row) {
    ui->setupUi(this);
    ui->time->setDateTime(QDateTime::currentDateTime());
    connect(ui->AddButton, &QPushButton::clicked, this, &PassengerFlightsAddDialog::onAddButtonClick);
    connect(ui->flightnumber, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->aircrafttype, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->runway, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->departure, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->gate, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->terminal, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);
    connect(ui->baggagearea, &QLineEdit::textChanged, this, &PassengerFlightsAddDialog::addButtonActivation);

    if(isEditing) {
        ui->flightnumber->setText(QString::fromStdString(arrPassFlights[row].get_flight_number()));
        ui->aircrafttype->setText(QString::fromStdString(arrPassFlights[row].get_aircraft_type()));
        ui->isArrived->setChecked(arrPassFlights[row].get_is_arrive());
        ui->late->setChecked(arrPassFlights[row].get_is_late());
        ui->customs->setChecked(arrPassFlights[row].get_customs_required());
        ui->connecting->setChecked(arrPassFlights[row].get_is_connecting_flight());
        ui->emergency->setChecked(arrPassFlights[row].get_is_emergency_landing());
        ui->bus->setChecked(arrPassFlights[row].get_is_bus());
        ui->assistans->setChecked(arrPassFlights[row].get_special_assistance_required());
        ui->visa->setChecked(arrPassFlights[row].get_is_visa());
        ui->baggageUnloadded->setChecked(arrPassFlights[row].get_is_baggage_unloaded());
        ui->time->setDateTime(QDateTime::fromString(QString::fromStdString(arrPassFlights[row].get_time())));
        ui->runway->setText(QString::fromStdString(arrPassFlights[row].get_runway()));
        ui->departure->setText(QString::fromStdString(arrPassFlights[row].get_departure()));
        ui->gate->setText(QString::fromStdString(arrPassFlights[row].get_gate()));
        ui->terminal->setText(QString::fromStdString(arrPassFlights[row].get_terminal()));
        ui->baggagearea->setText(QString::fromStdString(arrPassFlights[row].get_baggage_claim_area()));
        ui->AddButton->setText("Edit");
    }
}

PassengerFlightsAddDialog::~PassengerFlightsAddDialog() {
    delete ui;
}

void PassengerFlightsAddDialog::onAddButtonClick() {
    if (isEditing) {
        try {
            arrPassFlights[row].set_flight_number(ui->flightnumber->text().toStdString());
            arrPassFlights[row].set_aircraft_type(ui->aircrafttype->text().toStdString());
            arrPassFlights[row].set_is_arrive(ui->isArrived->isChecked());
            arrPassFlights[row].set_is_late(ui->late->isChecked());
            arrPassFlights[row].set_customs_required(ui->customs->isChecked());
            arrPassFlights[row].set_is_connecting_flight(ui->connecting->isChecked());
            arrPassFlights[row].set_is_emergency_landing(ui->emergency->isChecked());
            arrPassFlights[row].set_is_bus(ui->bus->isChecked());
            arrPassFlights[row].set_special_assistance_required(ui->assistans->isChecked());
            arrPassFlights[row].set_is_visa(ui->visa->isChecked());
            arrPassFlights[row].set_is_baggage_unloaded(ui->baggageUnloadded->isChecked());
            arrPassFlights[row].set_time(ui->time->dateTime().toString().toStdString());
            arrPassFlights[row].set_runway(ui->runway->text().toStdString());
            arrPassFlights[row].set_departure(ui->departure->text().toStdString());
            arrPassFlights[row].set_gate(ui->gate->text().toStdString());
            arrPassFlights[row].set_terminal(ui->terminal->text().toStdString());
            arrPassFlights[row].set_baggage_claim_area(ui->baggagearea->text().toStdString());
        }
        catch (flightException& e) {
            e.showMessage();
            return;
        }
        this->done(0);
    }else {
        ArrivingPassengerFlight buffer;
        try{
            buffer.set_flight_number(ui->flightnumber->text().toStdString());
            buffer.set_aircraft_type(ui->aircrafttype->text().toStdString());
            buffer.set_is_arrive(ui->isArrived->isChecked());
            buffer.set_is_late(ui->late->isChecked());
            buffer.set_customs_required(ui->customs->isChecked());
            buffer.set_is_connecting_flight(ui->connecting->isChecked());
            buffer.set_is_emergency_landing(ui->emergency->isChecked());
            buffer.set_is_bus(ui->bus->isChecked());
            buffer.set_special_assistance_required(ui->assistans->isChecked());
            buffer.set_is_visa(ui->visa->isChecked());
            buffer.set_is_baggage_unloaded(ui->baggageUnloadded->isChecked());
            buffer.set_time(ui->time->dateTime().toString().toStdString());
            buffer.set_runway(ui->runway->text().toStdString());
            buffer.set_departure(ui->departure->text().toStdString());
            buffer.set_gate(ui->gate->text().toStdString());
            buffer.set_terminal(ui->terminal->text().toStdString());
            buffer.set_baggage_claim_area(ui->baggagearea->text().toStdString());
        }catch (flightException& e) {
            e.showMessage();
            return;
        }
        arrPassFlights.push_back(buffer);
        this->done(0);
    }
}
void PassengerFlightsAddDialog::addButtonActivation(){
    ui->AddButton->setEnabled(!(ui->flightnumber->text().isEmpty()|| ui->aircrafttype->text().isEmpty() || ui->runway->text().isEmpty() || ui->departure->text().isEmpty() || ui->gate->text().isEmpty() || ui->terminal->text().isEmpty() || ui->baggagearea->text().isEmpty() ));

}