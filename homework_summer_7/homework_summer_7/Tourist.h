#pragma once
#include <iostream>
using namespace std;

enum Nationality {
	Bulgarian,
	American,
	French,
	German,
	Italian,
	Spanish,
	Chinese,
	Japanese,
	Indian,
	Canadian,
	Ukrainian,
	Other
};

class Tourist {
	string name;
	int age;
	Nationality nationality;
public:
	Tourist() : name(""), age(0), nationality(Other) {}
	Tourist(const string& name, int age, Nationality nationality)
		: name(name), age(age), nationality(nationality) {
	}
	Tourist(const Tourist& other)
		: name(other.name), age(other.age), nationality(other.nationality) {
	}
	Tourist& operator=(const Tourist& other) {
		if (this != &other) {
			name = other.name;
			age = other.age;
			nationality = other.nationality;
		}
		return *this;
	}
	Tourist(Tourist&& other) noexcept
		: name(std::move(other.name)), age(other.age), nationality(other.nationality) {
		other.age = 0;
		other.nationality = Other;
	}
	Tourist& operator=(Tourist&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			age = other.age;
			nationality = other.nationality;
			other.age = 0;
			other.nationality = Other;
		}
		return *this;
	}
	~Tourist() {
		cout << "Tourist destructor called for " << name << endl;
	}

	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	Nationality getNationality() const {
		return nationality;
	}

	void setName(const string& newName) {
		name = newName;
	}
	void setAge(int newAge) {
		if (newAge >= 0) {
			age = newAge;
		}
		else {
			cout << "Invalid age" << endl;
		}
	}
	void setNationality(Nationality newNationality) {
		nationality = newNationality;
	}

	void showInfo() {
		cout << "Tourist Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Nationality^" << nationality << endl;
	}
};