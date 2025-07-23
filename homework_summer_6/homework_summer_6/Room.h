#pragma once
#include "Guest.h"

enum TypeOfRoom {
	Standard = 1,
	Luxury = 2,
};

class Room {
	int roomNumber;
	TypeOfRoom type;
	double pricePerNight;
	Guest guest;
public:
	Room() : roomNumber(0), type(Standard), pricePerNight(0.0) {}
	Room(int roomNumber, TypeOfRoom type, double pricePerNight)
		: roomNumber(roomNumber), type(type), pricePerNight(pricePerNight) {
	}
	Room(const Room& other)
		: roomNumber(other.roomNumber), type(other.type), pricePerNight(other.pricePerNight), guest(other.guest) {
	}
	Room& operator=(const Room& other) {
		if (this != &other) {
			roomNumber = other.roomNumber;
			type = other.type;
			pricePerNight = other.pricePerNight;
			guest = other.guest;
		}
		return *this;
	}
	Room(Room&& other) noexcept
		: roomNumber(other.roomNumber), type(other.type), pricePerNight(other.pricePerNight), guest(std::move(other.guest)) {
		other.roomNumber = 0;
		other.type = Standard;
		other.pricePerNight = 0.0;
	}
	Room& operator=(Room&& other) noexcept {
		if (this != &other) {
			roomNumber = other.roomNumber;
			type = other.type;
			pricePerNight = other.pricePerNight;
			guest = std::move(other.guest);
			other.roomNumber = 0;
			other.type = Standard;
			other.pricePerNight = 0.0;
		}
		return *this;
	}
	 ~Room() {
		cout << "Room " << roomNumber << " is being destroyed." << endl;
	}

	 int getRoomNumber() const {
		 return roomNumber;
	 }
	 TypeOfRoom getType() const {
		 return type;
	 }
	 double getPricePerNight() const {
		 return pricePerNight;
	 }
	 Guest getGuest() const {
		 return guest;
	 }

	 void setGuest(const Guest& newGuest) {
		 guest = newGuest;
	 }
	 void setRoomNumber(int newRoomNumber) {
		 roomNumber = newRoomNumber;
	 }
	 void setType(TypeOfRoom newType) {
		 type = newType;
	 }
	 void setPricePerNight(double newPrice) {
		 pricePerNight = newPrice;
	 }

	 void printRoomInfo() const {
		 cout << "Room Number: " << roomNumber << endl;
		 cout << "Type: " << (type == Standard ? "Standard" : "Luxury") << endl;
		 cout << "Price per Night: $" << pricePerNight << endl;
		 if (guest.getName() != "") {
			 cout << "Guest Name: " << guest.getName() << endl;
			 cout << "Nights Stayed: " << guest.getNofNights() << endl;
			 cout << "Services: " << guest.getServices() << endl;
		 }
		 else {
			 cout << "No guest assigned." << endl;
		 }
	 }

	

};
