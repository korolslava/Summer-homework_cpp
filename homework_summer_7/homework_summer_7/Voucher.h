#pragma once
#include <iostream>
using namespace std;

class Voucher {
	string code;
	double discount;
public:
	Voucher() : code(""), discount(0.0) {}
	Voucher(const string& code, double discount) : code(code), discount(discount) {}
	Voucher(const Voucher& other) : code(other.code), discount(other.discount) {}
	Voucher& operator=(const Voucher& other) {
		if (this != &other) {
			code = other.code;
			discount = other.discount;
		}
		return *this;
	}
	Voucher(Voucher&& other) noexcept : code(std::move(other.code)), discount(other.discount) {
		other.discount = 0.0;
	}
	Voucher& operator=(Voucher&& other) noexcept {
		if (this != &other) {
			code = std::move(other.code);
			discount = other.discount;
			other.discount = 0.0;
		}
		return *this;
	}
	~Voucher() {
		cout << "Voucher destructor called for " << code << endl;
	}

	string getCode() const {
		return code;
	}
	double getDiscount() const {
		return discount;
	}

	void setCode(const string& newCode) {
		code = newCode;
	}
	void setDiscount(double newDiscount) {
		discount = newDiscount;
	}

	void ShowVoucherInformation() {
		cout << "Voucher Code: " << code << endl;
		cout << "Discount: " << discount << endl;
	}
};
