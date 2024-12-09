//
// Created by Егор Томашев on 13.11.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_crewregdialog.h" resolved

#include "crewregdialog.h"

#include <QMessageBox>

#include "ui_crewregdialog.h"


crewregdialog::crewregdialog(std::vector <CrewMember>& crew,QWidget *parent) :
    QDialog(parent), ui(new Ui::crewregdialog), crew(crew){
    ui->setupUi(this);
    ui->passDate->setMinimumDate(QDate::currentDate());
    ui->passDate->setDate(QDate::currentDate());
    connect(ui->add, SIGNAL(clicked()), this, SLOT(on_addButton_clicked()));
    connect(ui->name, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->surname, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->middle, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->Age, SIGNAL(textChanged(QString)), this, SLOT(addActivation()));
    connect(ui->passNum, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->passDate, SIGNAL(textEdited(QDate)), this, SLOT(addActivation()));
    connect(ui->nationality, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->email, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->phone, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->language, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->specialization, SIGNAL(textEdited(QString)), this, SLOT(addActivation()));
    connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(onUndoClick()));
    if (!crew.empty()) {
        vectorToTable();
    }
}

crewregdialog::~crewregdialog() {
    delete ui;
}

void crewregdialog::onUndoClick() {
    try {
        crew = backUpCrew.pop();
    }catch(const char*) {
        //qmsg
    }
    vectorToTable();
}

void crewregdialog::addActivation() {
    ui->add->setEnabled(!(ui->name->text().isEmpty()|| ui->surname->text().isEmpty() || ui->middle->text().isEmpty() || ui->passNum->text().isEmpty() || ui->passDate->text().isEmpty() || ui->nationality->text().isEmpty() || ui->email->text().isEmpty() || ui->phone->text().isEmpty() || ui->language->text().isEmpty() || ui->specialization->text().isEmpty()));
}

void crewregdialog::on_addButton_clicked() {
    backUpCrew.push(crew);
    CrewMember buffer;
    buffer.set_name(ui->name->text().toStdString());
    buffer.set_surname(ui->surname->text().toStdString());
    buffer.set_middle_name(ui->middle->text().toStdString());
    buffer.set_age(ui->Age->text().toInt());
    buffer.set_pass_num(ui->passNum->text().toStdString());
    buffer.set_pass_expiry_date(ui->passDate->text().toStdString());
    buffer.set_nationality(ui->nationality->text().toStdString());
    buffer.set_email(ui->email->text().toStdString());
    buffer.set_phone(ui->phone->text().toStdString());
    buffer.set_languages(ui->language->text().toStdString());
    buffer.set_specialization(ui->specialization->text().toStdString());
    crew.push_back(buffer);
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
    ui->language->clear();
    ui->specialization->clear();
    ui->add->setEnabled(false);
}

void crewregdialog::vectorToTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    for(auto& crewMember : crew) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1, 16,new QPushButton("Del"));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(crewMember.get_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(crewMember.get_surname())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, new QTableWidgetItem(QString::fromStdString(crewMember.get_middle_name())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, new QTableWidgetItem(QString::number(crewMember.get_age())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, new QTableWidgetItem(QString::fromStdString(crewMember.get_pass_num())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 5, new QTableWidgetItem(QString::fromStdString(crewMember.get_pass_expiry_date())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 6, new QTableWidgetItem(QString::fromStdString(crewMember.get_nationality())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 7, new QTableWidgetItem(QString::fromStdString(crewMember.get_email())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 8, new QTableWidgetItem(QString::fromStdString(crewMember.get_phone())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 9, new QTableWidgetItem(QString::fromStdString(crewMember.get_languages())));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 10, new QTableWidgetItem(QString::fromStdString(crewMember.get_specialization())));
        auto *deletebutton = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::ListRemove),"Delete");
        connect(deletebutton, &QPushButton::clicked, this, &crewregdialog::onDeleteButtonClicked);
        ui->tableWidget->setCellWidget(ui->tableWidget->rowCount() - 1, 11, deletebutton);
        deletebutton->setProperty("row", ui->tableWidget->rowCount() - 1);
    }
}

void crewregdialog::onDeleteButtonClicked() {
    if (!yesNoButton()) {
        return;
    }
    backUpCrew.push(crew);
    crew.erase(crew.begin() + sender()->property("row").toInt());
    vectorToTable();
}

bool crewregdialog::yesNoButton() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Are you sure?", "Delete?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        return true;
    } else {
        return false;
    }
}
