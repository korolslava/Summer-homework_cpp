#pragma once
#include <iostream>
using namespace std;

class Student {
	string name;
	float average_grade;
public:
	Student() : name(""), average_grade(0.0f) {}
	Student(string name, float average_grade) : name(name), average_grade(average_grade) {}
	Student(const Student& other) : name(other.name), average_grade(other.average_grade) {
		cout << "Copy constructor called for " << name << endl;
	}
	Student& operator=(const Student& other) {
		if (this != &other) {
			name = other.name;
			average_grade = other.average_grade;
			cout << "Copy assignment operator called for " << name << endl;
		}
		return *this;
	}
	Student(Student&& other) noexcept : name(std::move(other.name)), average_grade(other.average_grade) {
		cout << "Move constructor called for " << name << endl;
		other.average_grade = 0.0f;
	}
	~Student() {
		cout << "Student " << name << " destroyed." << endl;
	}

	string getName() const {
		return name;
	}
	float getAverageGrade() const {
		return average_grade;
	}

	void setName(const string& newName) {
		name = newName;
	}
	void setAverageGrade(float newAverageGrade) {
		average_grade = newAverageGrade;
	}

	void print_all_student() const {
		cout << "Name: " << name << ", Average Grade: " << average_grade << endl;
	}
};