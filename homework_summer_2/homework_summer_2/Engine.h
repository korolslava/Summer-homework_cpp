#pragma once
#include <iostream>
#include <string>
using namespace std;

enum EngineType {
	DIESEL,
	GASOLINE,
	ELECTRIC
};

class Engine {
	EngineType type;
	int power;
public:
	Engine() : type(GASOLINE), power(0) {}
	Engine(EngineType type, int power) : type(type), power(power) {}
	Engine(const Engine& other) : type(other.type), power(other.power) {}
	Engine& operator=(const Engine& other) {
		if (this != &other) {
			type = other.type;
			power = other.power;
		}
		return *this;
	}
	Engine(Engine&& other) noexcept : type(other.type), power(other.power) {
		other.type = GASOLINE;
		other.power = 0;
	}
	Engine& operator=(Engine&& other) noexcept {
		if (this != &other) {
			type = other.type;
			power = other.power;
			other.type = GASOLINE;
			other.power = 0;
		}
		return *this;
	}
	~Engine() {
		cout << "Engine destroyed" << endl;
	}

	EngineType getType() const {
		return type;
	}
	int getPower() const {
		return power;
	}
	void setType(EngineType newType) {
		type = newType;
	}
	void setPower(int newPower) {
		power = newPower;
	}
	
	void print_engine_info() const {
		cout << "Engine Type: ";
		switch (type) {
		case DIESEL: cout << "Diesel"; break;
		case GASOLINE: cout << "Gasoline"; break;
		case ELECTRIC: cout << "Electric"; break;
		}
		cout << ", Power: " << power << " HP" << endl;
	}
};

