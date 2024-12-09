#include "departedcargoflightsadddialog.h"

#include "clases.h"
#include "ui_DepartedCargoFlightsAddDialog.h"


DepartedCargoFlightsAddDialog::DepartedCargoFlightsAddDialog(vector<DepartingCargoFlight> &depCargoFlight,bool isEditing,int row,QWidget *parent) :
    QDialog(parent), ui(new Ui::DepartedCargoFlightsAddDialog),depCargoFlight(depCargoFlight), isEditing(isEditing), row(row) {
    ui->setupUi(this);
    connect(ui->AddButton, &QPushButton::clicked, this, &DepartedCargoFlightsAddDialog::onAddButtonClick);
    ui->time->setMinimumDate(QDate::currentDate().addDays(-3));
    ui->time->setDateTime(QDateTime::currentDateTime());
    ui->time->setMaximumDate(QDate::currentDate().addDays(3));
    ui->cargoStartTime->setTime(QTime::currentTime());
    ui->cargoEndTime->setTime(QTime::currentTime());
    if (isEditing) {
        ui->flightnumber->setText(QString::fromStdString(depCargoFlight[row].get_flight_number()));
        ui->aircrafttype->setText(QString::fromStdString(depCargoFlight[row].get_aircraft_type()));
        ui->time->setDateTime(QDateTime::fromString(QString::fromStdString(depCargoFlight[row].get_time())));;
        ui->runway->setText(QString::fromStdString(depCargoFlight[row].get_runway()));
        ui->destination->setText(QString::fromStdString(depCargoFlight[row].get_destination()));
        ui->status->setText(QString::fromStdString(depCargoFlight[row].get_status()));
        ui->fuelStatus->setText(QString::fromStdString(depCargoFlight[row].get_fuel_status()));
        ui->aircraftStatus->setText(QString::fromStdString(depCargoFlight[row].get_aircraft_status()));
        ui->isDepart->setChecked(depCargoFlight[row].get_is_depart());
        ui->cargoLoadded->setChecked(depCargoFlight[row].get_is_cargo_loaded());
        ui->type->setText(QString::fromStdString(depCargoFlight[row].get_cargo_type()));
        ui->cargoStartTime->setTime(QTime::fromString(QString::fromStdString(depCargoFlight[row].get_cargo_start_load_time())));
        ui->cargoEndTime->setTime(QTime::fromString(QString::fromStdString(depCargoFlight[row].get_cargo_end_load_time())));
        ui->maxWeight->setValue(depCargoFlight[row].get_cargo_max_weight());
        ui->AddButton->setText("Edit");
    }
    connect(ui->flightnumber, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->aircrafttype, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->runway, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->destination, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->status, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->fuelStatus, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->aircraftStatus, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
    connect(ui->type, &QLineEdit::textChanged, this, &DepartedCargoFlightsAddDialog::addButtonActivation);
}

DepartedCargoFlightsAddDialog::~DepartedCargoFlightsAddDialog() {
    delete ui;
}

void DepartedCargoFlightsAddDialog::onAddButtonClick() {
    if (isEditing) {
        depCargoFlight[row].set_flight_number(ui->flightnumber->text().toStdString());
        depCargoFlight[row].set_aircraft_type(ui->aircrafttype->text().toStdString());
        depCargoFlight[row].set_time(ui->time->text().toStdString());
        depCargoFlight[row].set_runway(ui->runway->text().toStdString());
        depCargoFlight[row].set_destination(ui->destination->text().toStdString());
        depCargoFlight[row].set_status(ui->status->text().toStdString());
        depCargoFlight[row].set_fuel_status(ui->fuelStatus->text().toStdString());
        depCargoFlight[row].set_aircraft_status(ui->aircraftStatus->text().toStdString());
        depCargoFlight[row].set_fuel_status(ui->fuelStatus->text().toStdString());
        depCargoFlight[row].set_is_depart(ui->isDepart->isChecked());
        depCargoFlight[row].set_aircraft_status(ui->aircraftStatus->text().toStdString());
        depCargoFlight[row].set_is_cargo_loaded(ui->cargoLoadded->isChecked());
        depCargoFlight[row].set_cargo_type(ui->type->text().toStdString());
        depCargoFlight[row].set_cargo_start_load_time(ui->cargoStartTime->text().toStdString());
        depCargoFlight[row].set_cargo_end_load_time(ui->cargoEndTime->text().toStdString());
        depCargoFlight[row].set_cargo_max_weight(ui->maxWeight->value());
        this->done(0);
    }else {
        auto& buffer = depCargoFlight.emplace_back();
        buffer.set_flight_number(ui->flightnumber->text().toStdString());
        buffer.set_aircraft_type(ui->aircrafttype->text().toStdString());
        buffer.set_time(ui->time->text().toStdString());
        buffer.set_runway(ui->runway->text().toStdString());
        buffer.set_destination(ui->destination->text().toStdString());
        buffer.set_status(ui->status->text().toStdString());
        buffer.set_fuel_status(ui->fuelStatus->text().toStdString());
        buffer.set_aircraft_status(ui->aircraftStatus->text().toStdString());
        buffer.set_fuel_status(ui->fuelStatus->text().toStdString());
        buffer.set_is_depart(ui->isDepart->isChecked());
        buffer.set_aircraft_status(ui->aircraftStatus->text().toStdString());
        buffer.set_is_cargo_loaded(ui->cargoLoadded->isChecked());
        buffer.set_cargo_type(ui->type->text().toStdString());
        buffer.set_cargo_start_load_time(ui->cargoStartTime->text().toStdString());
        buffer.set_cargo_end_load_time(ui->cargoEndTime->text().toStdString());
        buffer.set_cargo_max_weight(ui->maxWeight->value());
        this->done(0);
    }
}

void DepartedCargoFlightsAddDialog::addButtonActivation() {
    ui->AddButton->setEnabled(!(ui->flightnumber->text().isEmpty() || ui->aircrafttype->text().isEmpty() || ui->runway->text().isEmpty() || ui->destination->text().isEmpty() || ui->status->text().isEmpty() || ui->fuelStatus->text().isEmpty() || ui->aircraftStatus->text().isEmpty() || ui->type->text().isEmpty()));
}

