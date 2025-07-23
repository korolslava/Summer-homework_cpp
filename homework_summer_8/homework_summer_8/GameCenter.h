#pragma once
#include "Player.h"

class GameCenter {
    string centerName;
    Player* players;
    int numPlayers;
public:
    GameCenter() : centerName(""), players(nullptr), numPlayers(0) {}
    GameCenter(string name) : centerName(name), players(nullptr), numPlayers(0) {}
    GameCenter(string name, Player* pls, int num)
        : centerName(name), numPlayers(num) {
        players = new Player[num];
        for (int i = 0; i < num; ++i) {
            players[i] = pls[i];
        }
    }
    GameCenter(const GameCenter& other)
        : centerName(other.centerName), numPlayers(other.numPlayers) {
        players = new Player[other.numPlayers];
        for (int i = 0; i < other.numPlayers; ++i) {
            players[i] = other.players[i];
        }
    }
    GameCenter& operator=(const GameCenter& other) {
        if (this != &other) {
            delete[] players;
            centerName = other.centerName;
            numPlayers = other.numPlayers;
            players = new Player[other.numPlayers];
            for (int i = 0; i < other.numPlayers; ++i) {
                players[i] = other.players[i];
            }
        }
        return *this;
    }
    GameCenter(GameCenter&& other) noexcept
        : centerName(move(other.centerName)),
        players(other.players),
        numPlayers(other.numPlayers) {
        other.players = nullptr;
        other.numPlayers = 0;
    }
    GameCenter& operator=(GameCenter&& other) noexcept {
        if (this != &other) {
            delete[] players;
            centerName = move(other.centerName);
            players = other.players;
            numPlayers = other.numPlayers;
            other.players = nullptr;
            other.numPlayers = 0;
        }
        return *this;
    }
    ~GameCenter() {
        delete[] players;
        cout << "GameCenter destructor called for " << centerName << endl;
    }

    void listPlayers() const {
        cout << "Game Center: " << centerName << endl;
        for (int i = 0; i < numPlayers; ++i) {
            players[i].print();
        }
    }

    const Player* findTopPlayer() const {
        if (numPlayers == 0) return nullptr;
        const Player* topPlayer = &players[0];
        int maxLevel = topPlayer->getHighestLevel();
        for (int i = 1; i < numPlayers; ++i) {
            int currentLevel = players[i].getHighestLevel();
            if (currentLevel > maxLevel) {
                maxLevel = currentLevel;
                topPlayer = &players[i];
            }
        }
        return topPlayer;
    }
};
