#pragma once
#include <iostream>
using namespace std;

class Recipient {
	string name;
	string town;
	int phone_number;
public:
	Recipient(string name, string town, int phone_number)
		: name(name), town(town), phone_number(phone_number) {
	}
	Recipient() : name(""), town(""), phone_number(0) {
	}
	Recipient(const Recipient& other)
		: name(other.name), town(other.town), phone_number(other.phone_number) {
	}
	Recipient& operator=(const Recipient& other) {
		if (this != &other) {
			name = other.name;
			town = other.town;
			phone_number = other.phone_number;
		}
		return *this;
	}
	Recipient(Recipient&& other) noexcept
		: name(std::move(other.name)), town(std::move(other.town)), phone_number(other.phone_number) {
		other.phone_number = 0;
	}
	Recipient& operator=(Recipient&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			town = std::move(other.town);
			phone_number = other.phone_number;
			other.phone_number = 0;
		}
		return *this;
	}
	~Recipient() {
		cout << "Recipient destructor called for " << name << endl;
	}

	string getName() const {
		return name;
	}
	string getTown() const {
		return town;
	}
	int getPhoneNumber() const {
		return phone_number;
	}

	void setName(const string& newName) {
		name = newName;
	}
	void setTown(const string& newTown) {
		town = newTown;
	}
	void setPhoneNumber(int newPhoneNumber) {
		phone_number = newPhoneNumber;
	}
	
	void print() const {
		cout << "Recipient Name: " << name << ", Town: " << town << ", Phone Number: " << phone_number << endl;
	}
};

