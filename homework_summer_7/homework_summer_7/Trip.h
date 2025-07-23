#pragma once
#include "Tourist.h"

class Trip {
	string title;
	string destination;
	int duration;
	Tourist tourist;
	double price;
public:
	Trip() : title(""), destination(""), duration(0), price(0.0) {}
	Trip(const string& title, const string& destination, int duration, const Tourist& tourist, double price)
		: title(title), destination(destination), duration(duration), tourist(tourist), price(price) {
	}
	Trip(const Trip& other)
		: title(other.title), destination(other.destination), duration(other.duration),
		tourist(other.tourist), price(other.price) {
	}
	Trip& operator=(const Trip& other) {
		if (this != &other) {
			title = other.title;
			destination = other.destination;
			duration = other.duration;
			tourist = other.tourist;
			price = other.price;
		}
		return *this;
	}
	Trip(Trip&& other) noexcept
		: title(std::move(other.title)), destination(std::move(other.destination)),
		duration(other.duration), tourist(std::move(other.tourist)), price(other.price) {
	}
	Trip& operator=(Trip&& other) noexcept {
		if (this != &other) {
			title = std::move(other.title);
			destination = std::move(other.destination);
			duration = other.duration;
			tourist = std::move(other.tourist);
			price = other.price;
			other.duration = 0;
			other.price = 0.0;
		}
		return *this;
	}
	~Trip() {
		cout << "Trip destructor called for " << title << endl;
	}

	string getTitle() const {
		return title;
	}
	string getDestination() const {
		return destination;
	}
	int getDuration() const {
		return duration;
	}
	Tourist getTourist() const {
		return tourist;
	}
	double getPrice() const {
		return price;
	}

	void setTitle(const string& title) {
		this->title = title;
	}
	void setDestination(const string& destination) {
		this->destination = destination;
	}
	void setDuration(int duration) {
		this->duration = duration;
	}
	void setTourist(const Tourist& tourist) {
		this->tourist = tourist;
	}
	void setPrice(double price) {
		this->price = price;
	}

	void ShowTripInformation() {
		cout << "Trip Title: " << title << endl;
		cout << "Destination: " << destination << endl;
		cout << "Duration: " << duration << endl;
		tourist.showInfo();
		cout << "Price: " << price << endl;
	}
};
