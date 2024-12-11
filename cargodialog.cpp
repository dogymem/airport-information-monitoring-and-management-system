//
// Created by Егор Томашев on 19.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CargoDialog.h" resolved

#include "cargodialog.h"

#include <QMessageBox>

#include "clases.h"
#include "Exception.h"
#include "ui_CargoDialog.h"

CargoDialog::CargoDialog(vector<Cargo>& cargo,QWidget *parent) :
    QDialog(parent), ui(new Ui::CargoDialog), cargo(cargo) {
    ui->setupUi(this);
    connect(ui->add, SIGNAL(clicked()), this, SLOT(onAddButtonClick()));
    connect(ui->name, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->type, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->shipper, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->receiver, SIGNAL(textChanged(QString)), this, SLOT(addActivation()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(onUndoClick()));
    vectorToTable();
}

CargoDialog::~CargoDialog() {
    delete ui;
}

void CargoDialog::addActivation() {
    ui->add->setEnabled(!(ui->name->text().isEmpty()|| ui->type->text().isEmpty() || ui->shipper->text().isEmpty() || ui->receiver->text().isEmpty() || ui->weight->text().isEmpty()));

}

void CargoDialog::onUndoClick() {
    try {
        cargo = backUpCargo.pop();
    }catch(const char*) {
        //qmsg
    }
    vectorToTable();
}

void CargoDialog::onAddButtonClick() {
    backUpCargo.push(cargo);
    Cargo buffer;
    try{
        buffer.set_name(ui->name->text().toStdString());
        buffer.set_type(ui->type->text().toStdString());
        buffer.set_shipper(ui->shipper->text().toStdString());
        buffer.set_receiver(ui->receiver->text().toStdString());
        buffer.set_weight(ui->weight->text().toInt());
    }catch (cargoException& e) {
        e.showMessage();
        return;
    }
    cargo.push_back(buffer);
    ui->name->clear();
    ui->type->clear();
    ui->shipper->clear();
    ui->receiver->clear();
    ui->weight->clear();
    vectorToTable();
}

void CargoDialog::vectorToTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(cargo.size());
    for (int i=0;i<cargo.size();i++) {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::fromStdString(cargo[i].get_name())));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::fromStdString(cargo[i].get_type())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::fromStdString(cargo[i].get_shipper())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::fromStdString(cargo[i].get_receiver())));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(cargo[i].get_weight())));
        auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
        connect(deletebutton, &QPushButton::clicked, this, &CargoDialog::onDeleteButtonClicked);
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 5, deletebutton);
        deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
    }
}

void CargoDialog::onDeleteButtonClicked() {
    if (!yesNoButton()) {
        return;
    }
    backUpCargo.push(cargo);
    cargo.erase(cargo.begin() + sender()->property("row").toInt());
    vectorToTable();
}

bool CargoDialog::yesNoButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Are you sure?", "Delete?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}
