/********************************************************************************
** Form generated from reading UI file 'DepartedCargoFlightsAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTEDCARGOFLIGHTSADDDIALOG_H
#define UI_DEPARTEDCARGOFLIGHTSADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_DepartedCargoFlightsAddDialog
{
public:
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *maxWeight;
    QDateTimeEdit *time;
    QTimeEdit *cargoStartTime;
    QPushButton *AddButton;
    QLineEdit *aircrafttype;
    QCheckBox *isDepart;
    QLineEdit *flightnumber;
    QCheckBox *cargoLoadded;
    QTimeEdit *cargoEndTime;
    QLineEdit *aircraftStatus;
    QLineEdit *status;
    QLineEdit *fuelStatus;
    QLineEdit *type;
    QLineEdit *runway;
    QLineEdit *destination;

    void setupUi(QDialog *DepartedCargoFlightsAddDialog)
    {
        if (DepartedCargoFlightsAddDialog->objectName().isEmpty())
            DepartedCargoFlightsAddDialog->setObjectName("DepartedCargoFlightsAddDialog");
        DepartedCargoFlightsAddDialog->resize(517, 571);
        DepartedCargoFlightsAddDialog->setMinimumSize(QSize(0, 0));
        DepartedCargoFlightsAddDialog->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(DepartedCargoFlightsAddDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        maxWeight = new QDoubleSpinBox(DepartedCargoFlightsAddDialog);
        maxWeight->setObjectName("maxWeight");

        gridLayout_2->addWidget(maxWeight, 13, 0, 1, 1);

        time = new QDateTimeEdit(DepartedCargoFlightsAddDialog);
        time->setObjectName("time");
        time->setDateTime(QDateTime(QDate(2000, 12, 31), QTime(23, 0, 0)));

        gridLayout_2->addWidget(time, 3, 0, 1, 1);

        cargoStartTime = new QTimeEdit(DepartedCargoFlightsAddDialog);
        cargoStartTime->setObjectName("cargoStartTime");

        gridLayout_2->addWidget(cargoStartTime, 14, 0, 1, 1);

        AddButton = new QPushButton(DepartedCargoFlightsAddDialog);
        AddButton->setObjectName("AddButton");
        AddButton->setEnabled(false);

        gridLayout_2->addWidget(AddButton, 16, 0, 1, 1);

        aircrafttype = new QLineEdit(DepartedCargoFlightsAddDialog);
        aircrafttype->setObjectName("aircrafttype");

        gridLayout_2->addWidget(aircrafttype, 1, 0, 1, 1);

        isDepart = new QCheckBox(DepartedCargoFlightsAddDialog);
        isDepart->setObjectName("isDepart");

        gridLayout_2->addWidget(isDepart, 11, 0, 1, 1);

        flightnumber = new QLineEdit(DepartedCargoFlightsAddDialog);
        flightnumber->setObjectName("flightnumber");

        gridLayout_2->addWidget(flightnumber, 0, 0, 1, 1);

        cargoLoadded = new QCheckBox(DepartedCargoFlightsAddDialog);
        cargoLoadded->setObjectName("cargoLoadded");

        gridLayout_2->addWidget(cargoLoadded, 10, 0, 1, 1);

        cargoEndTime = new QTimeEdit(DepartedCargoFlightsAddDialog);
        cargoEndTime->setObjectName("cargoEndTime");

        gridLayout_2->addWidget(cargoEndTime, 15, 0, 1, 1);

        aircraftStatus = new QLineEdit(DepartedCargoFlightsAddDialog);
        aircraftStatus->setObjectName("aircraftStatus");

        gridLayout_2->addWidget(aircraftStatus, 9, 0, 1, 1);

        status = new QLineEdit(DepartedCargoFlightsAddDialog);
        status->setObjectName("status");

        gridLayout_2->addWidget(status, 7, 0, 1, 1);

        fuelStatus = new QLineEdit(DepartedCargoFlightsAddDialog);
        fuelStatus->setObjectName("fuelStatus");

        gridLayout_2->addWidget(fuelStatus, 8, 0, 1, 1);

        type = new QLineEdit(DepartedCargoFlightsAddDialog);
        type->setObjectName("type");

        gridLayout_2->addWidget(type, 12, 0, 1, 1);

        runway = new QLineEdit(DepartedCargoFlightsAddDialog);
        runway->setObjectName("runway");

        gridLayout_2->addWidget(runway, 4, 0, 1, 1);

        destination = new QLineEdit(DepartedCargoFlightsAddDialog);
        destination->setObjectName("destination");

        gridLayout_2->addWidget(destination, 6, 0, 1, 1);


        retranslateUi(DepartedCargoFlightsAddDialog);

        QMetaObject::connectSlotsByName(DepartedCargoFlightsAddDialog);
    } // setupUi

    void retranslateUi(QDialog *DepartedCargoFlightsAddDialog)
    {
        DepartedCargoFlightsAddDialog->setWindowTitle(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Add flight", nullptr));
        AddButton->setText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Add", nullptr));
        aircrafttype->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Aircraft type", nullptr));
        isDepart->setText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Depated?", nullptr));
        flightnumber->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Flight number", nullptr));
        cargoLoadded->setText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Cargo loaded?", nullptr));
        aircraftStatus->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Aircraft status", nullptr));
        status->setText(QString());
        status->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Status", nullptr));
        fuelStatus->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Fuel status", nullptr));
        type->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Cargo type", nullptr));
        runway->setText(QString());
        runway->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Runway", nullptr));
        destination->setPlaceholderText(QCoreApplication::translate("DepartedCargoFlightsAddDialog", "Destination", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartedCargoFlightsAddDialog: public Ui_DepartedCargoFlightsAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTEDCARGOFLIGHTSADDDIALOG_H
