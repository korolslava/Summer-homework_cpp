#pragma once
#include <iostream>
#include <string>
using namespace std;

class Passenger {
    string name;
    string passportNumber;
    double luggageWeight;
public:
    Passenger() : name(""), passportNumber(""), luggageWeight(0.0) {}
    Passenger(string name, string passport, double luggage)
        : name(name), passportNumber(passport), luggageWeight(luggage) {
    }
    Passenger(const Passenger& other)
        : name(other.name), passportNumber(other.passportNumber), luggageWeight(other.luggageWeight) {
    }
    Passenger& operator=(const Passenger& other) {
        if (this != &other) {
            name = other.name;
            passportNumber = other.passportNumber;
            luggageWeight = other.luggageWeight;
        }
        return *this;
    }
    Passenger(Passenger&& other) noexcept
        : name(move(other.name)), passportNumber(move(other.passportNumber)), luggageWeight(other.luggageWeight) {
        other.luggageWeight = 0.0;
    }
    Passenger& operator=(Passenger&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            passportNumber = move(other.passportNumber);
            luggageWeight = other.luggageWeight;
            other.luggageWeight = 0.0;
        }
        return *this;
    }
    ~Passenger() {
        cout << "Passenger destructor called for " << name << endl;
    }

    string getName() const { return name; }
    string getPassportNumber() const { return passportNumber; }
    double getLuggageWeight() const { return luggageWeight; }

    void setName(string n) { name = n; }
    void setPassportNumber(string p) { passportNumber = p; }
    void setLuggageWeight(double w) { luggageWeight = w; }

    void print() const {
        cout << "Passenger: " << name << ", Passport: " << passportNumber
            << ", Luggage: " << luggageWeight << " kg" << endl;
    }
};