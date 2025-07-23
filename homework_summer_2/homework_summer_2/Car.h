#pragma once
#include "Engine.h"

class Car {
	string model;
	int year;
	Engine engine;
	int price;
public:
	Car() : model(""), year(0), engine(), price(0) {}
	Car(const string& model, int year, const Engine& engine, int price)
		: model(model), year(year), engine(engine), price(price) {
	}
	Car(const Car& other)
		: model(other.model), year(other.year), engine(other.engine), price(other.price) {
	}
	Car& operator=(const Car& other) {
		if (this != &other) {
			model = other.model;
			year = other.year;
			engine = other.engine;
			price = other.price;
		}
		return *this;
	}
	Car(Car&& other) noexcept
		: model(std::move(other.model)), year(other.year), engine(std::move(other.engine)), price(other.price) {
		other.year = 0;
		other.price = 0;
	}
	Car& operator=(Car&& other) noexcept {
		if (this != &other) {
			model = std::move(other.model);
			year = other.year;
			engine = std::move(other.engine);
			price = other.price;
			other.year = 0;
			other.price = 0;
		}
		return *this;
	}
	virtual ~Car() {
		cout << "Car destroyed" << endl;
	}
	void print_info() const {
		cout << "Model: " << model << ", Year: " << year << ", Price: " << price << endl;
		engine.print_engine_info();
	}

	string getModel() const { return model; }
	int getYear() const { return year; }
	const Engine& getEngine() const { return engine; }
	int getPrice() const { return price; }

	void setModel(const string& newModel) { model = newModel; }
	void setYear(int newYear) { year = newYear; }
	void setEngine(const Engine& newEngine) { engine = newEngine; }
	void setPrice(int newPrice) { price = newPrice; }

	void print_car_info() const {
		cout << "Car Model: " << model << ", Year: " << year << ", Price: " << price << endl;
		engine.print_engine_info();
	}
};