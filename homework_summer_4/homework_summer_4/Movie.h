#pragma once
#include <iostream>
using namespace std;

class Movie {
	string title;
	string director;
	int duration;
public:
	Movie() : title(""), director(""), duration(0) {}
	Movie(string t, string d, int dur) : title(t), director(d), duration(dur) {}
	Movie(const Movie& m) : title(m.title), director(m.director), duration(m.duration) {}
	Movie& operator=(const Movie& m) {
		if (this != &m) {
			title = m.title;
			director = m.director;
			duration = m.duration;
		}
		return *this;
	}
	Movie(Movie&& m) noexcept : title(std::move(m.title)), director(std::move(m.director)), duration(m.duration) {
		m.duration = 0;
	}
	Movie& operator=(Movie&& m) noexcept {
		if (this != &m) {
			title = std::move(m.title);
			director = std::move(m.director);
			duration = m.duration;
			m.duration = 0;
		}
		return *this;
	}
	~Movie() {
		cout << "Movie destructor called for: " << title << endl;
	}

	string getTitle() const { return title; }
	string getDirector() const { return director; }
	int getDuration() const { return duration; }

	void setTitle(const string& t) { title = t; }
	void setDirector(const string& d) { director = d; }
	void setDuration(int dur) { duration = dur; }

	void print() const {
		cout << "Movie: " << title << ", Director: " << director << ", Duration: " << duration << " minutes" << endl;
	}
};
