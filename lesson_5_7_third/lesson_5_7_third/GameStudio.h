#pragma once
#include "Game.h"

class GameStudio {
	string name;
	int foundedYear;
	Game* games;
	int gameCount;
public:
	GameStudio(string n, int year, Game* g, int count)
		: name(n), foundedYear(year), games(g), gameCount(count) {
		cout << "GameStudio constructor called for " << name << endl;
	}
	GameStudio() : name("Default Studio"), foundedYear(2000), games(nullptr), gameCount(0) {
		cout << "Default GameStudio constructor called" << endl;
	}
	GameStudio(const GameStudio& gs)
		: name(gs.name), foundedYear(gs.foundedYear), gameCount(gs.gameCount) {
		games = new Game[gameCount];
		for (int i = 0; i < gameCount; ++i) {
			games[i] = gs.games[i];
		}
		cout << "Copy constructor called for GameStudio: " << name << endl;
	}
	GameStudio& operator=(const GameStudio& gs) {
		if (this != &gs) {
			name = gs.name;
			foundedYear = gs.foundedYear;
			gameCount = gs.gameCount;
			delete[] games;
			games = new Game[gameCount];
			for (int i = 0; i < gameCount; ++i) {
				games[i] = gs.games[i];
			}
			cout << "Copy assignment operator called for GameStudio: " << name << endl;
		}
		return *this;
	}
	GameStudio(GameStudio&& gs) noexcept
		: name(std::move(gs.name)), foundedYear(gs.foundedYear), games(gs.games), gameCount(gs.gameCount) {
		gs.games = nullptr;
		cout << "Move constructor called for GameStudio: " << name << endl;
	}
	~GameStudio() {
		delete[] games;
		cout << "Destructor called for GameStudio: " << name << endl;
	}

	void ShowAllGames() const {
		cout << "Game Studio: " << name << endl;
		cout << "Founded Year: " << foundedYear << endl;
		cout << "Games Developed: " << gameCount << endl;
		for (int i = 0; i < gameCount; ++i) {
			games[i].showInfo();
			cout << endl;
		}
	}
};
