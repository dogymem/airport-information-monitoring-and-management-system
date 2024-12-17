/********************************************************************************
** Form generated from reading UI file 'CargoDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARGODIALOG_H
#define UI_CARGODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
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

class Ui_CargoDialog
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
    QLineEdit *type;
    QSpinBox *weight;
    QLineEdit *shipper;
    QLineEdit *receiver;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *add;

    void setupUi(QDialog *CargoDialog)
    {
        if (CargoDialog->objectName().isEmpty())
            CargoDialog->setObjectName("CargoDialog");
        CargoDialog->resize(1067, 670);
        CargoDialog->setBaseSize(QSize(1650, 800));
        actionUndo = new QAction(CargoDialog);
        actionUndo->setObjectName("actionUndo");
        statusbar = new QStatusBar(CargoDialog);
        statusbar->setObjectName("statusbar");
        statusbar->setGeometry(QRect(0, 0, 3, 27));
        gridLayout = new QGridLayout(CargoDialog);
        gridLayout->setObjectName("gridLayout");
        menubar = new QMenuBar(CargoDialog);
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
        label = new QLabel(CargoDialog);
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

        name = new QLineEdit(CargoDialog);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        type = new QLineEdit(CargoDialog);
        type->setObjectName("type");

        verticalLayout_2->addWidget(type);

        weight = new QSpinBox(CargoDialog);
        weight->setObjectName("weight");
        weight->setAccelerated(false);
        weight->setMinimum(1);
        weight->setValue(1);

        verticalLayout_2->addWidget(weight);

        shipper = new QLineEdit(CargoDialog);
        shipper->setObjectName("shipper");

        verticalLayout_2->addWidget(shipper);

        receiver = new QLineEdit(CargoDialog);
        receiver->setObjectName("receiver");

        verticalLayout_2->addWidget(receiver);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tableWidget = new QTableWidget(CargoDialog);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(825, 0));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(6);
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

        add = new QPushButton(CargoDialog);
        add->setObjectName("add");
        add->setEnabled(false);

        horizontalLayout->addWidget(add);

        horizontalLayout->setStretch(0, 7);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        menubar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionUndo);

        retranslateUi(CargoDialog);

        QMetaObject::connectSlotsByName(CargoDialog);
    } // setupUi

    void retranslateUi(QDialog *CargoDialog)
    {
        CargoDialog->setWindowTitle(QCoreApplication::translate("CargoDialog", "Cargo", nullptr));
        actionUndo->setText(QCoreApplication::translate("CargoDialog", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("CargoDialog", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        menuEdit->setTitle(QCoreApplication::translate("CargoDialog", "Edit", nullptr));
        label->setText(QCoreApplication::translate("CargoDialog", "Cargo data:", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("CargoDialog", "Name", nullptr));
        type->setText(QString());
        type->setPlaceholderText(QCoreApplication::translate("CargoDialog", "Type", nullptr));
        weight->setSpecialValueText(QString());
        shipper->setText(QString());
        shipper->setPlaceholderText(QCoreApplication::translate("CargoDialog", "Shipper", nullptr));
        receiver->setPlaceholderText(QCoreApplication::translate("CargoDialog", "Receiver", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CargoDialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CargoDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CargoDialog", "Weight", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CargoDialog", "Shiper", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CargoDialog", "Receiver", nullptr));
#if QT_CONFIG(whatsthis)
        add->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        add->setText(QCoreApplication::translate("CargoDialog", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CargoDialog: public Ui_CargoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARGODIALOG_H
