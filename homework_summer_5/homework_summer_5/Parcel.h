#pragma once
#include "Recipient.h"

class Parcel {
	int ID;
	double weight;
	Recipient recipient;
public:
	Parcel(int ID, double weight, const Recipient& recipient)
		: ID(ID), weight(weight), recipient(recipient) {
	}
	Parcel() : ID(0), weight(0.0), recipient() {
	}
	Parcel(const Parcel& other)
		: ID(other.ID), weight(other.weight), recipient(other.recipient) {
	}
	Parcel& operator=(const Parcel& other) {
		if (this != &other) {
			ID = other.ID;
			weight = other.weight;
			recipient = other.recipient;
		}
		return *this;
	}
	Parcel(Parcel&& other) noexcept
		: ID(other.ID), weight(other.weight), recipient(std::move(other.recipient)) {
	}
	Parcel& operator=(Parcel&& other) noexcept {
		if (this != &other) {
			ID = other.ID;
			weight = other.weight;
			recipient = std::move(other.recipient);
		}
		return *this;
	}

	~Parcel() {
		cout << "Parcel destructor called for ID: " << ID << endl;
	}

	int getID() const {
		return ID;
	}
	double getWeight() const {
		return weight;
	}
	const Recipient& getRecipient() const {
		return recipient;
	}

	void setID(int newID) {
		ID = newID;
	}
	void setWeight(double newWeight) {
		weight = newWeight;
	}
	void setRecipient(const Recipient& newRecipient) {
		recipient = newRecipient;
	}

	void printDetails() const {
		cout << "Parcel ID: " << ID << ", Weight: " << weight
			<< ", Recipient: " << recipient.getName()
			<< ", Town: " << recipient.getTown()
			<< ", Phone: " << recipient.getPhoneNumber() << endl;
	}
};
