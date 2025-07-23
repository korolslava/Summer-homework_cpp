#pragma once
#include "Flight.h"

class Airport {
    string name;
    Flight* flights;
    int numFlights;
public:
    Airport() : name(""), flights(nullptr), numFlights(0) {}
    Airport(string name) : name(name), flights(nullptr), numFlights(0) {}
    Airport(const Airport& other) : name(other.name), numFlights(other.numFlights) {
        flights = new Flight[other.numFlights];
        for (int i = 0; i < other.numFlights; ++i) {
            flights[i] = other.flights[i];
        }
    }
    Airport& operator=(const Airport& other) {
        if (this != &other) {
            delete[] flights;
            name = other.name;
            numFlights = other.numFlights;
            flights = new Flight[other.numFlights];
            for (int i = 0; i < other.numFlights; ++i) {
                flights[i] = other.flights[i];
            }
        }
        return *this;
    }
    Airport(Airport&& other) noexcept
        : name(move(other.name)), flights(other.flights), numFlights(other.numFlights) {
        other.flights = nullptr;
        other.numFlights = 0;
    }
    Airport& operator=(Airport&& other) noexcept {
        if (this != &other) {
            delete[] flights;
            name = move(other.name);
            flights = other.flights;
            numFlights = other.numFlights;
            other.flights = nullptr;
            other.numFlights = 0;
        }
        return *this;
    }
    ~Airport() {
        delete[] flights;
        cout << "Airport destructor called for " << name << endl;
    }

    void addFlight(const Flight& flight) {
        Flight* newFlights = new Flight[numFlights + 1];
        for (int i = 0; i < numFlights; ++i) {
            newFlights[i] = move(flights[i]);
        }
        newFlights[numFlights] = flight;
        delete[] flights;
        flights = newFlights;
        numFlights++;
    }

    void listFlights() const {
        cout << "Airport: " << name << endl;
        for (int i = 0; i < numFlights; ++i) {
            flights[i].print();
            cout << "-------------------" << endl;
        }
    }

    double calculateTotalLuggage() const {
        double total = 0.0;
        for (int i = 0; i < numFlights; ++i) {
            total += flights[i].getPassenger().getLuggageWeight();
        }
        return total;
    }
};
