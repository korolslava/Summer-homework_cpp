#pragma once
#include <iostream>
using namespace std;

class Author {
	string name;
	string country;
public:
	Author() : name(""), country("") {}
	Author(string n, string c) : name(n), country(c) {}

	Author(const Author& other)
		: name(other.name), country(other.country) {
	}

	Author(Author&& other) noexcept
		: name(std::move(other.name)), country(std::move(other.country)) {
	}

	Author& operator=(const Author& other) {
		if (this != &other) {
			name = other.name;
			country = other.country;
		}
		return *this;
	}

	Author& operator=(Author&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			country = std::move(other.country);
		}
		return *this;
	}

	~Author() {
		cout << "Author destructor called for " << name << endl;
	}

	string getName() const { return name; }
	string getCountry() const { return country; }

	void setName(const string& n) { name = n; }
	void setCountry(const string& c) { country = c; }

	void print() const {
		cout << "Author: " << name << ", Country: " << country << endl;
	}
};