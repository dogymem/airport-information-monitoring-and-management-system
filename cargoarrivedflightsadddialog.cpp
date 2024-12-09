//
// Created by Егор Томашев on 20.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CargoArrivedFlightsAddDialog.h" resolved

#include "cargoarrivedflightsadddialog.h"

#include "StartWindow.h"
#include "ui_CargoArrivedFlightsAddDialog.h"


CargoArrivedFlightsAddDialog::CargoArrivedFlightsAddDialog(vector<ArrivingCargoFlight>& arrCargoFlights,bool isEditing,int row,QWidget *parent) :
    QDialog(parent), ui(new Ui::CargoArrivedFlightsAddDialog), arrCargoFlights(arrCargoFlights), isEditing(isEditing), row(row) {
    ui->setupUi(this);
    ui->time->setMinimumDate(QDate::currentDate().addDays(-3));
    ui->time->setDateTime(QDateTime::currentDateTime());
    ui->time->setMaximumDate(QDate::currentDate().addDays(3));
    connect(ui->AddButton, &QPushButton::clicked, this, &CargoArrivedFlightsAddDialog::onAddButtonClick);
    if (isEditing) {
        ui->flightnumber->setText(QString::fromStdString(arrCargoFlights[row].get_flight_number()));
        ui->aircrafttype->setText(QString::fromStdString(arrCargoFlights[row].get_aircraft_type()));
        ui->isArrived->setChecked(arrCargoFlights[row].get_is_arrive());
        ui->late->setChecked(arrCargoFlights[row].get_is_late());
        ui->customs->setChecked(arrCargoFlights[row].get_customs_required());
        ui->connecting->setChecked(arrCargoFlights[row].get_is_connecting_flight());
        ui->emergency->setChecked(arrCargoFlights[row].get_is_emergency_landing());
        ui->baggageUnloadded->setChecked(arrCargoFlights[row].get_is_cargo_unloaded());
        ui->time->setDateTime(QDateTime::fromString(QString::fromStdString(arrCargoFlights[row].get_time())));
        ui->runway->setText(QString::fromStdString(arrCargoFlights[row].get_runway()));
        ui->departure->setText(QString::fromStdString(arrCargoFlights[row].get_departure()));
        ui->cargomax->setValue(arrCargoFlights[row].get_cargo_max_weight());
        ui->cargotype->setText(QString::fromStdString(arrCargoFlights[row].get_cargo_type()));
        ui->AddButton->setText("Edit");
    }
    connect(ui->flightnumber, &QLineEdit::textChanged, this, &CargoArrivedFlightsAddDialog::addButtonActivation);
    connect(ui->aircrafttype, &QLineEdit::textChanged, this, &CargoArrivedFlightsAddDialog::addButtonActivation);
    connect(ui->runway, &QLineEdit::textChanged, this, &CargoArrivedFlightsAddDialog::addButtonActivation);
    connect(ui->departure, &QLineEdit::textChanged, this, &CargoArrivedFlightsAddDialog::addButtonActivation);
    connect(ui->cargotype, &QLineEdit::textChanged, this, &CargoArrivedFlightsAddDialog::addButtonActivation);

}

CargoArrivedFlightsAddDialog::~CargoArrivedFlightsAddDialog() {
    delete ui;
}

void CargoArrivedFlightsAddDialog::onAddButtonClick() {
    if (isEditing) {
        arrCargoFlights[row].set_flight_number(ui->flightnumber->text().toStdString());
        arrCargoFlights[row].set_aircraft_type(ui->aircrafttype->text().toStdString());
        arrCargoFlights[row].set_is_arrive(ui->isArrived->isChecked());
        arrCargoFlights[row].set_is_late(ui->late->isChecked());
        arrCargoFlights[row].set_customs_required(ui->customs->isChecked());
        arrCargoFlights[row].set_is_connecting_flight(ui->connecting->isChecked());
        arrCargoFlights[row].set_is_emergency_landing(ui->emergency->isChecked());
        arrCargoFlights[row].set_is_cargo_unloaded(ui->baggageUnloadded->isChecked());
        arrCargoFlights[row].set_time(ui->time->dateTime().toString().toStdString());
        arrCargoFlights[row].set_runway(ui->runway->text().toStdString());
        arrCargoFlights[row].set_departure(ui->departure->text().toStdString());
        arrCargoFlights[row].set_cargo_max_weight(ui->cargomax->value());
        arrCargoFlights[row].set_cargo_type(ui->cargotype->text().toStdString());
        this->done(0);
    }else {
        ArrivingCargoFlight buffer;
        buffer.set_flight_number(ui->flightnumber->text().toStdString());
        buffer.set_aircraft_type(ui->aircrafttype->text().toStdString());
        buffer.set_is_arrive(ui->isArrived->isChecked());
        buffer.set_is_late(ui->late->isChecked());
        buffer.set_customs_required(ui->customs->isChecked());
        buffer.set_is_connecting_flight(ui->connecting->isChecked());
        buffer.set_is_emergency_landing(ui->emergency->isChecked());
        buffer.set_is_cargo_unloaded(ui->baggageUnloadded->isChecked());
        buffer.set_time(ui->time->dateTime().toString().toStdString());
        buffer.set_runway(ui->runway->text().toStdString());
        buffer.set_departure(ui->departure->text().toStdString());
        buffer.set_cargo_max_weight(ui->cargomax->value());
        buffer.set_cargo_type(ui->cargotype->text().toStdString());
        arrCargoFlights.push_back(buffer);
        this->done(0);
    }
}

void CargoArrivedFlightsAddDialog::addButtonActivation() {
    ui->AddButton->setEnabled(!(ui->flightnumber->text().isEmpty() || ui->aircrafttype->text().isEmpty() || ui->runway->text().isEmpty() || ui->departure->text().isEmpty() || ui->cargotype->text().isEmpty()));
}
