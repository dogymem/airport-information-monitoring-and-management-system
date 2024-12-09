//
// Created by Егор Томашев on 22.10.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_passengerRegWindow.h" resolved

#include "passengerregwindow.h"

#include <QMessageBox>

#include "ui_passengerRegWindow.h"


passengerRegWindow::passengerRegWindow(vector<Passenger>& passengers,QWidget *parent) :
    QDialog(parent), ui(new Ui::passengerRegWindow), passengers(passengers) {
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(3,30);
    ui->tableWidget->setColumnWidth(4,100);
    ui->tableWidget->setColumnWidth(5,80);
    ui->tableWidget->setColumnWidth(6,70);
    ui->tableWidget->setColumnWidth(10,40);
    ui->tableWidget->setColumnWidth(11,30);
    ui->tableWidget->setColumnWidth(13,50);
    ui->tableWidget->setColumnWidth(14,40);
    ui->tableWidget->setColumnWidth(15,40);
    ui->tableWidget->setColumnWidth(16,40);
    ui->passDate->setMinimumDate(QDate::currentDate());
    ui->passDate->setDate(QDate::currentDate());
    connect(ui->add, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    connect(ui->name, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->surname, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->middle, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->passNum, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->passDate, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->nationality, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->phone, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->visaNum, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->passengerClass, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->seat, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->ticketNumber, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(onUndoClick()));
    if (!passengers.empty()) {
        vectorToTable();
    }
}

passengerRegWindow::~passengerRegWindow() {
    delete ui;
}

void passengerRegWindow::on_addButton_clicked() {
    backUpPassengers.push(passengers);
    Passenger buffer;
    buffer.set_name(ui->name->text().toStdString());
    buffer.set_surname(ui->surname->text().toStdString());
    buffer.set_middle_name(ui->middle->text().toStdString());
    buffer.set_age(ui->Age->text().toInt());
    buffer.set_pass_num(ui->passNum->text().toStdString());
    buffer.set_pass_expiry_date(ui->passDate->text().toStdString());
    buffer.set_nationality(ui->nationality->text().toStdString());
    buffer.set_email(ui->email->text().toStdString());
    buffer.set_phone(ui->phone->text().toStdString());
    buffer.set_visa_num(ui->visaNum->text().toStdString());
    buffer.set_has_travel_insurance(ui->travelInsurance->isChecked());
    buffer.set_requires_special_assistance(ui->assistance->isChecked());
    buffer.set_passenger_class(ui->passengerClass->text().toStdString());
    buffer.set_seat(ui->seat->text().toStdString());
    buffer.set_ticket_number(ui->ticketNumber->text().toStdString());
    buffer.set_bags(ui->bags->text().toInt());
    passengers.push_back(buffer);
    vectorToTable();
    ui->name->clear();
    ui->surname->clear();
    ui->middle->clear();
    ui->Age->setValue(1);
    ui->passNum->clear();
    ui->nationality->clear();
    ui->email->clear();
    ui->phone->clear();
    ui->visaNum->clear();
    ui->travelInsurance->setChecked(false);
    ui->assistance->setChecked(false);
    ui->passengerClass->clear();
    ui->seat->clear();
    ui->ticketNumber->clear();
    ui->bags->setValue(1);
    ui->add->setEnabled(false);
}

void passengerRegWindow::vectorToTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(auto& passenger : passengers) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(passenger.get_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(passenger.get_surname())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::fromStdString(passenger.get_middle_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(passenger.get_age())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::fromStdString(passenger.get_pass_num())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(QString::fromStdString(passenger.get_pass_expiry_date())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, new QTableWidgetItem(QString::fromStdString(passenger.get_nationality())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 7, new QTableWidgetItem(QString::fromStdString(passenger.get_email())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 8, new QTableWidgetItem(QString::fromStdString(passenger.get_phone())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 9, new QTableWidgetItem(QString::fromStdString(passenger.get_visa_num())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 10, new QTableWidgetItem(QString::fromStdString(passenger.get_passenger_class())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 11, new QTableWidgetItem(QString::fromStdString(passenger.get_seat())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 12, new QTableWidgetItem(QString::fromStdString(passenger.get_ticket_number())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 13, new QTableWidgetItem(QString::number(passenger.get_bags())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 14, new QTableWidgetItem(QString::fromStdString(passenger.get_has_travel_insurance_str())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 15, new QTableWidgetItem(QString::fromStdString(passenger.get_requires_special_assistance_str())));
        auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
        connect(deletebutton, &QPushButton::clicked, this, &passengerRegWindow::onDeleteButtonClicked);
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 16, deletebutton);
        deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
    }
}

void passengerRegWindow::addActivation() {
    ui->add->setEnabled(!(ui->name->text().isEmpty()|| ui->surname->text().isEmpty() || ui->passNum->text().isEmpty() || ui->passDate->text().isEmpty() || ui->nationality->text().isEmpty() || ui->email->text().isEmpty() || ui->phone->text().isEmpty() || ui->visaNum->text().isEmpty() || ui->passengerClass->text().isEmpty() || ui->seat->text().isEmpty() || ui->ticketNumber->text().isEmpty()));
}

void passengerRegWindow::onUndoClick() {
    try {
        passengers = backUpPassengers.pop();
    }catch(const char*) {
        //qmsg
    }
    vectorToTable();
}
void passengerRegWindow::onDeleteButtonClicked() {
    if (!yesNoButton()) {
        return;
    }
    backUpPassengers.push(passengers);
    passengers.erase(passengers.begin() + sender()->property("row").toInt());
    vectorToTable();
}

bool passengerRegWindow::yesNoButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Are you sure?", "Delete?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}
