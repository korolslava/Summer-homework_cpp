#pragma once
#include <iostream>
using namespace std;

enum additionalServices {
	None = 0,
	Breakfast = 1,
	Lunch = 2,
	Dinner = 4,
	All = Breakfast | Lunch | Dinner
};

class Guest {
	string name;
	int NofNights;
	additionalServices services;
public:
	Guest() : name(""), NofNights(0), services(None) {}
	Guest(string name, int NofNights, additionalServices services)
		: name(name), NofNights(NofNights), services(services) {
	}
	Guest(const Guest& other)
		: name(other.name), NofNights(other.NofNights), services(other.services) {
	}
	Guest& operator=(const Guest& other) {
		if (this != &other) {
			name = other.name;
			NofNights = other.NofNights;
			services = other.services;
		}
		return *this;
	}
	Guest(Guest&& other) noexcept
		: name(std::move(other.name)), NofNights(other.NofNights), services(other.services) {
		other.NofNights = 0;
		other.services = None;
	}
	Guest& operator=(Guest&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			NofNights = other.NofNights;
			services = other.services;
			other.NofNights = 0;
			other.services = None;
		}
		return *this;
	}
	~Guest() {
		cout << "Guest " << name << " is being destroyed." << endl;
	}

	string getName() const {
		return name;
	}
	int getNofNights() const {
		return NofNights;
	}
	additionalServices getServices() const {
		return services;
	}

	void setName(const string& newName) {
		name = newName;
	}
	void setNofNights(int newNofNights) {
		NofNights = newNofNights;
	}
	void setServices(additionalServices newServices) {
		services = newServices;
	}

	void print() const {
		cout << "Guest Name: " << name << ", Nights: " << NofNights
			<< ", Services: " << services << endl;
	}
	
};

