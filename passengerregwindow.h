#ifndef PASSENGERREGWINDOW_H
#define PASSENGERREGWINDOW_H

#include <QDialog>

#include "clases.h"
#include "passengerregwindow.h"
#include "StartWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class passengerRegWindow; }
QT_END_NAMESPACE

class passengerRegWindow : public QDialog {
Q_OBJECT

    private slots:
    void on_addButton_clicked();
    void addActivation();

void onUndoClick();

void onDeleteButtonClicked();

bool yesNoButton();

public:
    explicit passengerRegWindow(vector<Passenger>& passengers,QWidget *parent = nullptr);
    ~passengerRegWindow() override;

private:
    Stack <vector<Passenger>> backUpPassengers;
    Ui::passengerRegWindow *ui;
    vector<Passenger>& passengers;
    void vectorToTable();
};


#endif //PASSENGERREGWINDOW_H
