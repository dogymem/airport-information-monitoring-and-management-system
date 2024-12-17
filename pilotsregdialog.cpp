//
// Created by Егор Томашев on 12.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PilotsRegDialog.h" resolved

#include "pilotsregdialog.h"

#include <QMessageBox>

#include "clases.h"
#include "Exception.h"
#include "ui_PilotsRegDialog.h"


PilotsRegDialog::PilotsRegDialog(std::vector <Pilot>& pilots,QWidget *parent) :
    QDialog(parent), ui(new Ui::PilotsRegDialog), pilots(pilots){
    ui->setupUi(this);
    ui->passDate->setMinimumDate(QDate::currentDate());
    ui->passDate->setDate(QDate::currentDate());
    ui->licenseexpiredate->setMinimumDate(QDate::currentDate());
    ui->licenseexpiredate->setDate(QDate::currentDate());
    connect(ui->add, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(onUndoClick()));
    connect(ui->name, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->surname, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->middle, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->passNum, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->nationality, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->phone, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->licenseNum, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->licenseexpiredate, SIGNAL(dateChanged(QDate)), this, SLOT(addActivation()));
    connect(ui->rank, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->experience, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->flighthours, SIGNAL(textChanged(QString)), this, SLOT(addActivation()));
    if (!pilots.empty()) {
        vectorToTable();
    }
}

PilotsRegDialog::~PilotsRegDialog() {
    delete ui;
}

void PilotsRegDialog::addActivation() {
    ui->add->setEnabled(!(ui->name->text().isEmpty()|| ui->surname->text().isEmpty() || ui->middle->text().isEmpty() || ui->passNum->text().isEmpty() || ui->passDate->text().isEmpty() || ui->nationality->text().isEmpty() || ui->email->text().isEmpty() || ui->phone->text().isEmpty() || ui->licenseNum->text().isEmpty() || ui->licenseexpiredate->text().isEmpty() || ui->rank->text().isEmpty() || ui->experience->text().isEmpty()));
}

void PilotsRegDialog::on_addButton_clicked() {
    backUpPilots.push(pilots);
    Pilot buffer;
    try {
        buffer.set_name(ui->name->text().toStdString());
        buffer.set_surname(ui->surname->text().toStdString());
        buffer.set_middle_name(ui->middle->text().toStdString());
        buffer.set_age(ui->Age->text().toInt());
        buffer.set_pass_num(ui->passNum->text().toStdString());
        buffer.set_pass_expiry_date(ui->passDate->text().toStdString());
        buffer.set_nationality(ui->nationality->text().toStdString());
        buffer.set_email(ui->email->text().toStdString());
        buffer.set_phone(ui->phone->text().toStdString());
        buffer.set_license_num(ui->licenseNum->text().toStdString());
        buffer.set_license_expiry_date(ui->licenseexpiredate->text().toStdString());
        buffer.set_rank(ui->rank->text().toStdString());
        buffer.set_experience(ui->experience->text().toStdString());
        buffer.set_flight_hours(ui->flighthours->text().toInt());
    } catch (humanException &e) {
        e.showMessage();
        return;
    }
    catch (pilotException &e) {
        e.showMessage();
        return;
    }
    pilots.push_back(buffer);
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    vectorToTable();
    ui->name->clear();
    ui->surname->clear();
    ui->middle->clear();
    ui->Age->setValue(1);
    ui->passNum->clear();
    ui->nationality->clear();
    ui->email->clear();
    ui->phone->clear();
    ui->licenseNum->clear();
    ui->licenseexpiredate->clear();
    ui->rank->clear();
    ui->experience->clear();
    ui->flighthours->clear();
    ui->add->setEnabled(false);
}

void PilotsRegDialog::onUndoClick() {
    try {
        pilots = backUpPilots.pop();
    }catch(StackException& e) {
        e.showMessage();
    }
    vectorToTable();
}

void PilotsRegDialog::vectorToTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
      for(auto& pilot : pilots) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 16,new QPushButton("Del"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(pilot.get_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(pilot.get_surname())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::fromStdString(pilot.get_middle_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(pilot.get_age())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::fromStdString(pilot.get_pass_num())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(QString::fromStdString(pilot.get_pass_expiry_date())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, new QTableWidgetItem(QString::fromStdString(pilot.get_nationality())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 7, new QTableWidgetItem(QString::fromStdString(pilot.get_email())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 8, new QTableWidgetItem(QString::fromStdString(pilot.get_phone())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 9, new QTableWidgetItem(QString::fromStdString(pilot.get_license_num())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 10, new QTableWidgetItem(QString::fromStdString(pilot.get_license_expiry_date())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 11, new QTableWidgetItem(QString::fromStdString(pilot.get_rank())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 12, new QTableWidgetItem(QString::fromStdString(pilot.get_experience())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 13, new QTableWidgetItem(QString::number(pilot.get_flight_hours())));
          auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
          connect(deletebutton, &QPushButton::clicked, this, &PilotsRegDialog::onDeleteButtonClicked);
          ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 14, deletebutton);
          deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
    }
}

void PilotsRegDialog::onDeleteButtonClicked() {
    if (!yesNoButton()) {
        return;
    }
    backUpPilots.push(pilots);
    pilots.erase(pilots.begin() + sender()->property("row").toInt());
    vectorToTable();
}

bool PilotsRegDialog::yesNoButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Are you sure?", "Delete?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}