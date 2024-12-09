#ifndef TEST_CLASES_H
#define TEST_CLASES_H
#include <string>
#include <vector>
using namespace std;
class Human {
protected:
    string name;
    string surname;
    string middleName;
    int age;
    string passNum;
    string passExpiryDate;
    string nationality;  // Гражданство
    string email;        // Электронная почта
    string phone;        // Номер телефона
public:
    Human();
    string get_name();
    void set_name(const string &name);
    string get_surname();
    void set_surname(const string &surname);
    string get_middle_name();
    void set_middle_name(const string &middle_name);
    int get_age();
    void set_age(int age);
    string get_pass_num();
    void set_pass_num(const string &pass_num);
    string get_pass_expiry_date();
    void set_pass_expiry_date(const string &pass_expiry_date);
    string get_nationality();
    void set_nationality(const string &nationality);
    string get_email();
    void set_email(const string &email);
    string get_phone();
    void set_phone(const string &phone);

};
class Passenger:public Human
{
protected:
    string visaNum;      // Номер визы (если есть)
    bool hasTravelInsurance; // Наличие туристической страховки
    bool requiresSpecialAssistance;  // Требуется ли специальная помощь
    string passengerClass;
    string seat;                // Номер места
    string ticketNumber;         // Номер билета
    int bags;           // Количество зарегистрированного багажа
public:
    Passenger();
    bool is_has_visa();
    string get_visa_num();
    void set_visa_num(const string &visa_num);
    bool is_has_travel_insurance();
    void set_has_travel_insurance(bool has_travel_insurance);
    void set_has_travel_insurance_str(string has_travel_insurance);
    bool is_requires_special_assistance();
    void set_requires_special_assistance(bool requires_special_assistance);
    void set_requires_special_assistance_str(string requires_special_assistance);
    string get_has_travel_insurance_str();
    string get_requires_special_assistance_str();
    string get_passenger_class();
    void set_passenger_class(const string &passenger_class);
    string get_seat();
    void set_seat(const string &seat);
    string get_ticket_number();
    void set_ticket_number(const string &ticket_number);
    int get_bags();
    void set_bags(int bags);
};
class Pilot:public Human{
    int flightHours;
    string licenseNum;
    string licenseExpiryDate;
    string rank;
    string experience;
public:
    Pilot();
    int get_flight_hours();
    void set_flight_hours(int flight_hours);
    string get_license_num();
    void set_license_num(const string &license_num);
    string get_license_expiry_date();
    void set_license_expiry_date(const string &license_expiry_date);
    string get_rank();
    void set_rank(const string &rank);
    string get_experience();
    void set_experience(const string &experience);

};
class CrewMember:public Human {
    string languages;
    string specialization;
public:
    CrewMember();
    string get_languages();
    void set_languages(string languages);
    string get_specialization();
    void set_specialization(const string &specialization);
};
////////////////////////////////////////////////////////////////////////
class Cargo
{
protected:
    string name;
    string type;
    double weight;
    string shipper;
    string receiver;
public:
    Cargo();
    string get_name() const;
    void set_name(const string &name);
    string get_type() const;
    void set_type(const string &type);
    double get_weight() const;
    void set_weight(double weight);
    string get_shipper() const;
    void set_shipper(const string &shipper);
    string get_receiver() const;
    void set_receiver(const string &receiver);
};
////////////////////////////////////////////////////////////////////////
class Flight {
protected:
    string flightNumber;  // Номер рейса
    string aircraftType;
    int numberOfStaff;    // Количество персонала
    string time;          // Время отправления или прибытия
    string runway;        // Используемая полоса
    vector<Pilot> pilots;

public:
    Flight();  // Constructor declaration
    string get_flight_number();
    void set_flight_number(const string &flight_number);
    string get_aircraft_type();
    void set_aircraft_type(const string &aircraft_type);
    vector<Pilot>& get_pilots();
    void set_pilots(const vector<Pilot> &pilots);
    int get_number_of_staff();
    void set_number_of_staff(int number_of_staff);
    string get_time();
    void set_time(const string &time);
    string get_runway();
    void set_runway(const string &runway);
};

class ArrivingFlight : public Flight {
protected:
    bool isArrive;
    string departure;        // Пункт отправления
    bool isLate;
    bool customsRequired;    // Нужен ли таможенный контроль
    bool isConnectingFlight; // Является ли рейс пересадочным
    bool isEmergencyLanding; // Является ли рейс аварийной посадкой

public:
    ArrivingFlight();
    string get_is_arrive_str();
    bool get_is_arrive();
    void set_is_arrive(bool is_arrive);
    void set_is_arrive_str(string is_arrive);
    string get_departure();
    void set_departure(const string &departure);
    string get_is_late_str();
    bool get_is_late();
    void set_is_late(bool is_late);
    void set_is_late_str(string is_late);
    string get_customs_required_str();
    bool get_customs_required();
    void set_customs_required(bool customs_required);
    void set_customs_required_str(string customs_required);
    bool get_is_connecting_flight();
    string get_is_connecting_flight_str();
    void set_is_connecting_flight(bool is_connecting_flight);
    void set_is_connecting_flight_str(string is_connecting_flight);
    string get_is_emergency_landing_str();
    bool get_is_emergency_landing();
    void set_is_emergency_landing(bool is_emergency_landing);
    void set_is_emergency_landing_str(string is_emergency_landing);
};

class DepartingFlight : public Flight {
protected:
    bool isDepart;
    string destination;      // Пункт назначения
    string status;
    string fuelStatus;
    string aircraftStatus;

public:
    DepartingFlight();  // Constructor declaration
    bool get_is_depart();
    string get_is_depart_str();
    void set_is_depart_str(string is_depart);
    void set_is_depart(bool is_depart);
    string get_destination();
    void set_destination(const string &destination);
    string get_status();
    void set_status(const string &status);
    string get_fuel_status();
    void set_fuel_status(const string &fuel_status);
    string get_aircraft_status();
    void set_aircraft_status(const string &aircraft_status);
};

class ArrivingPassengerFlight : public ArrivingFlight {
private:
    int currentPassengerCount;
    string gate;
    string terminal;
    bool isBus;
    string baggageClaimArea;
    bool specialAssistanceRequired;
    bool isVisa;
    bool isBaggageUnloaded;
    vector<Passenger> passengerList;
    vector<CrewMember> crewList;

public:
    ArrivingPassengerFlight();
    int get_current_passenger_count();
    void set_current_passenger_count(int current_passenger_count);
    string get_gate();
    void set_gate(const string &gate);
    string get_terminal();
    void set_terminal(const string &terminal);
    bool get_is_bus();
    string get_is_bus_str();
    void set_is_bus(bool is_bus);
    void set_is_bus_str(string is_bus);
    string get_baggage_claim_area();
    void set_baggage_claim_area(const string &baggage_claim_area);
    string get_special_assistance_required_str();
    bool get_special_assistance_required();
    void set_special_assistance_required(bool special_assistance_required);
    void set_special_assistance_required_str(string special_assistance_required);
    bool get_is_visa();
    string get_is_visa_str();
    void set_is_visa(bool is_visa);
    void set_is_visa_str(string is_visa);
    bool get_is_baggage_unloaded();
    string get_is_baggage_unloaded_str();
    void set_is_baggage_unloaded(bool is_baggage_unloaded);
    void set_is_baggage_unloaded_str(string is_baggage_unloaded);
    vector<Passenger>& get_passenger_list ();
    void set_passenger_list(const vector<Passenger> &passenger_list);
    vector<CrewMember>& get_crew_list();
    void set_crew_list(const vector<CrewMember> &crew_list);
};

class ArrivingCargoFlight : public ArrivingFlight {
private:
    double cargoMaxWeight;
    string cargoType;
    bool isCargoUnloaded;
    vector<Cargo> cargoList;

public:
    ArrivingCargoFlight();  // Constructor declaration
    double get_cargo_max_weight();
    void set_cargo_max_weight(double cargo_max_weight);
    string get_cargo_type();
    void set_cargo_type(const string &cargo_type);
    bool get_is_cargo_unloaded();
    string get_is_cargo_unloaded_str();
    void set_is_cargo_unloaded(bool is_cargo_unloaded);

    void set_is_cargo_unloaded_str(string isCargoUnloaded);

    vector<Cargo>& get_cargo_list();
    void set_cargo_list(const vector<Cargo> &cargo_list);
};

class DepartingPassengerFlight : public DepartingFlight {
private:
    string terminal;
    string gate;
    int passengerMaxValue;
    string checkInStartTime;
    string checkInEndTime;
    string boardingStartTime;
    string boardingEndTime;
    bool isBaggageLoaded;
    vector<Passenger> passengerList;
    vector<CrewMember> crewList;

public:
    DepartingPassengerFlight();  // Constructor declaration
    string get_terminal();
    void set_terminal(const string &terminal);
    string get_gate();
    void set_gate(const string &gate);
    int get_passenger_max_value();
    void set_passenger_max_value(int passenger_max_value);
    string get_check_in_start_time();
    void set_check_in_start_time(const string &check_in_start_time);
    string get_check_in_end_time();
    void set_check_in_end_time(const string &check_in_end_time);
    string get_boarding_start_time();
    void set_boarding_start_time(const string &boarding_start_time);
    string get_boarding_end_time();
    void set_boarding_end_time(const string &boarding_end_time);
    string get_is_baggage_loaded_str();
    void set_is_baggage_loaded_str(string is_baggage_loaded);
    bool get_is_baggage_loaded();
    void set_is_baggage_loaded(bool is_baggage_loaded);
    vector<Passenger>& get_passenger_list();
    void set_passenger_list(const vector<Passenger> &passenger_list);
    vector<CrewMember>& get_crew_list();
    void set_crew_list(const vector<CrewMember> &crew_list);
};

class DepartingCargoFlight : public DepartingFlight {
private:
    double cargoMaxWeight;
    string cargoType;
    bool isCargoLoaded;
    string cargoStartLoadTime;
    string cargoEndLoadTime;
    vector<Cargo> cargoList;

public:
    DepartingCargoFlight();  // Constructor declaration
    double get_cargo_max_weight();
    void set_cargo_max_weight(double cargo_max_weight);
    string get_cargo_type();
    void set_cargo_type(const string &cargo_type);
    bool get_is_cargo_loaded();
    void set_is_cargo_loaded(bool is_cargo_loaded);
    string get_is_cargo_loaded_str();
    void set_is_cargo_loaded_str(string is_cargo_loaded);
    string get_cargo_start_load_time();
    void set_cargo_start_load_time(const string &cargo_start_load_time);
    string get_cargo_end_load_time();
    void set_cargo_end_load_time(const string &cargo_end_load_time);
    vector<Cargo> get_cargo_list();
    void set_cargo_list(const vector<Cargo> &cargo_list);
};

std::vector<DepartingCargoFlight> generateDepartingCargoFlights();
std::vector<DepartingPassengerFlight> generateDepartingPassengerFlights();
std::vector<ArrivingCargoFlight> generateArrivingCargoFlights();
std::vector<ArrivingPassengerFlight> generateArrivingPassengerFlights();

#endif //TEST_CLASSES_H
