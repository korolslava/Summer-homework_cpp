#pragma once
#include "Faculty.h"

class University {
	string title;
	string location;
	Faculty* faculties;
public:
	University() : title(""), location(""), faculties(nullptr) {}
	University(string title, string location, Faculty* faculties)
		: title(title), location(location), faculties(faculties) {
	}

	University(const University& other)
		: title(other.title), location(other.location), faculties(other.faculties) {
		cout << "Copy constructor called for University " << title << endl;
	}
	University& operator=(const University& other) {
		if (this != &other) {
			title = other.title;
			location = other.location;
			faculties = other.faculties;
			cout << "Copy assignment operator called for University " << title << endl;
		}
		return *this;
	}
	~University() {
		cout << "University " << title << " destroyed." << endl;
	}
	string getTitle() const {
		return title;
	}
	string getLocation() const {
		return location;
	}
	void setTitle(const string& newTitle) {
		title = newTitle;
	}
	void setLocation(const string& newLocation) {
		location = newLocation;
	}

	void print_all_university() const {
		cout << "University Title: " << title << ", Location: " << location << endl;
		for (int i = 0; faculties && faculties[i].getTitle() != ""; ++i) {
			faculties[i].print_all_faculty();
		}
	}
};
