#include "passengerdepartedflightsadddialog.h"

#include "Exception.h"
#include "ui_passengerdepartedflightsadddialog.h"


PassengerDepartedFlightsAddDialog::PassengerDepartedFlightsAddDialog(vector<DepartingPassengerFlight> &depPassFlight,bool isEditing,int row,
                                                                     QWidget *parent) : QDialog(parent), ui(new Ui::PassengerDepartedFlightsAddDialog), depPassFlight(depPassFlight), isEditing(isEditing),row(row) {
    ui->setupUi(this);
    connect(ui->AddButton, &QPushButton::clicked, this, &PassengerDepartedFlightsAddDialog::onAddButtonClick);
    ui->time->setDateTime(QDateTime::currentDateTime());
    ui->boardingStartTime->setTime(QTime::currentTime());
    ui->boardingEndTime->setTime(QTime::currentTime());
    ui->checkInStartTime->setTime(QTime::currentTime());
    ui->checkInEndTime->setTime(QTime::currentTime());
    if (isEditing) {
        ui->flightnumber->setText(QString::fromStdString(depPassFlight[row].get_flight_number()));
        ui->aircrafttype->setText(QString::fromStdString(depPassFlight[row].get_aircraft_type()));
        ui->time->setDateTime(QDateTime::fromString(QString::fromStdString(depPassFlight[row].get_time())));
        ui->runway->setText(QString::fromStdString(depPassFlight[row].get_runway()));
        ui->destination->setText(QString::fromStdString(depPassFlight[row].get_destination()));
        ui->status->setText(QString::fromStdString(depPassFlight[row].get_status()));
        ui->fuelStatus->setText(QString::fromStdString(depPassFlight[row].get_fuel_status()));
        ui->aircraftStatus->setText(QString::fromStdString(depPassFlight[row].get_aircraft_status()));
        ui->baggageLoadded->setChecked(depPassFlight[row].get_is_baggage_loaded());
        ui->isDepart->setChecked(depPassFlight[row].get_is_depart());
        ui->terminal->setText(QString::fromStdString(depPassFlight[row].get_terminal()));
        ui->gate->setText(QString::fromStdString(depPassFlight[row].get_gate()));
        ui->passMax->setValue(depPassFlight[row].get_passenger_max_value());
        ui->checkInStartTime->setTime(QTime::fromString(QString::fromStdString(depPassFlight[row].get_check_in_start_time())));
        ui->checkInEndTime->setTime(QTime::fromString(QString::fromStdString(depPassFlight[row].get_check_in_end_time())));
        ui->boardingStartTime->setTime(QTime::fromString(QString::fromStdString(depPassFlight[row].get_boarding_start_time())));
        ui->boardingEndTime->setTime(QTime::fromString(QString::fromStdString(depPassFlight[row].get_boarding_end_time())));
        ui->AddButton->setText("Edit");
    }
    connect(ui->flightnumber, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->aircrafttype, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->runway, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->destination, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->status, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->fuelStatus, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->aircraftStatus, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->terminal, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);
    connect(ui->gate, &QLineEdit::textChanged, this, &PassengerDepartedFlightsAddDialog::addButtonActivation);


}

PassengerDepartedFlightsAddDialog::~PassengerDepartedFlightsAddDialog() {
    delete ui;
}

void PassengerDepartedFlightsAddDialog::onAddButtonClick() {
    if (isEditing) {
        try{
            depPassFlight[row].set_flight_number(ui->flightnumber->text().toStdString());
            depPassFlight[row].set_aircraft_type(ui->aircrafttype->text().toStdString());
            depPassFlight[row].set_time(ui->time->text().toStdString());
            depPassFlight[row].set_runway(ui->runway->text().toStdString());
            depPassFlight[row].set_destination(ui->destination->text().toStdString());
            depPassFlight[row].set_status(ui->status->text().toStdString());
            depPassFlight[row].set_fuel_status(ui->fuelStatus->text().toStdString());
            depPassFlight[row].set_aircraft_status(ui->aircraftStatus->text().toStdString());
            depPassFlight[row].set_is_baggage_loaded(ui->baggageLoadded->isChecked());
            depPassFlight[row].set_is_depart(ui->isDepart->isChecked());
            depPassFlight[row].set_terminal(ui->terminal->text().toStdString());
            depPassFlight[row].set_gate(ui->gate->text().toStdString());
            depPassFlight[row].set_passenger_max_value(ui->passMax->value());
            depPassFlight[row].set_check_in_start_time(ui->checkInStartTime->text().toStdString());
            depPassFlight[row].set_check_in_end_time(ui->checkInEndTime->text().toStdString());
            depPassFlight[row].set_boarding_start_time(ui->boardingEndTime->text().toStdString());
            depPassFlight[row].set_boarding_end_time(ui->boardingEndTime->text().toStdString());
        }catch (flightException& e) {
            e.showMessage();
            return;
        }
        this->done(0);
    }else {
        auto& buffer = depPassFlight.emplace_back();
        try{
            buffer.set_flight_number(ui->flightnumber->text().toStdString());
            buffer.set_aircraft_type(ui->aircrafttype->text().toStdString());
            buffer.set_time(ui->time->text().toStdString());
            buffer.set_runway(ui->runway->text().toStdString());
            buffer.set_destination(ui->destination->text().toStdString());
            buffer.set_status(ui->status->text().toStdString());
            buffer.set_fuel_status(ui->fuelStatus->text().toStdString());
            buffer.set_aircraft_status(ui->aircraftStatus->text().toStdString());
            buffer.set_is_baggage_loaded(ui->baggageLoadded->isChecked());
            buffer.set_is_depart(ui->isDepart->isChecked());
            buffer.set_terminal(ui->terminal->text().toStdString());
            buffer.set_gate(ui->gate->text().toStdString());
            buffer.set_passenger_max_value(ui->passMax->value());
            buffer.set_check_in_start_time(ui->checkInStartTime->text().toStdString());
            buffer.set_check_in_end_time(ui->checkInEndTime->text().toStdString());
            buffer.set_boarding_start_time(ui->boardingEndTime->text().toStdString());
            buffer.set_boarding_end_time(ui->boardingEndTime->text().toStdString());
        }catch (flightException& e) {
            e.showMessage();
            return;
        }
    }
    this->done(0);
}

void PassengerDepartedFlightsAddDialog::addButtonActivation() {
    ui->AddButton->setEnabled(!(ui->flightnumber->text().isEmpty() || ui->aircrafttype->text().isEmpty() || ui->runway->text().isEmpty() || ui->destination->text().isEmpty() || ui->status->text().isEmpty() || ui->fuelStatus->text().isEmpty() || ui->aircraftStatus->text().isEmpty() || ui->terminal->text().isEmpty() || ui->gate->text().isEmpty()));
}
