#pragma once
#include "Developer.h"

class Game {
	string title;
	float rating;
	Developer lead;
public:
	Game(string t, float r, const Developer& d) : title(t), rating(r), lead(d) {
		cout << "Game constructor called for " << title << endl;
	}
	Game() : title("Untitled Game"), rating(0.0f), lead() {
		cout << "Default Game constructor called" << endl;
	}
	Game(const Game& g) : title(g.title), rating(g.rating), lead(g.lead) {
		cout << "Copy constructor called for Game: " << title << endl;
	}
	Game& operator=(const Game& g) {
		if (this != &g) {
			title = g.title;
			rating = g.rating;
			lead = g.lead;
			cout << "Copy assignment operator called for Game: " << title << endl;
		}
		return *this;
	}
	Game(Game&& g) noexcept : title(std::move(g.title)), rating(g.rating), lead(std::move(g.lead)) {
		g.rating = 0.0f;
		cout << "Move constructor called for Game: " << title << endl;
	}
	~Game() {
		cout << "Destructor called for Game: " << title << endl;
	}

	void showInfo() const {
		cout << "Game Title: " << title << endl;
		cout << "Rating: " << rating << endl;
		cout << "Lead Developer: " << endl;
		showInfo();
	}

	string getTitle() const {
		return title;
	}
	float getRating() const {
		return rating;
	}
	Developer getLead() const {
		return lead;
	}

	void setTitle(const string& t) {
		title = t;
	}
	void setRating(float r) {
		rating = r;
	}
	void setLead(const Developer& d) {
		lead = d;
	}
};