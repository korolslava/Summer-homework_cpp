#pragma once
#include "Author.h"

class Book {
	string title;
	Author author;
	int year;
	float price;
public:
	Book() : title(""), author(), year(0), price(0.0f) {}
	Book(string t, Author a, int y, float p)
		: title(t), author(a), year(y), price(p) {
	}
	Book(const Book& other)
		: title(other.title), author(other.author), year(other.year), price(other.price) {
	}
	Book(Book&& other) noexcept
		: title(std::move(other.title)), author(std::move(other.author)), year(other.year), price(other.price) {
	}
	~Book() {
		cout << "Book destructor called for " << title << endl;
	}

	Book& operator=(const Book& other) {
		if (this != &other) {
			title = other.title;
			author = other.author;
			year = other.year;
			price = other.price;
		}
		return *this;
	}
	Book& operator=(Book&& other) noexcept {
		if (this != &other) {
			title = std::move(other.title);
			author = std::move(other.author);
			year = other.year;
			price = other.price;
		}
		return *this;
	}

	string getTitle() const { return title; }
	Author getAuthor() const { return author; }
	int getYear() const { return year; }
	float getPrice() const { return price; }

	void setTitle(const string& t) { title = t; }
	void setAuthor(const Author& a) { author = a; }
	void setYear(int y) { year = y; }
	void setPrice(float p) { price = p; }

	void print() const {
		cout << "Book: " << title << ", Author: " << author.getName()
			<< ", Year: " << year << ", Price: $" << price << endl;
	}
};
