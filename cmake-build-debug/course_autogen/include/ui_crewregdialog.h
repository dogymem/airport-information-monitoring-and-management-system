/********************************************************************************
** Form generated from reading UI file 'crewregdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREWREGDIALOG_H
#define UI_CREWREGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
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

class Ui_crewregdialog
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
    QLineEdit *language;
    QLineEdit *specialization;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;

    void setupUi(QDialog *crewregdialog)
    {
        if (crewregdialog->objectName().isEmpty())
            crewregdialog->setObjectName("crewregdialog");
        crewregdialog->resize(1067, 670);
        crewregdialog->setBaseSize(QSize(1650, 800));
        actionUndo = new QAction(crewregdialog);
        actionUndo->setObjectName("actionUndo");
        statusbar = new QStatusBar(crewregdialog);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 27));
        gridLayout = new QGridLayout(crewregdialog);
        gridLayout->setObjectName("gridLayout");
        menubar = new QMenuBar(crewregdialog);
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
        label = new QLabel(crewregdialog);
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

        name = new QLineEdit(crewregdialog);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        surname = new QLineEdit(crewregdialog);
        surname->setObjectName("surname");

        verticalLayout_2->addWidget(surname);

        middle = new QLineEdit(crewregdialog);
        middle->setObjectName("middle");

        verticalLayout_2->addWidget(middle);

        Age = new QSpinBox(crewregdialog);
        Age->setObjectName("Age");
        Age->setAccelerated(false);
        Age->setMinimum(1);
        Age->setValue(1);

        verticalLayout_2->addWidget(Age);

        passNum = new QLineEdit(crewregdialog);
        passNum->setObjectName("passNum");

        verticalLayout_2->addWidget(passNum);

        passDate = new QDateEdit(crewregdialog);
        passDate->setObjectName("passDate");

        verticalLayout_2->addWidget(passDate);

        nationality = new QLineEdit(crewregdialog);
        nationality->setObjectName("nationality");

        verticalLayout_2->addWidget(nationality);

        email = new QLineEdit(crewregdialog);
        email->setObjectName("email");

        verticalLayout_2->addWidget(email);

        phone = new QLineEdit(crewregdialog);
        phone->setObjectName("phone");

        verticalLayout_2->addWidget(phone);

        language = new QLineEdit(crewregdialog);
        language->setObjectName("language");

        verticalLayout_2->addWidget(language);

        specialization = new QLineEdit(crewregdialog);
        specialization->setObjectName("specialization");

        verticalLayout_2->addWidget(specialization);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(crewregdialog);
        if (tableWidget->columnCount() < 12)
            tableWidget->setColumnCount(12);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(825, 0));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(12);
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

        add = new QPushButton(crewregdialog);
        add->setObjectName("add");
        add->setEnabled(false);

        horizontalLayout->addWidget(add);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionUndo);

        retranslateUi(crewregdialog);

        QMetaObject::connectSlotsByName(crewregdialog);
    } // setupUi

    void retranslateUi(QDialog *crewregdialog)
    {
        crewregdialog->setWindowTitle(QCoreApplication::translate("crewregdialog", "crewregdialog", nullptr));
        actionUndo->setText(QCoreApplication::translate("crewregdialog", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("crewregdialog", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        menuEdit->setTitle(QCoreApplication::translate("crewregdialog", "Edit", nullptr));
        label->setText(QCoreApplication::translate("crewregdialog", "Crew data:", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Name", nullptr));
        surname->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Surname", nullptr));
        middle->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Middle name", nullptr));
        Age->setSpecialValueText(QString());
        passNum->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Passport number", nullptr));
        nationality->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Nationality", nullptr));
        email->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Email", nullptr));
        phone->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Mobile phone", nullptr));
        language->setText(QString());
        language->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Language", nullptr));
        specialization->setPlaceholderText(QCoreApplication::translate("crewregdialog", "Specialization", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("crewregdialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("crewregdialog", "Surname", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("crewregdialog", "Middle name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("crewregdialog", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("crewregdialog", "Passport number", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("crewregdialog", "Passport date", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("crewregdialog", "Nationality", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("crewregdialog", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("crewregdialog", "Phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("crewregdialog", "Language", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("crewregdialog", "Specialization", nullptr));
#if QT_CONFIG(whatsthis)
        add->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        add->setText(QCoreApplication::translate("crewregdialog", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class crewregdialog: public Ui_crewregdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREWREGDIALOG_H
