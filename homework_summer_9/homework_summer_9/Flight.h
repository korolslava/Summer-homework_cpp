#pragma once
#include"Passenger.h"
class Flight {
    string flightNumber;
    string destination;
    Passenger passenger;
public:
    Flight() : flightNumber(""), destination("") {}
    Flight(string num, string dest, const Passenger& pass)
        : flightNumber(num), destination(dest), passenger(pass) {
    }
    Flight(const Flight& other)
        : flightNumber(other.flightNumber), destination(other.destination), passenger(other.passenger) {
    }
    Flight& operator=(const Flight& other) {
        if (this != &other) {
            flightNumber = other.flightNumber;
            destination = other.destination;
            passenger = other.passenger;
        }
        return *this;
    }
    Flight(Flight&& other) noexcept
        : flightNumber(move(other.flightNumber)), destination(move(other.destination)), passenger(move(other.passenger)) {
    }
    Flight& operator=(Flight&& other) noexcept {
        if (this != &other) {
            flightNumber = move(other.flightNumber);
            destination = move(other.destination);
            passenger = move(other.passenger);
        }
        return *this;
    }
    ~Flight() {
        cout << "Flight destructor called for " << flightNumber << endl;
    }

    string getFlightNumber() const { return flightNumber; }
    string getDestination() const { return destination; }
    const Passenger& getPassenger() const { return passenger; }

    void setFlightNumber(string num) { flightNumber = num; }
    void setDestination(string dest) { destination = dest; }
    void setPassenger(const Passenger& pass) { passenger = pass; }

    void print() const {
        cout << "Flight: " << flightNumber << " to " << destination << endl;
        passenger.print();
    }
};
