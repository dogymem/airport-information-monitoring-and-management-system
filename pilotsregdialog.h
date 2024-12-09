//
// Created by Егор Томашев on 12.11.24.
//

#ifndef PILOTSREGDIALOG_H
#define PILOTSREGDIALOG_H

#include <QDialog>

#include "clases.h"
#include "StartWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PilotsRegDialog; }
QT_END_NAMESPACE

class PilotsRegDialog : public QDialog {
Q_OBJECT

public:
    explicit PilotsRegDialog(std::vector <Pilot>&,QWidget *parent = nullptr);
    ~PilotsRegDialog() override;

private slots:
    void addActivation();
    void on_addButton_clicked();
    void onUndoClick();
    void onDeleteButtonClicked();

private:
    Ui::PilotsRegDialog *ui;
    vector<Pilot>& pilots;
    Stack <vector<Pilot>> backUpPilots;
    void vectorToTable();


bool yesNoButton();
};


#endif //PILOTSREGDIALOG_H
