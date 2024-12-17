#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>

#include "clases.h"
#include "Exception.h"

template <typename T>
struct StackNode {
    T value;
    StackNode* next = nullptr;
};

template <typename T>
class Stack {
private:
    StackNode<T>* node = nullptr;

public:
    Stack() = default;
    ~Stack() {
        while(this->node) {
            auto* newNode = this->node->next;
            delete(this->node);
            this->node=newNode;
        }

    }
    void push(T x) {
        auto* newNode = new StackNode<T>();
        newNode->value = x;
        newNode->next = this->node;
        this->node = newNode;
    }

    T pop() {
        if (this->begin()==this->end()) {
            throw StackException("There is no more undoes");
        }
        auto bufValue = node->value;
        auto* newNode = node->next;
        delete(node);
        node = newNode;
        return bufValue;
    }

    T pick() {
        return this->node->value;
    }

    class Iterator {
    private:
        StackNode<T>* current;

    public:
        explicit Iterator(StackNode<T>* start) : current(start) {}

        // Перегрузка оператора разыменования
        T& operator*() {
            return current->data;
        }

        // Перегрузка оператора инкремента
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        // Операторы сравнения
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    Iterator begin() {
        return Iterator(node);
    }
    Iterator end() {
        return Iterator(nullptr);
    }
};


QT_BEGIN_NAMESPACE
namespace Ui { class StartWindow; }
QT_END_NAMESPACE

class StartWindow : public QMainWindow {
    Q_OBJECT

    public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow() override;
    void vectorToTable();
    void backUp();
    bool yesNoButton();

private slots:
    void onArrButtonClick();
    void onDepButtonClick();
    void onAddPassengerFlightsButtonClick();
    void onAddCargoFlightsButtonClick();
    void onUndoButtonClick();
    static void onRegButtonClick();
    void onPilotsButtonClicked();
    void onPassengersButtonClicked();
    void onCargoButtonClicked();
    void onCrewButtonClicked();
    void onEditButtonClicked();
    void onDeleteButtonClicked();

private:
    Ui::StartWindow *ui;
    vector<ArrivingPassengerFlight> arrPassFlights;
    vector<ArrivingCargoFlight> arrCargoFlights;
    vector<DepartingPassengerFlight> depPassFlights;
    vector<DepartingCargoFlight> depCargoFlights;

    Stack<vector<ArrivingPassengerFlight>> arrPassBackup;
    Stack<vector<ArrivingCargoFlight>> arrCargoBackup;
    Stack<vector<DepartingPassengerFlight>> depPassBackup;
    Stack<vector<DepartingCargoFlight>> depCargoBackup;
    bool permission = false;
    bool isArrivedSelected = true;
    QList<QString> headerLabels1 = {"Passenger flights", "Aircr.", "Staff", "Time", "Runway", "Depar.", "Arrived", "Late", "Cust req.", "Conn.", "Emg.", "Pass.", "Gate", "Term.", "Bus req.", "Bagg. area", "Ass.", "Vias", "Bagg. unl."};
    QList<QString> headerLabels2 = {"Cargo flights", "Aircr.", "Staff", "Time", "Runway", "Depar.", "Arrived", "Late", "Cust req.", "Conn.", "Emg.", "Weight", "Type", "Cargo unl."};
    QList<QString> headerLabels3 = {"Passenger flights", "Aircr.", "Staff", "Time", "Runway", "Departed", "Dest.", "Status", "Fuel st.", "Aircraft st.", "Terminal", "Gate", "Pass. max", "Terminal", "CheckIn start", "CheckIn end", "Board. start", "Board. end", "Bagg. loaded"};
    QList<QString> headerLabels4 = {"Cargo flights", "Aircr.", "Staff", "Time", "Runway", "Departed", "Dest.", "Status", "Fuel st.", "Aircraft st.", "Max weight","Cargo type", "Loaded", "Load. start", "Load. end"};
};

void writeString(ostream& out, const std::string& str);
string readString(ifstream &in);
void pilotsRead(ifstream& in,vector<Pilot>& pilots);
void passengersRead(ifstream& in,vector<Passenger>& passengers);
void pilotsWrite(ofstream& out,vector <Pilot>& pilots);
void cargoRead(ifstream& in, vector<Cargo>& cargoes);
void passengersWrite(ofstream& out,vector <Passenger>& passengers);
void crewRead(ifstream &in, vector<CrewMember> &crew_member);
void crewWrite(ofstream& out,vector <CrewMember>& crew_member);
void cargoWrite(ofstream& out,const vector <Cargo>& cargoes);

#endif //STARTWINDOW_H
