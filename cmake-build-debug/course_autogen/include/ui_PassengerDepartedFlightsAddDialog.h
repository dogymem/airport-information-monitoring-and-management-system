/********************************************************************************
** Form generated from reading UI file 'passengerdepartedflightsadddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERDEPARTEDFLIGHTSADDDIALOG_H
#define UI_PASSENGERDEPARTEDFLIGHTSADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_PassengerDepartedFlightsAddDialog
{
public:
    QGridLayout *gridLayout_2;
    QLineEdit *aircrafttype;
    QLineEdit *fuelStatus;
    QLineEdit *status;
    QSpinBox *passMax;
    QCheckBox *baggageLoadded;
    QDateTimeEdit *time;
    QLineEdit *destination;
    QLineEdit *terminal;
    QLineEdit *aircraftStatus;
    QTimeEdit *boardingEndTime;
    QLineEdit *flightnumber;
    QTimeEdit *boardingStartTime;
    QLineEdit *runway;
    QTimeEdit *checkInStartTime;
    QTimeEdit *checkInEndTime;
    QPushButton *AddButton;
    QLineEdit *gate;
    QCheckBox *isDepart;

    void setupUi(QDialog *PassengerDepartedFlightsAddDialog)
    {
        if (PassengerDepartedFlightsAddDialog->objectName().isEmpty())
            PassengerDepartedFlightsAddDialog->setObjectName("PassengerDepartedFlightsAddDialog");
        PassengerDepartedFlightsAddDialog->resize(517, 571);
        PassengerDepartedFlightsAddDialog->setMinimumSize(QSize(0, 0));
        PassengerDepartedFlightsAddDialog->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(PassengerDepartedFlightsAddDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        aircrafttype = new QLineEdit(PassengerDepartedFlightsAddDialog);
        aircrafttype->setObjectName("aircrafttype");

        gridLayout_2->addWidget(aircrafttype, 1, 0, 1, 1);

        fuelStatus = new QLineEdit(PassengerDepartedFlightsAddDialog);
        fuelStatus->setObjectName("fuelStatus");

        gridLayout_2->addWidget(fuelStatus, 8, 0, 1, 1);

        status = new QLineEdit(PassengerDepartedFlightsAddDialog);
        status->setObjectName("status");

        gridLayout_2->addWidget(status, 7, 0, 1, 1);

        passMax = new QSpinBox(PassengerDepartedFlightsAddDialog);
        passMax->setObjectName("passMax");
        passMax->setMinimum(1);
        passMax->setMaximum(500);

        gridLayout_2->addWidget(passMax, 14, 0, 1, 1);

        baggageLoadded = new QCheckBox(PassengerDepartedFlightsAddDialog);
        baggageLoadded->setObjectName("baggageLoadded");

        gridLayout_2->addWidget(baggageLoadded, 10, 0, 1, 1);

        time = new QDateTimeEdit(PassengerDepartedFlightsAddDialog);
        time->setObjectName("time");
        time->setSpecialValueText(QString::fromUtf8(""));
        time->setDateTime(QDateTime(QDate(2000, 12, 31), QTime(23, 0, 0)));
        time->setCalendarPopup(true);

        gridLayout_2->addWidget(time, 3, 0, 1, 1);

        destination = new QLineEdit(PassengerDepartedFlightsAddDialog);
        destination->setObjectName("destination");

        gridLayout_2->addWidget(destination, 6, 0, 1, 1);

        terminal = new QLineEdit(PassengerDepartedFlightsAddDialog);
        terminal->setObjectName("terminal");

        gridLayout_2->addWidget(terminal, 12, 0, 1, 1);

        aircraftStatus = new QLineEdit(PassengerDepartedFlightsAddDialog);
        aircraftStatus->setObjectName("aircraftStatus");

        gridLayout_2->addWidget(aircraftStatus, 9, 0, 1, 1);

        boardingEndTime = new QTimeEdit(PassengerDepartedFlightsAddDialog);
        boardingEndTime->setObjectName("boardingEndTime");

        gridLayout_2->addWidget(boardingEndTime, 18, 0, 1, 1);

        flightnumber = new QLineEdit(PassengerDepartedFlightsAddDialog);
        flightnumber->setObjectName("flightnumber");

        gridLayout_2->addWidget(flightnumber, 0, 0, 1, 1);

        boardingStartTime = new QTimeEdit(PassengerDepartedFlightsAddDialog);
        boardingStartTime->setObjectName("boardingStartTime");

        gridLayout_2->addWidget(boardingStartTime, 17, 0, 1, 1);

        runway = new QLineEdit(PassengerDepartedFlightsAddDialog);
        runway->setObjectName("runway");

        gridLayout_2->addWidget(runway, 4, 0, 1, 1);

        checkInStartTime = new QTimeEdit(PassengerDepartedFlightsAddDialog);
        checkInStartTime->setObjectName("checkInStartTime");

        gridLayout_2->addWidget(checkInStartTime, 15, 0, 1, 1);

        checkInEndTime = new QTimeEdit(PassengerDepartedFlightsAddDialog);
        checkInEndTime->setObjectName("checkInEndTime");

        gridLayout_2->addWidget(checkInEndTime, 16, 0, 1, 1);

        AddButton = new QPushButton(PassengerDepartedFlightsAddDialog);
        AddButton->setObjectName("AddButton");
        AddButton->setEnabled(false);

        gridLayout_2->addWidget(AddButton, 19, 0, 1, 1);

        gate = new QLineEdit(PassengerDepartedFlightsAddDialog);
        gate->setObjectName("gate");

        gridLayout_2->addWidget(gate, 13, 0, 1, 1);

        isDepart = new QCheckBox(PassengerDepartedFlightsAddDialog);
        isDepart->setObjectName("isDepart");

        gridLayout_2->addWidget(isDepart, 11, 0, 1, 1);


        retranslateUi(PassengerDepartedFlightsAddDialog);

        QMetaObject::connectSlotsByName(PassengerDepartedFlightsAddDialog);
    } // setupUi

    void retranslateUi(QDialog *PassengerDepartedFlightsAddDialog)
    {
        PassengerDepartedFlightsAddDialog->setWindowTitle(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "PassengerDepartedFlightsAddDialog", nullptr));
        aircrafttype->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Aircraft type", nullptr));
        fuelStatus->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Fuel status", nullptr));
        status->setText(QString());
        status->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Status", nullptr));
        baggageLoadded->setText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Baggage loaded?", nullptr));
#if QT_CONFIG(whatsthis)
        time->setWhatsThis(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Departure time", nullptr));
#endif // QT_CONFIG(whatsthis)
        destination->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Destination", nullptr));
        terminal->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Terminal", nullptr));
        aircraftStatus->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Aircraft status", nullptr));
        flightnumber->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Flight number", nullptr));
        runway->setText(QString());
        runway->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Runway", nullptr));
        AddButton->setText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Add", nullptr));
        gate->setPlaceholderText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Gate", nullptr));
        isDepart->setText(QCoreApplication::translate("PassengerDepartedFlightsAddDialog", "Depated?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerDepartedFlightsAddDialog: public Ui_PassengerDepartedFlightsAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERDEPARTEDFLIGHTSADDDIALOG_H
