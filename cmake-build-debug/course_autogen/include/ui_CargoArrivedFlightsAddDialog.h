/********************************************************************************
** Form generated from reading UI file 'CargoArrivedFlightsAddDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGOARRIVEDFLIGHTSADDDIALOG_H
#define UI_CARGOARRIVEDFLIGHTSADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CargoArrivedFlightsAddDialog
{
public:
    QGridLayout *gridLayout_2;
    QLineEdit *departure;
    QLineEdit *cargotype;
    QPushButton *AddButton;
    QLineEdit *flightnumber;
    QGridLayout *gridLayout;
    QCheckBox *connecting;
    QCheckBox *customs;
    QCheckBox *isArrived;
    QCheckBox *emergency;
    QCheckBox *late;
    QCheckBox *baggageUnloadded;
    QLineEdit *aircrafttype;
    QLineEdit *runway;
    QDateTimeEdit *time;
    QDoubleSpinBox *cargomax;

    void setupUi(QDialog *CargoArrivedFlightsAddDialog)
    {
        if (CargoArrivedFlightsAddDialog->objectName().isEmpty())
            CargoArrivedFlightsAddDialog->setObjectName("CargoArrivedFlightsAddDialog");
        CargoArrivedFlightsAddDialog->resize(517, 571);
        CargoArrivedFlightsAddDialog->setMinimumSize(QSize(0, 0));
        CargoArrivedFlightsAddDialog->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(CargoArrivedFlightsAddDialog);
        gridLayout_2->setObjectName("gridLayout_2");
        departure = new QLineEdit(CargoArrivedFlightsAddDialog);
        departure->setObjectName("departure");

        gridLayout_2->addWidget(departure, 6, 0, 1, 1);

        cargotype = new QLineEdit(CargoArrivedFlightsAddDialog);
        cargotype->setObjectName("cargotype");

        gridLayout_2->addWidget(cargotype, 8, 0, 1, 1);

        AddButton = new QPushButton(CargoArrivedFlightsAddDialog);
        AddButton->setObjectName("AddButton");
        AddButton->setEnabled(false);

        gridLayout_2->addWidget(AddButton, 9, 0, 1, 1);

        flightnumber = new QLineEdit(CargoArrivedFlightsAddDialog);
        flightnumber->setObjectName("flightnumber");

        gridLayout_2->addWidget(flightnumber, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        connecting = new QCheckBox(CargoArrivedFlightsAddDialog);
        connecting->setObjectName("connecting");

        gridLayout->addWidget(connecting, 1, 1, 1, 1);

        customs = new QCheckBox(CargoArrivedFlightsAddDialog);
        customs->setObjectName("customs");

        gridLayout->addWidget(customs, 1, 0, 1, 1);

        isArrived = new QCheckBox(CargoArrivedFlightsAddDialog);
        isArrived->setObjectName("isArrived");

        gridLayout->addWidget(isArrived, 0, 0, 1, 1);

        emergency = new QCheckBox(CargoArrivedFlightsAddDialog);
        emergency->setObjectName("emergency");

        gridLayout->addWidget(emergency, 2, 0, 1, 1);

        late = new QCheckBox(CargoArrivedFlightsAddDialog);
        late->setObjectName("late");

        gridLayout->addWidget(late, 0, 1, 1, 1);

        baggageUnloadded = new QCheckBox(CargoArrivedFlightsAddDialog);
        baggageUnloadded->setObjectName("baggageUnloadded");

        gridLayout->addWidget(baggageUnloadded, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        aircrafttype = new QLineEdit(CargoArrivedFlightsAddDialog);
        aircrafttype->setObjectName("aircrafttype");

        gridLayout_2->addWidget(aircrafttype, 1, 0, 1, 1);

        runway = new QLineEdit(CargoArrivedFlightsAddDialog);
        runway->setObjectName("runway");

        gridLayout_2->addWidget(runway, 4, 0, 1, 1);

        time = new QDateTimeEdit(CargoArrivedFlightsAddDialog);
        time->setObjectName("time");
        time->setFrame(true);
        time->setDateTime(QDateTime(QDate(2000, 12, 31), QTime(23, 0, 0)));
        time->setCalendarPopup(true);

        gridLayout_2->addWidget(time, 3, 0, 1, 1);

        cargomax = new QDoubleSpinBox(CargoArrivedFlightsAddDialog);
        cargomax->setObjectName("cargomax");

        gridLayout_2->addWidget(cargomax, 7, 0, 1, 1);


        retranslateUi(CargoArrivedFlightsAddDialog);

        QMetaObject::connectSlotsByName(CargoArrivedFlightsAddDialog);
    } // setupUi

    void retranslateUi(QDialog *CargoArrivedFlightsAddDialog)
    {
        CargoArrivedFlightsAddDialog->setWindowTitle(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Add flight", nullptr));
        departure->setPlaceholderText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Departure", nullptr));
        cargotype->setPlaceholderText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Type", nullptr));
        AddButton->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Add", nullptr));
        flightnumber->setPlaceholderText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Flight number", nullptr));
        connecting->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Connecting flight?", nullptr));
        customs->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Customs required?", nullptr));
        isArrived->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Arrived?", nullptr));
        emergency->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Emergency landing?", nullptr));
        late->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Late?", nullptr));
        baggageUnloadded->setText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Cargo unloaded?", nullptr));
        aircrafttype->setPlaceholderText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Aircraft type", nullptr));
        runway->setText(QString());
        runway->setPlaceholderText(QCoreApplication::translate("CargoArrivedFlightsAddDialog", "Runway", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CargoArrivedFlightsAddDialog: public Ui_CargoArrivedFlightsAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGOARRIVEDFLIGHTSADDDIALOG_H
