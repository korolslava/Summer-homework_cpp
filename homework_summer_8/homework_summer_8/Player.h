#pragma once
#include "Character.h"

class Player {
    string nickname;
    int age;
    Character* characters;
    int numCharacters;
public:
    Player() : nickname(""), age(0), characters(nullptr), numCharacters(0) {}
    Player(string nick, int a, Character* chars, int num)
        : nickname(nick), age(a), numCharacters(num) {
        characters = new Character[num];
        for (int i = 0; i < num; ++i) {
            characters[i] = chars[i];
        }
    }
    Player(const Player& other)
        : nickname(other.nickname), age(other.age), numCharacters(other.numCharacters) {
        characters = new Character[other.numCharacters];
        for (int i = 0; i < other.numCharacters; ++i) {
            characters[i] = other.characters[i];
        }
    }
    Player& operator=(const Player& other) {
        if (this != &other) {
            delete[] characters;
            nickname = other.nickname;
            age = other.age;
            numCharacters = other.numCharacters;
            characters = new Character[other.numCharacters];
            for (int i = 0; i < other.numCharacters; ++i) {
                characters[i] = other.characters[i];
            }
        }
        return *this;
    }
    Player(Player&& other) noexcept
        : nickname(move(other.nickname)), age(other.age),
        characters(other.characters), numCharacters(other.numCharacters) {
        other.characters = nullptr;
        other.numCharacters = 0;
    }
    Player& operator=(Player&& other) noexcept {
        if (this != &other) {
            delete[] characters;
            nickname = move(other.nickname);
            age = other.age;
            characters = other.characters;
            numCharacters = other.numCharacters;
            other.characters = nullptr;
            other.numCharacters = 0;
        }
        return *this;
    }
    ~Player() {
        delete[] characters;
        cout << "Player destructor called for " << nickname << endl;
    }

    string getNickname() const { return nickname; }
    int getAge() const { return age; }
    int getNumCharacters() const { return numCharacters; }
    Character* getCharacters() const { return characters; }

    void setNickname(string nick) { nickname = nick; }
    void setAge(int a) { age = a; }
    void setCharacters(Character* newChars, int num) {
        delete[] characters;
        numCharacters = num;
        characters = new Character[num];
        for (int i = 0; i < num; ++i) {
            characters[i] = newChars[i];
        }
    }

    int getHighestLevel() const {
        if (numCharacters == 0) return 0;
        int maxLevel = characters[0].getLevel();
        for (int i = 1; i < numCharacters; ++i) {
            if (characters[i].getLevel() > maxLevel) {
                maxLevel = characters[i].getLevel();
            }
        }
        return maxLevel;
    }

    void print() const {
        cout << "Player: " << nickname << ", Age: " << age << endl;
        for (int i = 0; i < numCharacters; ++i) {
            cout << "  Character: " << characters[i].getName()
                << ", Level: " << characters[i].getLevel()
                << ", Type: " << characters[i].getType() << endl;
        }
    }
};
