#pragma once
#include "Student.h"

class Faculty {
	string title;
	int number_of_students;
	Student* students;
public:
	Faculty() : title(""), number_of_students(0), students(nullptr) {}
	Faculty(string title, int number_of_students, Student* students)
		: title(title), number_of_students(number_of_students), students(students) {
	}
	Faculty(const Faculty& other)
		: title(other.title), number_of_students(other.number_of_students), students(other.students) {
		cout << "Copy constructor called for Faculty " << title << endl;
	}
	Faculty& operator=(const Faculty& other) {
		if (this != &other) {
			title = other.title;
			number_of_students = other.number_of_students;
			students = other.students;
			cout << "Copy assignment operator called for Faculty " << title << endl;
		}
		return *this;
	}
	~Faculty() {
		cout << "Faculty " << title << " destroyed." << endl;
	}
	string getTitle() const {
		return title;
	}
	int getNumberOfStudents() const {
		return number_of_students;
	}
	void setTitle(const string& newTitle) {
		title = newTitle;
	}
	void setNumberOfStudents(int newNumberOfStudents) {
		number_of_students = newNumberOfStudents;
	}

	void print_all_faculty() const {
		cout << "Faculty Title: " << title << ", Number of Students: " << number_of_students << endl;
		for (int i = 0; i < number_of_students; ++i) {
			students[i].print_all_student();
		}
	}
};
