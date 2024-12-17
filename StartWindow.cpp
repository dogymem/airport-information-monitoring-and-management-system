#include "StartWindow.h"
#include "passengerregwindow.h"
#include "ui_StartWindow.h"
#include <QMessageBox>
#include <QTimer>
#include <fstream>
#include <qdatetime.h>

#include "cargoarrivedflightsadddialog.h"
#include "cargodialog.h"
#include "crewregdialog.h"
#include "departedcargoflightsadddialog.h"
#include "Exception.h"
#include "logindialog.h"
#include "passengerarrivedflightsadddialog.h"
#include "passengerdepartedflightsadddialog.h"
#include "pilotsregdialog.h"
#include "regestrationdialog.h"
template <typename T>
void fileRead(T& flights) {
        ifstream in;
        string path(getenv("HOME"));
        if constexpr (std::is_same_v<T, vector<ArrivingPassengerFlight> >) {
            in.open(path+"/Documents/airportSystem/ArrivingPassengerFlight.bin", std::ios::binary);
        }
        if constexpr (std::is_same_v<T, vector<ArrivingCargoFlight> >) {
            in.open(path+"/Documents/airportSystem/ArrivingCargoFlight.bin", std::ios::binary);
        }
        if constexpr (std::is_same_v<T, vector<DepartingPassengerFlight> >) {
            in.open(path+"/Documents/airportSystem/DepartingPassengerFlight.bin", std::ios::binary);
        }
        if constexpr (std::is_same_v<T, vector<DepartingCargoFlight> >) {
            in.open(path+"/Documents/airportSystem/DepartingCargoFlight.bin", std::ios::binary);
        }
        int size = 0;

        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        flights.resize(size);

        for (auto &flight: flights) {
            flight.set_flight_number(readString(in));
            flight.set_aircraft_type(readString(in));

            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            flight.set_number_of_staff(size);

            flight.set_time(readString(in));
            flight.set_runway(readString(in));

            in.read(reinterpret_cast<char *>(&size), sizeof(size));
            vector<Pilot> pilots(size);
            pilotsRead(in, pilots);
            flight.set_pilots(pilots);

            if constexpr (std::same_as<T, vector<ArrivingPassengerFlight> > || std::same_as<T, vector<ArrivingCargoFlight> >) {
                flight.set_is_arrive_str(readString(in));
                flight.set_is_late_str(readString(in));
                flight.set_departure(readString(in));
                flight.set_customs_required_str(readString(in));
                flight.set_is_connecting_flight_str(readString(in));
                flight.set_is_emergency_landing_str(readString(in));

                if constexpr (std::same_as<T, vector<ArrivingPassengerFlight>>) {
                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    flight.set_current_passenger_count(size);
                    flight.set_gate(readString(in));
                    flight.set_terminal(readString(in));
                    flight.set_is_bus_str(readString(in));
                    flight.set_baggage_claim_area(readString(in));
                    flight.set_special_assistance_required_str(readString(in));
                    flight.set_is_visa_str(readString(in));
                    flight.set_is_baggage_unloaded_str(readString(in));

                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    vector<Passenger> passengers(size);
                    passengersRead(in, passengers);
                    flight.set_passenger_list(passengers);

                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    std::vector<CrewMember> crewList(size);
                    crewRead(in, crewList);
                    flight.set_crew_list(crewList);
                }
                if constexpr (std::same_as<T, vector<ArrivingCargoFlight>>) {
                    double weight;
                    in.read(reinterpret_cast<char *>(&weight), sizeof(weight));
                    flight.set_cargo_max_weight(weight);
                    flight.set_cargo_type(readString(in));
                    flight.set_is_cargo_unloaded_str(readString(in));
                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    vector<Cargo> cargoes(size);
                    cargoRead(in, cargoes);
                    flight.set_cargo_list(cargoes);
                }
            }
            if constexpr (std::same_as<T, vector<DepartingPassengerFlight>> || std::same_as<T, vector<DepartingCargoFlight>>) {
                flight.set_is_depart_str(readString(in));
                flight.set_destination(readString(in));
                flight.set_status(readString(in));
                flight.set_fuel_status(readString(in));
                flight.set_aircraft_status(readString(in));
                if constexpr (std::same_as<T, vector<DepartingPassengerFlight>>) {
                    flight.set_terminal(readString(in));
                    flight.set_gate(readString(in));
                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    flight.set_passenger_max_value(size);
                    flight.set_check_in_start_time(readString(in));
                    flight.set_check_in_end_time(readString(in));
                    flight.set_boarding_start_time(readString(in));
                    flight.set_boarding_end_time(readString(in));
                    flight.set_is_baggage_loaded_str(readString(in));

                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    vector<Passenger> passengers(size);
                    passengersRead(in, passengers);
                    flight.set_passenger_list(passengers);

                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    std::vector<CrewMember> crewList(size);
                    crewRead(in, crewList);
                    flight.set_crew_list(crewList);
                }
                if constexpr (std::same_as<T, vector<DepartingCargoFlight> >) {
                    double maxWeight;
                    in.read(reinterpret_cast<char *>(&maxWeight), sizeof(maxWeight));
                    flight.set_cargo_max_weight(maxWeight);
                    flight.set_cargo_type(readString(in));
                    flight.set_is_cargo_loaded_str(readString(in));
                    flight.set_cargo_start_load_time(readString(in));
                    flight.set_cargo_end_load_time(readString(in));

                    in.read(reinterpret_cast<char *>(&size), sizeof(size));
                    vector<Cargo> cargoes(size);
                    cargoRead(in, cargoes);
                    flight.set_cargo_list(cargoes);
                }
            }
        }
        in.close();

}

template<typename T>
void fileWrite(T& flights) {
    ofstream out;
    string path(getenv("HOME"));
    if constexpr (std::is_same_v<T, vector<ArrivingPassengerFlight> >) {
        out.open(path+"/Documents/airportSystem/ArrivingPassengerFlight.bin", std::ios::binary);
    }
    if constexpr (std::is_same_v<T, vector<ArrivingCargoFlight> >) {
        out.open(path+"/Documents/airportSystem/ArrivingCargoFlight.bin", std::ios::binary);
    }
    if constexpr (std::is_same_v<T, vector<DepartingPassengerFlight> >) {
        out.open(path+"/Documents/airportSystem/DepartingPassengerFlight.bin", std::ios::binary);
    }
    if constexpr (std::is_same_v<T, vector<DepartingCargoFlight> >) {
        out.open(path+"/Documents/airportSystem/DepartingCargoFlight.bin", std::ios::binary);
    }
    int size = static_cast<int>(flights.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));

    for (auto &flight: flights) {
        writeString(out, flight.get_flight_number());
        writeString(out, flight.get_aircraft_type());

        size = flight.get_number_of_staff();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));

        writeString(out, flight.get_time());
        writeString(out, flight.get_runway());
        pilotsWrite(out, flight.get_pilots());
        if constexpr (std::same_as<T, vector<ArrivingPassengerFlight> > || std::same_as<T, vector<ArrivingCargoFlight> >) {
            writeString(out, flight.get_is_arrive_str());
            writeString(out, flight.get_is_late_str());
            writeString(out, flight.get_departure());
            writeString(out, flight.get_customs_required_str());
            writeString(out, flight.get_is_connecting_flight_str());
            writeString(out, flight.get_is_emergency_landing_str());
            if constexpr (std::same_as<T, vector<ArrivingPassengerFlight> >) {
                size = flight.get_current_passenger_count();
                out.write(reinterpret_cast<const char *>(&size), sizeof(size));
                writeString(out, flight.get_gate());
                writeString(out, flight.get_terminal());
                writeString(out, flight.get_is_bus_str());
                writeString(out, flight.get_baggage_claim_area());
                writeString(out, flight.get_special_assistance_required_str());
                writeString(out, flight.get_is_visa_str());
                writeString(out, flight.get_is_baggage_unloaded_str());
                passengersWrite(out, flight.get_passenger_list());
                crewWrite(out, flight.get_crew_list());
            }
            if constexpr (std::same_as<T, vector<ArrivingCargoFlight> >) {
                double weight = flight.get_cargo_max_weight();
                out.write(reinterpret_cast<const char *>(&weight), sizeof(weight));
                writeString(out, flight.get_cargo_type());
                writeString(out, flight.get_is_cargo_unloaded_str());
                cargoWrite(out, flight.get_cargo_list());
            }
        }
        if constexpr (std::same_as<T, vector<DepartingPassengerFlight> > || std::same_as<T, vector<DepartingCargoFlight> >) {
            writeString(out, flight.get_is_depart_str());
            writeString(out, flight.get_destination());
            writeString(out, flight.get_status());
            writeString(out, flight.get_fuel_status());
            writeString(out, flight.get_aircraft_status());
            if constexpr (std::same_as<T, vector<DepartingPassengerFlight> >) {
                writeString(out, flight.get_terminal());
                writeString(out, flight.get_gate());
                size = flight.get_passenger_max_value();
                out.write(reinterpret_cast<const char *>(&size), sizeof(size));
                writeString(out, flight.get_check_in_start_time());
                writeString(out, flight.get_check_in_end_time());
                writeString(out, flight.get_boarding_start_time());
                writeString(out, flight.get_boarding_end_time());
                writeString(out, flight.get_is_baggage_loaded_str());
                passengersWrite(out, flight.get_passenger_list());
                crewWrite(out, flight.get_crew_list());
            }
            if constexpr (std::same_as<T, vector<DepartingCargoFlight> >) {
                double maxWeight = flight.get_cargo_max_weight();
                out.write(reinterpret_cast<const char *>(&maxWeight), sizeof(maxWeight));
                writeString(out, flight.get_cargo_type());
                writeString(out, flight.get_is_cargo_loaded_str());
                writeString(out, flight.get_cargo_start_load_time());
                writeString(out, flight.get_cargo_end_load_time());
                cargoWrite(out, flight.get_cargo_list());
            }
        }
    }
    out.close();
}

StartWindow::StartWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::StartWindow) {
    ui->setupUi(this);
    
    connect(ui->ArrivingButton, &QPushButton::clicked, this, &StartWindow::onArrButtonClick);
    connect(ui->DepartingButton, &QPushButton::clicked, this, &StartWindow::onDepButtonClick);
    connect(ui->AddPassenerFlightsButton, &QPushButton::clicked, this, &StartWindow::onAddPassengerFlightsButtonClick);
    connect(ui->AddCargoFlightsButton, &QPushButton::clicked, this, &StartWindow::onAddCargoFlightsButtonClick);
    connect(ui->actionRegestration, &QAction::triggered, this, &StartWindow::onRegButtonClick);
    connect(ui->actionUndo_2,&QAction::triggered, this, &StartWindow::onUndoButtonClick);
    bool loggedIn = false;
    while (loggedIn == false) {
        LoginDialog loginDialog(loggedIn, permission);
        loginDialog.exec();
        if (loggedIn == false) {
            QMessageBox::critical(this, "Error", "You are not logged in");
        }
    }
    if (permission) {
        ui->menuOptions->setEnabled(true);
        ui->AddPassenerFlightsButton->setEnabled(true);
        ui->AddCargoFlightsButton->setEnabled(true);
        ui->menuEdit->setEnabled(true);
    }
    try {
        fileRead(arrPassFlights);
        fileRead(depPassFlights);
        fileRead(arrCargoFlights);
        fileRead(depCargoFlights);
    }catch (...) {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString("Error reading files"));
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        exit(1);
    }
    onArrButtonClick();
}

StartWindow::~StartWindow() {
    delete ui;
}

void writeString(ostream &out, const std::string &str) {
    out.write(str.c_str(), static_cast<long>(str.size()));
    out.put('\0');
}

string readString(ifstream &in) {
    std::string str;
    std::getline(in, str, '\0');
    return str;
}
void StartWindow::onArrButtonClick() {
    isArrivedSelected = true;
    vectorToTable();
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels1);
    ui->tableWidget_2->setHorizontalHeaderLabels(headerLabels2);
}

void StartWindow::onDepButtonClick() {
    isArrivedSelected = false;
    vectorToTable();
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels3);
    ui->tableWidget_2->setHorizontalHeaderLabels(headerLabels4);
}

void StartWindow::onAddPassengerFlightsButtonClick() {
    backUp();
    if (isArrivedSelected) {
        PassengerFlightsAddDialog passengerFlightsAddDialog(arrPassFlights,false,0);
        passengerFlightsAddDialog.exec();
        fileWrite(arrPassFlights);
        vectorToTable();
    } else {
        PassengerDepartedFlightsAddDialog passengerDeparedFlightsAddDialog(depPassFlights,false,0);
        passengerDeparedFlightsAddDialog.exec();
        fileWrite(depPassFlights);
        vectorToTable();
    }
}

void StartWindow::onAddCargoFlightsButtonClick() {
    backUp();
    if (isArrivedSelected) {
        CargoArrivedFlightsAddDialog cargoAddDialog(arrCargoFlights,false,0);
        cargoAddDialog.exec();
        fileWrite(arrCargoFlights);
        vectorToTable();
    } else {
        DepartedCargoFlightsAddDialog cargoDepDialog(depCargoFlights,false,0);
        cargoDepDialog.exec();
        fileWrite(depCargoFlights);
        vectorToTable();
    }
}

void StartWindow::onUndoButtonClick() {
    bool show;
    try {
        arrPassFlights=arrPassBackup.pop();
        fileWrite(arrPassFlights);
    }catch(StackException &e){
        e.showMessage();
        show = true;
    }
    try {
        depPassFlights=depPassBackup.pop();
        fileWrite(depPassFlights);
    }catch(StackException &e){
        if (!show)
            e.showMessage();
    }
    try {
        arrCargoFlights=arrCargoBackup.pop();
        fileWrite(arrCargoFlights);
    }catch(StackException &e){
        if (!show)
            e.showMessage();
    }
    try {
        depCargoFlights=depCargoBackup.pop();
        fileWrite(depCargoFlights);
    }catch(StackException &e){
        if (!show)
            e.showMessage();
    }
    vectorToTable();

}

void StartWindow::onPilotsButtonClicked() {
    if (sender()->property("type") == "arrPass") {
        PilotsRegDialog pilotsDialog(arrPassFlights[sender()->property("row").toInt()].get_pilots());
        pilotsDialog.exec();
        fileWrite(arrPassFlights);
    }
    if (sender()->property("type") == "arrCargo") {
        PilotsRegDialog pilotsDialog(arrCargoFlights[sender()->property("row").toInt()].get_pilots());
        pilotsDialog.exec();
        fileWrite(arrCargoFlights);
    }
    if (sender()->property("type") == "depPass") {
        PilotsRegDialog pilotsDialog(depPassFlights[sender()->property("row").toInt()].get_pilots());
        pilotsDialog.exec();
        fileWrite(depPassFlights);
    }
    if (sender()->property("type") == "depCargo") {
        PilotsRegDialog pilotsDialog(depCargoFlights[sender()->property("row").toInt()].get_pilots());
        pilotsDialog.exec();
        fileWrite(depCargoFlights);
    }
    vectorToTable();
}

void StartWindow::onRegButtonClick() {
    RegestrationDialog regestrationDialog;
    regestrationDialog.exec();
}

void StartWindow::onPassengersButtonClicked() {
    if (sender()->property("type") == "arrPass") {
        passengerRegWindow reg_window(arrPassFlights[sender()->property("row").toInt()].get_passenger_list());
        reg_window.exec();
        fileWrite(arrPassFlights);
    }
    if (sender()->property("type") == "depPass") {
        passengerRegWindow reg_window(depPassFlights[sender()->property("row").toInt()].get_passenger_list());
        reg_window.exec();
        fileWrite(depPassFlights);
    }
    vectorToTable();
}

void StartWindow::onCargoButtonClicked() {
    if (sender()->property("type") == "arrCargo") {
        CargoDialog cargoDialog(arrCargoFlights[sender()->property("row").toInt()].get_cargo_list());
        cargoDialog.exec();
        fileWrite(arrCargoFlights);
    }
    if (sender()->property("type") == "depCargo") {
        CargoDialog cargoDialog(depCargoFlights[sender()->property("row").toInt()].get_cargo_list());
        cargoDialog.exec();
        fileWrite(depCargoFlights);
    }
    vectorToTable();
}

void StartWindow::onCrewButtonClicked() {
    if (sender()->property("type") == "arrPass") {
        crewregdialog crewDialog(arrPassFlights[sender()->property("row").toInt()].get_crew_list());
        crewDialog.exec();
        fileWrite(arrPassFlights);
    }
    if (sender()->property("type") == "depPass") {
        crewregdialog crewDialog(depPassFlights[sender()->property("row").toInt()].get_crew_list());
        crewDialog.exec();
        fileWrite(depPassFlights);
    }
    vectorToTable();
}

void StartWindow::onEditButtonClicked() {
    backUp();
    if (sender()->property("type")=="arrPass") {
        PassengerFlightsAddDialog passengerFlightsAddDialog(arrPassFlights,true,sender()->property("row").toInt());
        passengerFlightsAddDialog.exec();
        fileWrite(arrPassFlights);
    }
    if (sender()->property("type")=="depPass") {
        PassengerDepartedFlightsAddDialog passengerDepartedFlightsAddDialog(depPassFlights,true,sender()->property("row").toInt());
        passengerDepartedFlightsAddDialog.exec();
        fileWrite(depPassFlights);
    }
    if (sender()->property("type")=="arrCargo") {
        CargoArrivedFlightsAddDialog cargoArrivedFlightsAddDialog(arrCargoFlights,true,sender()->property("row").toInt());
        cargoArrivedFlightsAddDialog.exec();
        fileWrite(arrCargoFlights);
    }
    if (sender()->property("type")=="depCargo") {
        DepartedCargoFlightsAddDialog departedCargoFlightsAddDialog(depCargoFlights,true,sender()->property("row").toInt());
        departedCargoFlightsAddDialog.exec();
        fileWrite(depCargoFlights);
    }
    vectorToTable();
}

void StartWindow::onDeleteButtonClicked() {
    if (!yesNoButton()) {
        return;
    }
    backUp();
    if (sender()->property("type")=="arrPass") {
        arrPassFlights.erase(arrPassFlights.begin() + sender()->property("row").toInt());
        fileWrite(arrPassFlights);
    }
    if (sender()->property("type")=="depPass") {
        depPassFlights.erase(depPassFlights.begin() + sender()->property("row").toInt());
        fileWrite(depPassFlights);
    }
    if (sender()->property("type")=="arrCargo") {
        arrCargoFlights.erase(arrCargoFlights.begin() + sender()->property("row").toInt());
        fileWrite(arrCargoFlights);
    }
    if (sender()->property("type")=="depCargo") {
        depCargoFlights.erase(depCargoFlights.begin() + sender()->property("row").toInt());
        fileWrite(depCargoFlights);
    }
    vectorToTable();
}

void StartWindow::vectorToTable() {
    if (isArrivedSelected) {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        for (auto &flight: arrPassFlights) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_flight_number())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_type())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2,
                                     new QTableWidgetItem(
                                         QString::number(flight.get_crew_list().size() + flight.get_pilots().size())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_runway())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_departure())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_arrive_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 7,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_late_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 8,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_customs_required_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 9,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_connecting_flight_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 10,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_emergency_landing_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 11,
                                     new QTableWidgetItem(QString::number(flight.get_passenger_list().size())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 12,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_gate())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 13,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_terminal())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 14,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_bus_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 15,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_baggage_claim_area())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 16,
                                     new QTableWidgetItem(
                                         QString::fromStdString(flight.get_special_assistance_required_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 17,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_visa_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 18,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_baggage_unloaded_str())));
            if (permission) {
                auto *pilotsbutton = new QPushButton("Pilots");
                connect(pilotsbutton, &QPushButton::clicked, this, &StartWindow::onPilotsButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 19, pilotsbutton);
                pilotsbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                pilotsbutton->setProperty("type", "arrPass");

                auto *passbutton = new QPushButton("Passengers");
                connect(passbutton, &QPushButton::clicked, this, &StartWindow::onPassengersButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 20, passbutton);
                passbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                passbutton->setProperty("type", "arrPass");

                auto *crewbutton = new QPushButton("Crew");
                connect(crewbutton, &QPushButton::clicked, this, &StartWindow::onCrewButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 21, crewbutton);
                crewbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                crewbutton->setProperty("type", "arrPass");

                auto *editbutton = new QPushButton("Edit");
                connect(editbutton, &QPushButton::clicked, this, &StartWindow::onEditButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 22, editbutton);
                editbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                editbutton->setProperty("type", "arrPass");

                auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
                connect(deletebutton, &QPushButton::clicked, this, &StartWindow::onDeleteButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 23, deletebutton);
                deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                deletebutton->setProperty("type", "arrPass");
            }
        }
        ui->tableWidget_2->setRowCount(0);
        ui->tableWidget_2->clearContents();
        for (auto &flight: arrCargoFlights) {
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 0,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_flight_number())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 1,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_type())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 2,
                                       new QTableWidgetItem(QString::number(flight.get_pilots().size())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 3,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_time())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 4,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_runway())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 5,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_departure())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 6,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_arrive_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 7,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_late_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 8,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_customs_required_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 9,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_connecting_flight_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 10,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_emergency_landing_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 11,
                                       new QTableWidgetItem(QString::number(flight.get_cargo_max_weight())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 12,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_cargo_type())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 13,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_cargo_unloaded_str())));
            if (permission) {
                auto *pilotsbutton = new QPushButton("Pilots");
                connect(pilotsbutton, &QPushButton::clicked, this, &StartWindow::onPilotsButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 14, pilotsbutton);
                pilotsbutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                pilotsbutton->setProperty("type", "arrCargo");

                auto *cargobutton = new QPushButton("Cargo");
                connect(cargobutton, &QPushButton::clicked, this, &StartWindow::onCargoButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 15, cargobutton);
                cargobutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                cargobutton->setProperty("type", "arrCargo");

                auto *editbutton = new QPushButton("Edit");
                connect(editbutton, &QPushButton::clicked, this, &StartWindow::onEditButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 16, editbutton);
                editbutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                editbutton->setProperty("type", "arrCargo");

                auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
                connect(deletebutton, &QPushButton::clicked, this, &StartWindow::onDeleteButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 17, deletebutton);
                deletebutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                deletebutton->setProperty("type", "arrCargo");
            }
        }
    }
    else {
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();
        for (auto &flight: depPassFlights) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_flight_number())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_type())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2,
                                     new QTableWidgetItem(
                                         QString::number(flight.get_crew_list().size() + flight.get_pilots().size())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_runway())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_depart_str())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_destination())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 7,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_status())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 8,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_fuel_status())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 9,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_status())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 10,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_terminal())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 11,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_gate())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 12,
                                     new QTableWidgetItem(QString::number(flight.get_passenger_max_value())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 13,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_terminal())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 14,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_check_in_start_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 15,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_check_in_end_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 16,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_boarding_start_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 17,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_boarding_end_time())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 18,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_baggage_loaded_str())));
            if (permission) {
                auto *pilotsbutton = new QPushButton("Pilots");
                connect(pilotsbutton, &QPushButton::clicked, this, &StartWindow::onPilotsButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 19, pilotsbutton);
                pilotsbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                pilotsbutton->setProperty("type", "depPass");

                auto *passbutton = new QPushButton("Passengers");
                connect(passbutton, &QPushButton::clicked, this, &StartWindow::onPassengersButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 20, passbutton);
                passbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                passbutton->setProperty("type", "depPass");

                auto *crewbutton = new QPushButton("Crew");
                connect(crewbutton, &QPushButton::clicked, this, &StartWindow::onCrewButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 21, crewbutton);
                crewbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                crewbutton->setProperty("type", "depPass");

                auto *editbutton = new QPushButton("Edit");
                connect(editbutton, &QPushButton::clicked, this, &StartWindow::onEditButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 22, editbutton);
                editbutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                editbutton->setProperty("type", "depPass");

                auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
                connect(deletebutton, &QPushButton::clicked, this, &StartWindow::onDeleteButtonClicked);
                ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 23, deletebutton);
                deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
                deletebutton->setProperty("type", "depPass");
            }
        }
        ui->tableWidget_2->setRowCount(0);
        ui->tableWidget_2->clearContents();
        for (auto &flight: depCargoFlights) {
            ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 0,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_flight_number())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 1,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_type())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 2,
                                       new QTableWidgetItem(QString::number(flight.get_pilots().size())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 3,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_time())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 4,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_runway())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 5,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_is_depart_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 6,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_destination())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 7,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_status())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 8,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_fuel_status())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 9,
                                     new QTableWidgetItem(QString::fromStdString(flight.get_aircraft_status())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 10,
                                       new QTableWidgetItem(QString::number(flight.get_cargo_max_weight())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 11,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_cargo_type())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 12,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_is_cargo_loaded_str())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 13,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_cargo_start_load_time())));
            ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount() - 1, 14,
                                       new QTableWidgetItem(QString::fromStdString(flight.get_cargo_end_load_time())));
            if (permission) {
                auto *pilotsbutton = new QPushButton("Pilots");
                connect(pilotsbutton, &QPushButton::clicked, this, &StartWindow::onPilotsButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 15, pilotsbutton);
                pilotsbutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                pilotsbutton->setProperty("type", "depCargo");

                auto *cargobutton = new QPushButton("Cargo");
                connect(cargobutton, &QPushButton::clicked, this, &StartWindow::onCargoButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 16, cargobutton);
                cargobutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                cargobutton->setProperty("type", "depCargo");

                auto *editbutton = new QPushButton("Edit");
                connect(editbutton, &QPushButton::clicked, this, &StartWindow::onEditButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 17, editbutton);
                editbutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                editbutton->setProperty("type", "depCargo");

                auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
                connect(deletebutton, &QPushButton::clicked, this, &StartWindow::onDeleteButtonClicked);
                ui->tableWidget_2->setCellWidget(ui->tableWidget_2->rowCount() - 1, 18, deletebutton);
                deletebutton->setProperty("row", ui->tableWidget_2->rowCount() - 1);
                deletebutton->setProperty("type", "depCargo");
            }
        }
    }
}

void StartWindow::backUp() {
    arrPassBackup.push(arrPassFlights);
    depPassBackup.push(depPassFlights);
    arrCargoBackup.push(arrCargoFlights);
    depCargoBackup.push(depCargoFlights);
}

void cargoRead(ifstream& in, vector<Cargo> &cargoes) {
    for (auto &cargo: cargoes) {
        cargo.set_name(readString(in));
        cargo.set_type(readString(in));
        double weight;
        in.read(reinterpret_cast<char *>(&weight), sizeof(weight));
        cargo.set_weight(weight);
        cargo.set_shipper(readString(in));
        cargo.set_receiver(readString(in));
    }
}
void crewRead(ifstream &in, vector<CrewMember> &crew_member) {
    int size;
    for (auto &crew: crew_member) {
        crew.set_name(readString(in));
        crew.set_surname(readString(in));
        crew.set_middle_name(readString(in));
        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        crew.set_age(size);
        crew.set_pass_num(readString(in));
        crew.set_pass_expiry_date(readString(in));
        crew.set_nationality(readString(in));
        crew.set_email(readString(in));
        crew.set_phone(readString(in));
        crew.set_languages(readString(in));
        crew.set_specialization(readString(in));
    }
}
void passengersRead(ifstream& in,vector<Passenger>& passengers) {
    int size;
    for (auto &passenger: passengers) {
        passenger.set_name(readString(in));
        passenger.set_surname(readString(in));
        passenger.set_middle_name(readString(in));
        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        passenger.set_age(size);
        passenger.set_pass_num(readString(in));
        passenger.set_pass_expiry_date(readString(in));
        passenger.set_nationality(readString(in));
        passenger.set_email(readString(in));
        passenger.set_phone(readString(in));
        passenger.set_visa_num(readString(in));
        passenger.set_has_travel_insurance_str(readString(in));
        passenger.set_requires_special_assistance_str(readString(in));
        passenger.set_passenger_class(readString(in));
        passenger.set_seat(readString(in));
        passenger.set_ticket_number(readString(in));
        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        passenger.set_bags(size);
    }
}
void pilotsRead(ifstream& in,vector<Pilot>& pilots) {
    int size;
    for (auto &pilot: pilots) {
        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        pilot.set_flight_hours(size);
        pilot.set_name(readString(in));
        pilot.set_surname(readString(in));
        pilot.set_middle_name(readString(in));
        in.read(reinterpret_cast<char *>(&size), sizeof(size));
        pilot.set_age(size);
        pilot.set_pass_num(readString(in));
        pilot.set_pass_expiry_date(readString(in));
        pilot.set_nationality(readString(in));
        pilot.set_email(readString(in));
        pilot.set_phone(readString(in));
        pilot.set_license_num(readString(in));
        pilot.set_license_expiry_date(readString(in));
        pilot.set_rank(readString(in));
        pilot.set_experience(readString(in));
    }
}
void cargoWrite(ofstream& out,const vector <Cargo>& cargoes) {
    int size = static_cast<int>(cargoes.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &cargo: cargoes){
        writeString(out, cargo.get_name());
        writeString(out, cargo.get_type());
        double weight = cargo.get_weight();
        out.write(reinterpret_cast<const char *>(&weight), sizeof(weight));
        writeString(out, cargo.get_shipper());
        writeString(out, cargo.get_receiver());
    }
}
void crewWrite(ofstream& out,vector <CrewMember>& crew_member){
    int size = static_cast<int>(crew_member.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &crew: crew_member) {
        writeString(out, crew.get_name());
        writeString(out, crew.get_surname());
        writeString(out, crew.get_middle_name());
        size = crew.get_age();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));
        writeString(out, crew.get_pass_num());
        writeString(out, crew.get_pass_expiry_date());
        writeString(out, crew.get_nationality());
        writeString(out, crew.get_email());
        writeString(out, crew.get_phone());
        writeString(out, crew.get_languages());
        writeString(out, crew.get_specialization());
    }
}
void pilotsWrite(ofstream& out,vector <Pilot>& pilots) {
    int size = static_cast<int>(pilots.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &pilot: pilots) {
        size = pilot.get_flight_hours();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));
        writeString(out, pilot.get_name());
        writeString(out, pilot.get_surname());
        writeString(out, pilot.get_middle_name());
        size = pilot.get_age();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));
        writeString(out, pilot.get_pass_num());
        writeString(out, pilot.get_pass_expiry_date());
        writeString(out, pilot.get_nationality());
        writeString(out, pilot.get_email());
        writeString(out, pilot.get_phone());
        writeString(out, pilot.get_license_num());
        writeString(out, pilot.get_license_expiry_date());
        writeString(out, pilot.get_rank());
        writeString(out, pilot.get_experience());
    }
}
void passengersWrite(ofstream& out,vector <Passenger>& passengers) {
    int size = static_cast<int>(passengers.size());
    out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &passenger: passengers) {
        writeString(out, passenger.get_name());
        writeString(out, passenger.get_surname());
        writeString(out, passenger.get_middle_name());
        size = passenger.get_age();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));
        writeString(out, passenger.get_pass_num());
        writeString(out, passenger.get_pass_expiry_date());
        writeString(out, passenger.get_nationality());
        writeString(out, passenger.get_email());
        writeString(out, passenger.get_phone());
        writeString(out, passenger.get_visa_num());
        writeString(out, passenger.get_has_travel_insurance_str());
        writeString(out, passenger.get_requires_special_assistance_str());
        writeString(out, passenger.get_passenger_class());
        writeString(out, passenger.get_seat());
        writeString(out, passenger.get_ticket_number());
        size = passenger.get_bags();
        out.write(reinterpret_cast<const char *>(&size), sizeof(size));
    }
}

bool StartWindow::yesNoButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Are you sure?", "Delete?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}

