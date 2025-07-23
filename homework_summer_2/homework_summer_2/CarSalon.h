#pragma once
#include "Car.h"

class CarSalon {
	string titile;
	Car* cars;
public:
    CarSalon() : titile(""), cars(nullptr) {}

    CarSalon(const string& title, Car* cars) : titile(title), cars(cars) {}

    CarSalon(const CarSalon& other)
        : titile(other.titile)
        , cars(other.cars)
    {
    }

    CarSalon& operator=(const CarSalon& other) {
        if (this != &other) {
            titile = other.titile;
            cars = other.cars;
        }
        return *this;
    }

    CarSalon(CarSalon&& other) noexcept
        : titile(std::move(other.titile))
        , cars(other.cars)
    {
        other.cars = nullptr;
    }

    CarSalon& operator=(CarSalon&& other) noexcept {
        if (this != &other) {
            titile = std::move(other.titile);
            cars = other.cars;
            other.cars = nullptr;
        }
        return *this;
    }

    ~CarSalon() {
		delete[] cars;
		cout << "CarSalon destroyed" << endl;
    }

	void setTitle(const string& newTitle) { titile = newTitle; }
	string getTitle() const { return titile; }

	void print_info() const {
		cout << "Car Salon: " << titile << endl;
		if (cars) {
			for (int i = 0; cars[i].getModel() != ""; ++i) {
				cars[i].print_info();
			}
		}
		else {
			cout << "No cars available." << endl;
		}
	}


	

	


};