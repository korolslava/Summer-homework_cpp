#pragma once
#include "Trip.h"
#include "Voucher.h"

class TravelAgency {
	string name;
	Trip* trips;
	Voucher* vouchers;
public:
	TravelAgency() : trips(nullptr), vouchers(nullptr) {}
	TravelAgency(const string& name, Trip* trips, Voucher* vouchers)
		: name(name), trips(trips), vouchers(vouchers) {
	}
	TravelAgency(const TravelAgency& other)
		: name(other.name), trips(nullptr), vouchers(nullptr) {
		if (other.trips) {
			trips = new Trip[10];
			for (int i = 0; i < 10; ++i) {
				trips[i] = other.trips[i];
			}
		}
		if (other.vouchers) {
			vouchers = new Voucher[10];
			for (int i = 0; i < 10; ++i) {
				vouchers[i] = other.vouchers[i];
			}
		}
	}
	TravelAgency& operator=(const TravelAgency& other) {
		if (this != &other) {
			name = other.name;
			delete[] trips;
			delete[] vouchers;
			if (other.trips) {
				trips = new Trip[10];
				for (int i = 0; i < 10; ++i) {
					trips[i] = other.trips[i];
				}
			}
			else {
				trips = nullptr;
			}
			if (other.vouchers) {
				vouchers = new Voucher[10];
				for (int i = 0; i < 10; ++i) {
					vouchers[i] = other.vouchers[i];
				}
			}
			else {
				vouchers = nullptr;
			}
		}
		return *this;
	}
	TravelAgency(TravelAgency&& other) noexcept
		: name(std::move(other.name)), trips(other.trips), vouchers(other.vouchers) {
		other.trips = nullptr;
		other.vouchers = nullptr;
	}
	TravelAgency& operator=(TravelAgency&& other) noexcept {
		if (this != &other) {
			name = std::move(other.name);
			delete[] trips;
			delete[] vouchers;
			trips = other.trips;
			vouchers = other.vouchers;
			other.trips = nullptr;
			other.vouchers = nullptr;
		}
		return *this;
	}
	TravelAgency(const string& name, int tripCount, int voucherCount)
		: name(name)
	{
		trips = new Trip[tripCount];
		vouchers = new Voucher[voucherCount];
	}
	~TravelAgency() {
		delete[] trips;
		delete[] vouchers;
		cout << "TravelAgency destructor called for " << name << endl;
	}

	string getName() const {
		return name;
	}
	Trip* getTrips() const {
		return trips;
	}
	Voucher* getVouchers() const {
		return vouchers;
	}

	void setName(const string& name) {
		this->name = name;
	}
	void setTrips(Trip* trips) {
		delete[] this->trips;
		this->trips = trips;
	}
	void setVouchers(Voucher* vouchers) {
		delete[] this->vouchers;
		this->vouchers = vouchers;
	}

	void showInfo() {
		cout << "TravelAgency Name: " << name << endl;
		cout << "Trips: " << trips << endl;
		cout << "Vouchers: " << vouchers << endl;
		for (int i = 0; i < 10; ++i) {
			trips[i].ShowTripInformation();
		}
		for (int i = 0; i < 10; ++i) {
			vouchers[i].ShowVoucherInformation();
		}
	}

	void applyVouchers() {
		for (int i = 0; i < 10; ++i) {
			if (vouchers[i].getCode() == "Voucher1") {
				vouchers[i].ShowVoucherInformation();
			}
			else {
				cout << "No vouchers found" << endl;
			}

		}
	}
};
