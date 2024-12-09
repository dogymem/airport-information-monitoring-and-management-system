#include "clases.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;
Human::Human() {
    name = "Empty";
    surname = "Empty";
    middleName = "Empty";
    age = 0;
    passNum = "Empty";
    passExpiryDate = "Empty";
    nationality = "Empty";
    email = "Empty";
    phone = "Empty";
}

string Human::get_name() {
        return name;
}

void Human::set_name(const string &name) {
        this->name = name;
}

string Human::get_surname() {
    return surname;
}

void Human::set_surname(const string &surname) {
    this->surname = surname;

}

string Human::get_middle_name() {
    return middleName;
}

void Human::set_middle_name(const string &middle_name) {
        middleName = middle_name;
}

int Human::get_age() {
    return age;
}

void Human::set_age(int age) {
        this->age = age;
}

string Human::get_pass_num() {
    return passNum;
}

void Human::set_pass_num(const string &pass_num) {
    passNum = pass_num;
}

string Human::get_pass_expiry_date() {
    return passExpiryDate;
}

void Human::set_pass_expiry_date(const string &pass_expiry_date) {
    passExpiryDate = pass_expiry_date;
}

string Human::get_nationality() {
    return nationality;
}

void Human::set_nationality(const string &nationality) {
    this->nationality = nationality;
}

string Human::get_email() {
    return email;
}

void Human::set_email(const string &email) {
    this->email = email;
}

string Human::get_phone() {
    return phone;
}

void Human::set_phone(const string &phone) {
    this->phone = phone;
}
Pilot::Pilot() {
    licenseNum = "Empty";
    licenseExpiryDate = "Empty";
    rank = "Empty";
    flightHours = 0;
}
int Pilot::get_flight_hours() {
    return flightHours;
}

void Pilot::set_flight_hours(int flight_hours) {
    flightHours = flight_hours;
}

string Pilot::get_license_num() {
    return licenseNum;
}

void Pilot::set_license_num(const string &license_num) {
    licenseNum = license_num;
}

string Pilot::get_license_expiry_date() {
    return licenseExpiryDate;
}

void Pilot::set_license_expiry_date(const string &license_expiry_date) {
    licenseExpiryDate = license_expiry_date;
}

string Pilot::get_rank() {
    return rank;
}

void Pilot::set_rank(const string &rank) {
    this->rank = rank;
}

string Pilot::get_experience() {
    return experience;
}

void Pilot::set_experience(const string &experience) {
    this->experience = experience;
}
Passenger::Passenger() {
    visaNum = "Empty";
    hasTravelInsurance = false;
    requiresSpecialAssistance = false;
    passengerClass = "Empty";
    seat = "Empty";
    ticketNumber = "Empty";
    bags = 0;
}

bool Passenger::is_has_visa() {
    return !visaNum.empty();
}

string Passenger::get_visa_num() {
    return visaNum;
}

void Passenger::set_visa_num(const string &visa_num) {
    visaNum = visa_num;
}

bool Passenger::is_has_travel_insurance() {
    return hasTravelInsurance;
}
string Passenger::get_has_travel_insurance_str() {
    return hasTravelInsurance ? "Yes" : "No";
}

void Passenger::set_has_travel_insurance(bool has_travel_insurance) {
    hasTravelInsurance = has_travel_insurance;
}

void Passenger::set_has_travel_insurance_str(string has_travel_insurance) {
    if (has_travel_insurance == "Yes")
        hasTravelInsurance = true;
    else
        hasTravelInsurance = false;
}

bool Passenger::is_requires_special_assistance() {
    return requiresSpecialAssistance;
}

string Passenger::get_requires_special_assistance_str() {
    return requiresSpecialAssistance ? "Yes" : "No";
}

void Passenger::set_requires_special_assistance(bool requires_special_assistance) {
    requiresSpecialAssistance = requires_special_assistance;
}

void Passenger::set_requires_special_assistance_str(string requires_special_assistance) {
    if (requires_special_assistance == "Yes")
        requiresSpecialAssistance = true;
    else
        requiresSpecialAssistance = false;
}

string Passenger::get_passenger_class() {
    return passengerClass;
}

void Passenger::set_passenger_class(const string &passenger_class) {
    passengerClass = passenger_class;
}

string Passenger::get_seat() {
    return seat;
}

void Passenger::set_seat(const string &seat) {
    this->seat = seat;
}

string Passenger::get_ticket_number() {
    return ticketNumber;
}

void Passenger::set_ticket_number(const string &ticket_number) {
    ticketNumber = ticket_number;
}

int Passenger::get_bags() {
    return bags;
}

void Passenger::set_bags(int bags) {
    this->bags = bags;
}

CrewMember::CrewMember() {
    specialization = "Empty";
}
string CrewMember::get_languages(){
    return languages;
}

void CrewMember::set_languages(string languages) {
    this->languages = languages;
}

string CrewMember::get_specialization(){
    return specialization;
}

void CrewMember::set_specialization(const string &specialization) {
    this->specialization = specialization;
}
///////////////////////////////////////////////////////////////////////
Cargo::Cargo() {
    name = "Empty";
    type = "Empty";
    weight = 0;
    shipper = "Empty";
    receiver = "Empty";
}
string Cargo::get_name() const {
    return name;
}

void Cargo::set_name(const string &name) {
    this->name = name;
}

string Cargo::get_type() const {
    return type;
}

void Cargo::set_type(const string &type) {
    this->type = type;
}

double Cargo::get_weight() const {
    return weight;
}

void Cargo::set_weight(double weight) {
    this->weight = weight;
}

string Cargo::get_shipper() const {
    return shipper;
}

void Cargo::set_shipper(const string &shipper) {
    this->shipper = shipper;
}

string Cargo::get_receiver() const {
    return receiver;
}

void Cargo::set_receiver(const string &receiver) {
    this->receiver = receiver;
}

///////////////////////////////////////////////////////////////////////
Flight::Flight() {
    flightNumber = "Empty";
    aircraftType = "Empty";
    numberOfStaff = 0;
    time = "Empty";
    runway = "Empty";
}

string Flight::get_flight_number() {
    return flightNumber;
}

void Flight::set_flight_number(const string &flight_number) {
    flightNumber = flight_number;
}

string Flight::get_aircraft_type() {
    return aircraftType;
}

void Flight::set_aircraft_type(const string &aircraft_type) {
    aircraftType = aircraft_type;
}

vector<Pilot>& Flight::get_pilots() {
    return pilots;
}

void Flight::set_pilots(const vector<Pilot> &pilots) {
    this->pilots = pilots;
}

int Flight::get_number_of_staff() {
    return numberOfStaff;
}

void Flight::set_number_of_staff(int number_of_staff) {
    numberOfStaff = number_of_staff;
}

string Flight::get_time() {
    return time;
}

void Flight::set_time(const string &time) {
    this->time = time;
}

string Flight::get_runway() {
    return runway;
}

void Flight::set_runway(const string &runway) {
    this->runway = runway;
}

ArrivingFlight::ArrivingFlight() {
    isArrive = false;
    departure = "Empty";
    isLate = false;
    customsRequired = false;
    isConnectingFlight = false;
    isEmergencyLanding = false;
}

string ArrivingFlight::get_is_arrive_str() {
    return get_is_arrive() ? "Yes" : "No";
}

bool ArrivingFlight::get_is_arrive() {
    return isArrive;
}

void ArrivingFlight::set_is_arrive(bool isArrive) {
    this->isArrive = isArrive;
}

void ArrivingFlight::set_is_arrive_str(string is_arrive) {
    if (is_arrive == "Yes")
        isArrive = true;
    else
        isArrive = false;
}

string ArrivingFlight::get_departure() {
    return departure;
}

void ArrivingFlight::set_departure(const string &departure) {
    this->departure = departure;
}

string ArrivingFlight::get_is_late_str() {
    return get_is_late() ? "Yes" : "No";
}

bool ArrivingFlight::get_is_late() {
    return isLate;
}

void ArrivingFlight::set_is_late(bool isLate) {
    this->isLate = isLate;
}

void ArrivingFlight::set_is_late_str(string is_late) {
    if (is_late == "Yes")
        isLate = true;
    else
        isLate = false;
}

string ArrivingFlight::get_customs_required_str() {
    return get_customs_required() ? "Yes" : "No";
}

bool ArrivingFlight::get_customs_required() {
    return customsRequired;
}

void ArrivingFlight::set_customs_required(bool customsRequired) {
    this->customsRequired = customsRequired;
}

void ArrivingFlight::set_customs_required_str(string customs_required) {
    if (customs_required == "Yes")
        customsRequired = true;
    else
        customsRequired = false;
}

bool ArrivingFlight::get_is_connecting_flight() {
    return isConnectingFlight;
}

string ArrivingFlight::get_is_connecting_flight_str() {
    return get_is_connecting_flight() ? "Yes" : "No";
}

void ArrivingFlight::set_is_connecting_flight(bool isConnectingFlight) {
    this->isConnectingFlight = isConnectingFlight;
}

void ArrivingFlight::set_is_connecting_flight_str(string is_connecting_flight) {
    if (is_connecting_flight == "Yes")
        isConnectingFlight = true;
    else
        isConnectingFlight = false;
}

string ArrivingFlight::get_is_emergency_landing_str() {
    return get_is_emergency_landing() ? "Yes" : "No";
}

bool ArrivingFlight::get_is_emergency_landing() {
    return isEmergencyLanding;
}

void ArrivingFlight::set_is_emergency_landing(bool isEmergencyLanding) {
    this->isEmergencyLanding = isEmergencyLanding;
}

void ArrivingFlight::set_is_emergency_landing_str(string is_emergency_landing) {
    if (is_emergency_landing == "Yes")
        isEmergencyLanding = true;
    else
        isEmergencyLanding = false;
}


DepartingFlight::DepartingFlight() {
    isDepart = false;
    destination = "Empty";
    status = "Empty";
    fuelStatus = "Empty";
    aircraftStatus = "Empty";
}
bool DepartingFlight::get_is_depart() {
    return isDepart;
}

string DepartingFlight::get_is_depart_str() {
    return get_is_depart() ? "Yes" : "No";
}

void DepartingFlight::set_is_depart_str(string is_depart) {
    if (is_depart == "Yes")
        this->isDepart = true;
    else
        this->isDepart = false;
}

void DepartingFlight::set_is_depart(bool isDepart) {
    this->isDepart = isDepart;
}

string DepartingFlight::get_destination() {
    return destination;
}

void DepartingFlight::set_destination(const string &destination) {
    this->destination = destination;
}

string DepartingFlight::get_status() {
    return status;
}

void DepartingFlight::set_status(const string &status) {
    this->status = status;
}

string DepartingFlight::get_fuel_status() {
    return fuelStatus;
}

void DepartingFlight::set_fuel_status(const string &fuelStatus) {
    this->fuelStatus = fuelStatus;
}

string DepartingFlight::get_aircraft_status() {
    return aircraftStatus;
}

void DepartingFlight::set_aircraft_status(const string &aircraftStatus) {
    this->aircraftStatus = aircraftStatus;
}


ArrivingPassengerFlight::ArrivingPassengerFlight() {
    currentPassengerCount = 0;
    gate = "Empty";
    terminal = "Empty";
    isBus = false;
    baggageClaimArea = "Empty";
    specialAssistanceRequired = false;
    isVisa = false;
    isBaggageUnloaded = false;
}

int ArrivingPassengerFlight::get_current_passenger_count() {
    return currentPassengerCount;
}

void ArrivingPassengerFlight::set_current_passenger_count(int currentPassengerCount) {
    this->currentPassengerCount = currentPassengerCount;
}

string ArrivingPassengerFlight::get_gate() {
    return gate;
}

void ArrivingPassengerFlight::set_gate(const string &gate) {
    this->gate = gate;
}

string ArrivingPassengerFlight::get_terminal() {
    return terminal;
}

void ArrivingPassengerFlight::set_terminal(const string &terminal) {
    this->terminal = terminal;
}

bool ArrivingPassengerFlight::get_is_bus() {
    return isBus;
}

string ArrivingPassengerFlight::get_is_bus_str() {
    return isBus ? "Yes" : "No";
}

void ArrivingPassengerFlight::set_is_bus(bool isBus) {
    this->isBus = isBus;
}

void ArrivingPassengerFlight::set_is_bus_str(string is_bus) {
    if (is_bus == "Yes")
        isBus = true;
    else
        isBus = false;
}

string ArrivingPassengerFlight::get_baggage_claim_area() {
    return baggageClaimArea;
}

void ArrivingPassengerFlight::set_baggage_claim_area(const string &baggageClaimArea) {
    this->baggageClaimArea = baggageClaimArea;
}

string ArrivingPassengerFlight::get_special_assistance_required_str() {
    return specialAssistanceRequired ? "Yes" : "No";
}

bool ArrivingPassengerFlight::get_special_assistance_required() {
    return specialAssistanceRequired;
}

void ArrivingPassengerFlight::set_special_assistance_required(bool specialAssistanceRequired) {
    this->specialAssistanceRequired = specialAssistanceRequired;
}

void ArrivingPassengerFlight::set_special_assistance_required_str(string special_assistance_required) {
    if (special_assistance_required == "Yes")
        specialAssistanceRequired = true;
    else
        specialAssistanceRequired = false;
}

bool ArrivingPassengerFlight::get_is_visa() {
    return isVisa;
}

string ArrivingPassengerFlight::get_is_visa_str() {
    return isVisa ? "Yes" : "No";
}

void ArrivingPassengerFlight::set_is_visa(bool isVisa) {
    this->isVisa = isVisa;
}

void ArrivingPassengerFlight::set_is_visa_str(string is_visa) {
    if (is_visa == "Yes")
        isVisa = true;
    else
        isVisa = false;
}

bool ArrivingPassengerFlight::get_is_baggage_unloaded() {
    return isBaggageUnloaded;
}

string ArrivingPassengerFlight::get_is_baggage_unloaded_str() {
    return isBaggageUnloaded ? "Yes" : "No";
}

void ArrivingPassengerFlight::set_is_baggage_unloaded(bool isBaggageUnloaded) {
    this->isBaggageUnloaded = isBaggageUnloaded;
}

void ArrivingPassengerFlight::set_is_baggage_unloaded_str(string is_baggage_unloaded) {
    if (is_baggage_unloaded == "Yes")
        isBaggageUnloaded = true;
    else
        isBaggageUnloaded = false;
}

vector<Passenger>& ArrivingPassengerFlight::get_passenger_list() {
    return passengerList;
}

void ArrivingPassengerFlight::set_passenger_list(const vector<Passenger> &passengerList) {
    this->passengerList = passengerList;
}

vector<CrewMember>& ArrivingPassengerFlight::get_crew_list() {
    return crewList;
}

void ArrivingPassengerFlight::set_crew_list(const vector<CrewMember> &crewList) {
    this->crewList = crewList;
}



ArrivingCargoFlight::ArrivingCargoFlight() {
    cargoMaxWeight = 0.0;
    cargoType = "Empty";
    isCargoUnloaded = false;
}
double ArrivingCargoFlight::get_cargo_max_weight() {
    return cargoMaxWeight;
}

void ArrivingCargoFlight::set_cargo_max_weight(double cargoMaxWeight) {
    this->cargoMaxWeight = cargoMaxWeight;
}

string ArrivingCargoFlight::get_cargo_type() {
    return cargoType;
}

void ArrivingCargoFlight::set_cargo_type(const string &cargoType) {
    this->cargoType = cargoType;
}

bool ArrivingCargoFlight::get_is_cargo_unloaded() {
    return isCargoUnloaded;
}

string ArrivingCargoFlight::get_is_cargo_unloaded_str() {
    return isCargoUnloaded ? "Yes" : "No";
}

void ArrivingCargoFlight::set_is_cargo_unloaded(bool isCargoUnloaded) {
    this->isCargoUnloaded = isCargoUnloaded;
}

void ArrivingCargoFlight::set_is_cargo_unloaded_str(string isCargoUnloaded) {
    if (isCargoUnloaded == "Yes")
        this->isCargoUnloaded = true;
    else
        this->isCargoUnloaded = false;
}



vector<Cargo>& ArrivingCargoFlight::get_cargo_list() {
    return cargoList;
}

void ArrivingCargoFlight::set_cargo_list(const vector<Cargo> &cargoList) {
    this->cargoList = cargoList;
}


DepartingPassengerFlight::DepartingPassengerFlight() {
    terminal = "Empty";
    gate = "Empty";
    passengerMaxValue = 0;
    checkInStartTime = "Empty";
    checkInEndTime = "Empty";
    boardingStartTime = "Empty";
    boardingEndTime = "Empty";
    isBaggageLoaded = false;
}
string DepartingPassengerFlight::get_terminal() {
    return terminal;
}

void DepartingPassengerFlight::set_terminal(const string &terminal) {
    this->terminal = terminal;
}

string DepartingPassengerFlight::get_gate() {
    return gate;
}

void DepartingPassengerFlight::set_gate(const string &gate) {
    this->gate = gate;
}

int DepartingPassengerFlight::get_passenger_max_value() {
    return passengerMaxValue;
}

void DepartingPassengerFlight::set_passenger_max_value(int passengerMaxValue) {
    this->passengerMaxValue = passengerMaxValue;
}

string DepartingPassengerFlight::get_check_in_start_time() {
    return checkInStartTime;
}

void DepartingPassengerFlight::set_check_in_start_time(const string &checkInStartTime) {
    this->checkInStartTime = checkInStartTime;
}

string DepartingPassengerFlight::get_check_in_end_time() {
    return checkInEndTime;
}

void DepartingPassengerFlight::set_check_in_end_time(const string &checkInEndTime) {
    this->checkInEndTime = checkInEndTime;
}

string DepartingPassengerFlight::get_boarding_start_time() {
    return boardingStartTime;
}

void DepartingPassengerFlight::set_boarding_start_time(const string &boardingStartTime) {
    this->boardingStartTime = boardingStartTime;
}

string DepartingPassengerFlight::get_boarding_end_time() {
    return boardingEndTime;
}

void DepartingPassengerFlight::set_boarding_end_time(const string &boardingEndTime) {
    this->boardingEndTime = boardingEndTime;
}

string DepartingPassengerFlight::get_is_baggage_loaded_str() {
    return isBaggageLoaded ? "Yes" : "No";
}

void DepartingPassengerFlight::set_is_baggage_loaded_str(string is_baggage_loaded) {
    if (is_baggage_loaded == "Yes")
        isBaggageLoaded = true;
    else
        isBaggageLoaded = false;

}

bool DepartingPassengerFlight::get_is_baggage_loaded() {
    return isBaggageLoaded;
}

void DepartingPassengerFlight::set_is_baggage_loaded(bool isBaggageLoaded) {
    this->isBaggageLoaded = isBaggageLoaded;
}

vector<Passenger>& DepartingPassengerFlight::get_passenger_list() {
    return passengerList;
}

void DepartingPassengerFlight::set_passenger_list(const vector<Passenger> &passengerList) {
    this->passengerList = passengerList;
}

vector<CrewMember>& DepartingPassengerFlight::get_crew_list() {
    return crewList;
}

void DepartingPassengerFlight::set_crew_list(const vector<CrewMember> &crewList) {
    this->crewList = crewList;
}



DepartingCargoFlight::DepartingCargoFlight() {
    cargoMaxWeight = 0.0;
    cargoType = "Empty";
    isCargoLoaded = false;
    cargoStartLoadTime = "Empty";
    cargoEndLoadTime = "Empty";
}
    double DepartingCargoFlight::get_cargo_max_weight() {
    return cargoMaxWeight;
}

void DepartingCargoFlight::set_cargo_max_weight(double cargoMaxWeight) {
    this->cargoMaxWeight = cargoMaxWeight;
}

string DepartingCargoFlight::get_cargo_type() {
    return cargoType;
}

void DepartingCargoFlight::set_cargo_type(const string &cargoType) {
    this->cargoType = cargoType;
}

bool DepartingCargoFlight::get_is_cargo_loaded() {
    return isCargoLoaded;
}

void DepartingCargoFlight::set_is_cargo_loaded(bool isCargoLoaded) {
    this->isCargoLoaded = isCargoLoaded;
}

string DepartingCargoFlight::get_is_cargo_loaded_str() {
    return isCargoLoaded ? "Yes" : "No";
}

void DepartingCargoFlight::set_is_cargo_loaded_str(string is_cargo_loaded) {
    if (is_cargo_loaded == "Yes")
        isCargoLoaded = true;
    else
        isCargoLoaded = false;
}

string DepartingCargoFlight::get_cargo_start_load_time() {
    return cargoStartLoadTime;
}

void DepartingCargoFlight::set_cargo_start_load_time(const string &cargoStartLoadTime) {
    this->cargoStartLoadTime = cargoStartLoadTime;
}

string DepartingCargoFlight::get_cargo_end_load_time() {
    return cargoEndLoadTime;
}

void DepartingCargoFlight::set_cargo_end_load_time(const string &cargoEndLoadTime) {
    this->cargoEndLoadTime = cargoEndLoadTime;
}

vector<Cargo> DepartingCargoFlight::get_cargo_list() {
    return cargoList;
}

void DepartingCargoFlight::set_cargo_list(const vector<Cargo> &cargoList) {
    this->cargoList = cargoList;
}








///////////////////////////////////////////////////




