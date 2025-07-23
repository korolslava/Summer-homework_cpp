#pragma once
#include "Room.h"

class Hotel {
	string name;
	int numberOfRooms;
	Room* rooms;
public:
	Hotel() : name(""), numberOfRooms(0), rooms(nullptr) {}
	Hotel(string name, int numberOfRooms)
		: name(name), numberOfRooms(numberOfRooms) {
		rooms = new Room[numberOfRooms];
	}
	Hotel(const Hotel& other)
		: name(other.name), numberOfRooms(other.numberOfRooms) {
		if (numberOfRooms > 0) {
			rooms = new Room[numberOfRooms];
			for (int i = 0; i < numberOfRooms; ++i) {
				rooms[i] = other.rooms[i];
			}
		}
		else {
			rooms = nullptr;
		}
	}
	Hotel& operator=(const Hotel& other) {
		if (this != &other) {
			delete[] rooms;
			name = other.name;
			numberOfRooms = other.numberOfRooms;
			if (numberOfRooms > 0) {
				rooms = new Room[numberOfRooms];
				for (int i = 0; i < numberOfRooms; ++i) {
					rooms[i] = other.rooms[i];
				}
			}
			else {
				rooms = nullptr;
			}
		}
		return *this;
	}
	Hotel(Hotel&& other) noexcept
		: name(std::move(other.name)), numberOfRooms(other.numberOfRooms), rooms(other.rooms) {
		other.rooms = nullptr;
	}
	Hotel& operator=(Hotel&& other) noexcept {
		if (this != &other) {
			delete[] rooms;
			name = std::move(other.name);
			numberOfRooms = other.numberOfRooms;
			rooms = other.rooms;
			other.rooms = nullptr;
		}
		return *this;
	}
	~Hotel() {
		delete[] rooms;
		cout << "Hotel " << name << " is being destroyed." << endl;
	};

	string getName() const {
		return name;
	}
	int getNumberOfRooms() const {
		return numberOfRooms;
	}
	Room* getRooms() const {
		return rooms;
	}

	void setName(const string& newName) {
		name = newName;
	}
	void setNumberOfRooms(int newNumberOfRooms) {
		if (newNumberOfRooms != numberOfRooms) {
			delete[] rooms;
			numberOfRooms = newNumberOfRooms;
			if (numberOfRooms > 0) {
				rooms = new Room[numberOfRooms];
			}
			else {
				rooms = nullptr;
			}
		}
	}
	void setRooms(Room* newRooms) {
		delete[] rooms;
		rooms = newRooms;
		numberOfRooms = (newRooms != nullptr) ? sizeof(newRooms) / sizeof(Room) : 0;
	}

	void printHotelInfo() const {
		cout << "Hotel Name: " << name << endl;
		cout << "Number of Rooms: " << numberOfRooms << endl;
		if (rooms != nullptr) {
			for (int i = 0; i < numberOfRooms; ++i) {
				rooms[i].printRoomInfo();
			}
		}
		else {
			cout << "No rooms available." << endl;
		}
	}

	void calculateIncome() const {
		double totalIncome = 0.0;
		for (int i = 0; i < numberOfRooms; ++i) {
			if (rooms[i].getGuest().getName() != "") {
				totalIncome += rooms[i].getPricePerNight() * rooms[i].getGuest().getNofNights();
			}
		}
		cout << "Total Income: $" << totalIncome << endl;
	}
};