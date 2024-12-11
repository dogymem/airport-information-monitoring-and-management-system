#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>

class Exception {
private:
    std::string message; // Сообщение об ошибке
public:
    explicit Exception(const std::string& msg) : message(msg) {}
    void showMessage() const;
};

class humanException : public Exception{
public:
    explicit humanException(const std::string& msg) : Exception(msg) {}
};

class pilotException : public Exception{
public:
    explicit pilotException(const std::string& msg) : Exception(msg) {}
};


class passengerException : public Exception{
public:
    explicit passengerException(const std::string& msg) : Exception(msg) {}
};

class crewException : public Exception{
public:
    explicit crewException(const std::string& msg) : Exception(msg) {}
};

class flightException : public Exception{
public:
    explicit flightException(const std::string& msg) : Exception(msg) {}
};

class cargoException : public Exception{
public:
    explicit cargoException(const std::string& msg) : Exception(msg) {}
};

class StackException : public Exception {
public:
    explicit StackException(const std::string& msg) : Exception(msg)  {}
};



#endif //EXCEPTION_H
