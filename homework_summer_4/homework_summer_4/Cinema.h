#pragma once
#include "Session.h"

class Cinema {
	string name;
	Session* sessions;
public:
	Cinema() : name(""), sessions(nullptr) {}
	Cinema(const string& n, Session* s) : name(n), sessions(s) {}
	Cinema(const Cinema& c) : name(c.name), sessions(new Session(*c.sessions)) {}
	Cinema& operator=(const Cinema& c) {
		if (this != &c) {
			name = c.name;
			delete[] sessions;
			sessions = new Session(*c.sessions);
		}
		return *this;
	}
	Cinema(Cinema&& c) noexcept : name(std::move(c.name)), sessions(c.sessions) {
		c.sessions = nullptr;
	}
	Cinema& operator=(Cinema&& c) noexcept {
		if (this != &c) {
			name = std::move(c.name);
			delete[] sessions;
			sessions = c.sessions;
			c.sessions = nullptr;
		}
		return *this;
	}
	~Cinema() {
		delete[] sessions;
		cout << "Cinema destructor called for: " << name << endl;
	}
	const string& getName() const { return name; }
	const Session* getSessions() const { return sessions; }

	void setName(const string& n) { name = n; }
	void setSessions(Session* s) {
		delete[] sessions;
		sessions = s;
	}

	void print() const {
		cout << "Cinema: " << name << endl;
		if (sessions) {
			cout << "Sessions:" << endl;
			for (int i = 0; sessions[i].getMovie().getTitle() != ""; ++i) {
				cout << "  ";
				sessions[i].getMovie().print();
				cout << "  Type: " << sessions[i].getType()
					<< ", Start Time: " << sessions[i].getStartTime()
					<< ", Hall: " << sessions[i].getHall() << endl;
			}
		}
		else {
			cout << "No sessions available." << endl;
		}
	}
};
