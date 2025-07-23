#pragma once
#include <iostream>
using namespace std;

enum role {
	programmer,
	designer,
	analyst,
	soundDesigner,
	notGiven
};

class Developer {
	string name;
	role position;
	int experience;
public:
	Developer(string n, role r, int exp) : name(n), position(r), experience(exp) {}
	Developer() : name("Developer_1"), position(notGiven), experience(0) {}
	Developer(const Developer& d) : name(d.name), position(d.position), experience(d.experience) {
		cout << "Copy constructor called for " << name << endl;
	}
	Developer& operator=(const Developer& d) {
		if (this != &d) {
			name = d.name;
			position = d.position;
			experience = d.experience;
			cout << "Copy assignment operator called for " << name << endl;
		}
		return *this;
	}
	Developer(Developer&& d) noexcept : name(std::move(d.name)), position(d.position), experience(d.experience) {
		d.position = notGiven;
		cout << "Move constructor called for " << name << endl;
	}
	~Developer() {
		cout << "Destructor called for " << name << endl;
	}

	string getName() const {
		return name;
	}
	role getPosition() const {
		return position;
	}
	int getExperience() const {
		return experience;
	}

	void setName(const string& n) {
		name = n;
	}
	void setPosition(role r) {
		position = r;
	}
	void setExperience(int exp) {
		experience = exp;
	}

	void showInfo() const {
		cout << "Name: " << name << endl << ", Position: ";
		switch (position) {
		case programmer: cout << "Programmer" << endl; break;
		case designer: cout << "Designer" << endl; break;
		case analyst: cout << "Analyst" << endl; break;
		case soundDesigner: cout << "Sound Designer" << endl; break;
		default: cout << "Not Given" << endl; break;
		}
		cout << ", Experience: " << experience << " years" << endl;
	}
};
