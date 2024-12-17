/********************************************************************************
** Form generated from reading UI file 'passengerRegWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSENGERREGWINDOW_H
#define UI_PASSENGERREGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_passengerRegWindow
{
public:
    QAction *actionUndo;
    QStatusBar *statusbar;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *middle;
    QSpinBox *Age;
    QLineEdit *passNum;
    QDateEdit *passDate;
    QLineEdit *nationality;
    QLineEdit *email;
    QLineEdit *phone;
    QLineEdit *visaNum;
    QLineEdit *passengerClass;
    QLineEdit *seat;
    QLineEdit *ticketNumber;
    QSpinBox *bags;
    QCheckBox *travelInsurance;
    QCheckBox *assistance;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;

    void setupUi(QDialog *passengerRegWindow)
    {
        if (passengerRegWindow->objectName().isEmpty())
            passengerRegWindow->setObjectName("passengerRegWindow");
        passengerRegWindow->resize(1067, 670);
        passengerRegWindow->setBaseSize(QSize(1650, 800));
        actionUndo = new QAction(passengerRegWindow);
        actionUndo->setObjectName("actionUndo");
        statusbar = new QStatusBar(passengerRegWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 27));
        gridLayout = new QGridLayout(passengerRegWindow);
        gridLayout->setObjectName("gridLayout");
        menubar = new QMenuBar(passengerRegWindow);
        menubar->setObjectName("menubar");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");

        gridLayout->addWidget(menubar, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(passengerRegWindow);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Academy Engraved LET")});
        font.setPointSize(24);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        name = new QLineEdit(passengerRegWindow);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        surname = new QLineEdit(passengerRegWindow);
        surname->setObjectName("surname");

        verticalLayout_2->addWidget(surname);

        middle = new QLineEdit(passengerRegWindow);
        middle->setObjectName("middle");

        verticalLayout_2->addWidget(middle);

        Age = new QSpinBox(passengerRegWindow);
        Age->setObjectName("Age");
        Age->setAccelerated(false);
        Age->setMinimum(1);
        Age->setValue(1);

        verticalLayout_2->addWidget(Age);

        passNum = new QLineEdit(passengerRegWindow);
        passNum->setObjectName("passNum");

        verticalLayout_2->addWidget(passNum);

        passDate = new QDateEdit(passengerRegWindow);
        passDate->setObjectName("passDate");

        verticalLayout_2->addWidget(passDate);

        nationality = new QLineEdit(passengerRegWindow);
        nationality->setObjectName("nationality");

        verticalLayout_2->addWidget(nationality);

        email = new QLineEdit(passengerRegWindow);
        email->setObjectName("email");

        verticalLayout_2->addWidget(email);

        phone = new QLineEdit(passengerRegWindow);
        phone->setObjectName("phone");

        verticalLayout_2->addWidget(phone);

        visaNum = new QLineEdit(passengerRegWindow);
        visaNum->setObjectName("visaNum");

        verticalLayout_2->addWidget(visaNum);

        passengerClass = new QLineEdit(passengerRegWindow);
        passengerClass->setObjectName("passengerClass");

        verticalLayout_2->addWidget(passengerClass);

        seat = new QLineEdit(passengerRegWindow);
        seat->setObjectName("seat");

        verticalLayout_2->addWidget(seat);

        ticketNumber = new QLineEdit(passengerRegWindow);
        ticketNumber->setObjectName("ticketNumber");

        verticalLayout_2->addWidget(ticketNumber);

        bags = new QSpinBox(passengerRegWindow);
        bags->setObjectName("bags");

        verticalLayout_2->addWidget(bags);

        travelInsurance = new QCheckBox(passengerRegWindow);
        travelInsurance->setObjectName("travelInsurance");

        verticalLayout_2->addWidget(travelInsurance);

        assistance = new QCheckBox(passengerRegWindow);
        assistance->setObjectName("assistance");

        verticalLayout_2->addWidget(assistance);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(passengerRegWindow);
        if (tableWidget->columnCount() < 17)
            tableWidget->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(825, 0));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(17);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);

        horizontalLayout_2->addWidget(tableWidget);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 6);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        add = new QPushButton(passengerRegWindow);
        add->setObjectName("add");
        add->setEnabled(false);

        horizontalLayout->addWidget(add);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionUndo);

        retranslateUi(passengerRegWindow);

        QMetaObject::connectSlotsByName(passengerRegWindow);
    } // setupUi

    void retranslateUi(QDialog *passengerRegWindow)
    {
        passengerRegWindow->setWindowTitle(QCoreApplication::translate("passengerRegWindow", "Passengers", nullptr));
        actionUndo->setText(QCoreApplication::translate("passengerRegWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("passengerRegWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        menuEdit->setTitle(QCoreApplication::translate("passengerRegWindow", "Edit", nullptr));
        label->setText(QCoreApplication::translate("passengerRegWindow", "Passenger data:", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Name", nullptr));
        surname->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Surname", nullptr));
        middle->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Middle name", nullptr));
        Age->setSpecialValueText(QString());
        passNum->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Passport number", nullptr));
        nationality->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Nationality", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Email", nullptr));
        phone->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Mobile phone", nullptr));
        visaNum->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Visa number", nullptr));
        passengerClass->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Passenger class", nullptr));
        seat->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Seat", nullptr));
        ticketNumber->setPlaceholderText(QCoreApplication::translate("passengerRegWindow", "Ticket number", nullptr));
        travelInsurance->setText(QCoreApplication::translate("passengerRegWindow", "Travel Insurance", nullptr));
        assistance->setText(QCoreApplication::translate("passengerRegWindow", "Requires Assistance", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("passengerRegWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("passengerRegWindow", "Surname", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("passengerRegWindow", "Middle name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("passengerRegWindow", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("passengerRegWindow", "Passport number", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("passengerRegWindow", "Passport date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("passengerRegWindow", "Nationality", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("passengerRegWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("passengerRegWindow", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("passengerRegWindow", "Visa", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("passengerRegWindow", "Class", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("passengerRegWindow", "Seat", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("passengerRegWindow", "Ticket number", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("passengerRegWindow", "Bags", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("passengerRegWindow", "Insur.", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("passengerRegWindow", "Ass.", nullptr));
#if QT_CONFIG(whatsthis)
        add->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        add->setText(QCoreApplication::translate("passengerRegWindow", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passengerRegWindow: public Ui_passengerRegWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSENGERREGWINDOW_H
