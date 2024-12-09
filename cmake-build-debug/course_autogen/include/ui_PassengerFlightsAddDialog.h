/********************************************************************************
** Form generated from reading UI file 'PassengerFlightsAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERFLIGHTSADDDIALOG_H
#define UI_PASSENGERFLIGHTSADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PassengerFlightsAddDialog
{
public:
    QGridLayout *gridLayout_2;
    QDateTimeEdit *time;
    QLineEdit *departure;
    QLineEdit *flightnumber;
    QLineEdit *aircrafttype;
    QGridLayout *gridLayout;
    QCheckBox *emergency;
    QCheckBox *connecting;
    QCheckBox *assistans;
    QCheckBox *visa;
    QCheckBox *customs;
    QCheckBox *baggageUnloadded;
    QCheckBox *late;
    QCheckBox *isArrived;
    QCheckBox *bus;
    QLineEdit *gate;
    QLineEdit *runway;
    QLineEdit *terminal;
    QLineEdit *baggagearea;
    QPushButton *AddButton;

    void setupUi(QDialog *PassengerFlightsAddDialog)
    {
        if (PassengerFlightsAddDialog->objectName().isEmpty())
            PassengerFlightsAddDialog->setObjectName("PassengerFlightsAddDialog");
        PassengerFlightsAddDialog->resize(517, 571);
        PassengerFlightsAddDialog->setMinimumSize(QSize(0, 0));
        PassengerFlightsAddDialog->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(PassengerFlightsAddDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        time = new QDateTimeEdit(PassengerFlightsAddDialog);
        time->setObjectName("time");
        time->setDateTime(QDateTime(QDate(2000, 12, 31), QTime(23, 0, 0)));
        time->setCalendarPopup(true);

        gridLayout_2->addWidget(time, 3, 0, 1, 1);

        departure = new QLineEdit(PassengerFlightsAddDialog);
        departure->setObjectName("departure");

        gridLayout_2->addWidget(departure, 6, 0, 1, 1);

        flightnumber = new QLineEdit(PassengerFlightsAddDialog);
        flightnumber->setObjectName("flightnumber");

        gridLayout_2->addWidget(flightnumber, 0, 0, 1, 1);

        aircrafttype = new QLineEdit(PassengerFlightsAddDialog);
        aircrafttype->setObjectName("aircrafttype");

        gridLayout_2->addWidget(aircrafttype, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        emergency = new QCheckBox(PassengerFlightsAddDialog);
        emergency->setObjectName("emergency");

        gridLayout->addWidget(emergency, 2, 0, 1, 1);

        connecting = new QCheckBox(PassengerFlightsAddDialog);
        connecting->setObjectName("connecting");

        gridLayout->addWidget(connecting, 1, 1, 1, 1);

        assistans = new QCheckBox(PassengerFlightsAddDialog);
        assistans->setObjectName("assistans");

        gridLayout->addWidget(assistans, 3, 0, 1, 1);

        visa = new QCheckBox(PassengerFlightsAddDialog);
        visa->setObjectName("visa");

        gridLayout->addWidget(visa, 3, 1, 1, 1);

        customs = new QCheckBox(PassengerFlightsAddDialog);
        customs->setObjectName("customs");

        gridLayout->addWidget(customs, 1, 0, 1, 1);

        baggageUnloadded = new QCheckBox(PassengerFlightsAddDialog);
        baggageUnloadded->setObjectName("baggageUnloadded");

        gridLayout->addWidget(baggageUnloadded, 4, 0, 1, 1);

        late = new QCheckBox(PassengerFlightsAddDialog);
        late->setObjectName("late");

        gridLayout->addWidget(late, 0, 1, 1, 1);

        isArrived = new QCheckBox(PassengerFlightsAddDialog);
        isArrived->setObjectName("isArrived");

        gridLayout->addWidget(isArrived, 0, 0, 1, 1);

        bus = new QCheckBox(PassengerFlightsAddDialog);
        bus->setObjectName("bus");

        gridLayout->addWidget(bus, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        gate = new QLineEdit(PassengerFlightsAddDialog);
        gate->setObjectName("gate");

        gridLayout_2->addWidget(gate, 7, 0, 1, 1);

        runway = new QLineEdit(PassengerFlightsAddDialog);
        runway->setObjectName("runway");

        gridLayout_2->addWidget(runway, 4, 0, 1, 1);

        terminal = new QLineEdit(PassengerFlightsAddDialog);
        terminal->setObjectName("terminal");

        gridLayout_2->addWidget(terminal, 8, 0, 1, 1);

        baggagearea = new QLineEdit(PassengerFlightsAddDialog);
        baggagearea->setObjectName("baggagearea");

        gridLayout_2->addWidget(baggagearea, 9, 0, 1, 1);

        AddButton = new QPushButton(PassengerFlightsAddDialog);
        AddButton->setObjectName("AddButton");
        AddButton->setEnabled(false);

        gridLayout_2->addWidget(AddButton, 10, 0, 1, 1);


        retranslateUi(PassengerFlightsAddDialog);

        QMetaObject::connectSlotsByName(PassengerFlightsAddDialog);
    } // setupUi

    void retranslateUi(QDialog *PassengerFlightsAddDialog)
    {
        PassengerFlightsAddDialog->setWindowTitle(QCoreApplication::translate("PassengerFlightsAddDialog", "PassengerFlightsAddDialog", nullptr));
#if QT_CONFIG(whatsthis)
        time->setWhatsThis(QCoreApplication::translate("PassengerFlightsAddDialog", "Arrival time", nullptr));
#endif // QT_CONFIG(whatsthis)
        departure->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Departure", nullptr));
        flightnumber->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Flight number", nullptr));
        aircrafttype->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Aircraft type", nullptr));
        emergency->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Emergency landing?", nullptr));
        connecting->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Connecting flight?", nullptr));
        assistans->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Special assistance?", nullptr));
        visa->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Visa control?", nullptr));
        customs->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Customs required?", nullptr));
        baggageUnloadded->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Baggage unloaded?", nullptr));
        late->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Late?", nullptr));
        isArrived->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Arrived?", nullptr));
        bus->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Bus rqquired?", nullptr));
        gate->setText(QString());
        gate->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Gate", nullptr));
        runway->setText(QString());
        runway->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Runway", nullptr));
        terminal->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Terminal", nullptr));
        baggagearea->setPlaceholderText(QCoreApplication::translate("PassengerFlightsAddDialog", "Baggage claim area", nullptr));
        AddButton->setText(QCoreApplication::translate("PassengerFlightsAddDialog", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassengerFlightsAddDialog: public Ui_PassengerFlightsAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERFLIGHTSADDDIALOG_H
