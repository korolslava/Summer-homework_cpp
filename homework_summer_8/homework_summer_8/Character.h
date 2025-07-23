#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
    string name;
    int level;
    string type;
public:
    Character() : name(""), level(0), type("") {}
    Character(string name, int level, string type)
        : name(name), level(level), type(type) {
    }
    Character(const Character& other)
        : name(other.name), level(other.level), type(other.type) {
    }
    Character& operator=(const Character& other) {
        if (this != &other) {
            name = other.name;
            level = other.level;
            type = other.type;
        }
        return *this;
    }
    Character(Character&& other) noexcept
        : name(move(other.name)), level(other.level), type(move(other.type)) {
        other.level = 0;
    }
    Character& operator=(Character&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            level = other.level;
            type = move(other.type);
            other.level = 0;
        }
        return *this;
    }
    ~Character() {
        cout << "Character destructor called for " << name << endl;
    }

    string getName() const { return name; }
    int getLevel() const { return level; }
    string getType() const { return type; }

    void setName(string n) { name = n; }
    void setLevel(int l) { level = l; }
    void setType(string t) { type = t; }
};