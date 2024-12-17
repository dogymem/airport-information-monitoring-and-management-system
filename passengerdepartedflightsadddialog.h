
#ifndef PASSENGERDEPARTEDFLIGHTSADDDIALOG_H
#define PASSENGERDEPARTEDFLIGHTSADDDIALOG_H

#include <QDialog>

#include "clases.h"


QT_BEGIN_NAMESPACE
namespace Ui { class PassengerDepartedFlightsAddDialog; }
QT_END_NAMESPACE

class PassengerDepartedFlightsAddDialog : public QDialog {
Q_OBJECT

public:
    explicit PassengerDepartedFlightsAddDialog(vector<DepartingPassengerFlight>& depPassFlight,bool isEditing,int row,QWidget *parent = nullptr);
    ~PassengerDepartedFlightsAddDialog() override;

private slots:
        void onAddButtonClick();

void addButtonActivation();

private:
    int row;
    bool isEditing;
    Ui::PassengerDepartedFlightsAddDialog *ui;
    vector<DepartingPassengerFlight>& depPassFlight;
};


#endif //PASSENGERDEPARTEDFLIGHTSADDDIALOG_H
