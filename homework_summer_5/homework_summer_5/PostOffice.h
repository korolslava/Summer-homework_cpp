#pragma once
#include "Parcel.h"

class PostOffice {
	Parcel* parcels;
	string name_of_post_Office;
public:
	PostOffice() : parcels(nullptr), name_of_post_Office("") {
	}
	PostOffice(const string& name) : parcels(nullptr), name_of_post_Office(name) {
	}
	PostOffice(const PostOffice& other) : name_of_post_Office(other.name_of_post_Office) {
		if (other.parcels) {
			parcels = new Parcel(*other.parcels);
		}
		else {
			parcels = nullptr;
		}
	}
	PostOffice& operator=(const PostOffice& other) {
		if (this != &other) {
			name_of_post_Office = other.name_of_post_Office;
			delete parcels;
			if (other.parcels) {
				parcels = new Parcel(*other.parcels);
			}
			else {
				parcels = nullptr;
			}
		}
		return *this;
	}
	PostOffice(PostOffice&& other) noexcept
		: parcels(other.parcels), name_of_post_Office(std::move(other.name_of_post_Office)) {
		other.parcels = nullptr;
	}
	PostOffice& operator=(PostOffice&& other) noexcept {
		if (this != &other) {
			delete parcels;
			parcels = other.parcels;
			name_of_post_Office = std::move(other.name_of_post_Office);
			other.parcels = nullptr;
		}
		return *this;
	}
	~PostOffice() {
		delete parcels;
		cout << "PostOffice destructor called for " << name_of_post_Office << endl;
	}

	string getNameOfPostOffice() const {
		return name_of_post_Office;
	}
	void setNameOfPostOffice(const string& newName) {
		name_of_post_Office = newName;
	}

	Parcel* getParcels() const {
		return parcels;
	}
	void setParcels(Parcel* newParcels) {
		delete parcels;
		parcels = newParcels;
	}
	
	void printDetails() const {
		cout << "Post Office Name: " << name_of_post_Office << endl;
		if (parcels) {
			cout << "Parcel ID: " << parcels->getID() << ", Weight: " << parcels->getWeight()
				<< ", Recipient: " << parcels->getRecipient().getName() << endl;
		}
		else {
			cout << "No parcels available." << endl;
		}
	}

};