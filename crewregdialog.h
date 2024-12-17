#ifndef CREWREGDIALOG_H
#define CREWREGDIALOG_H

#include <QDialog>

#include "clases.h"
#include "StartWindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class crewregdialog; }
QT_END_NAMESPACE

class crewregdialog : public QDialog {
Q_OBJECT

public:
    explicit crewregdialog(std::vector <CrewMember>&,QWidget *parent = nullptr);
    ~crewregdialog() override;

private slots:
    void onUndoClick();
    void addActivation();
    void on_addButton_clicked();

private:
    Ui::crewregdialog *ui;
    vector<CrewMember>& crew;
    Stack<vector<CrewMember>> backUpCrew;
    void vectorToTable();

void onDeleteButtonClicked();

bool yesNoButton();
};


#endif //CREWREGDIALOG_H