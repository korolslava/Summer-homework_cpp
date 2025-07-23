#pragma once
#include "Book.h"

class BookStore {
	string title;
	int year;
	string address;
	Book* books;
public:
	BookStore() : title(""), year(0), address(""), books(nullptr) {}
	BookStore(string t, int y, string a, Book* b)
		: title(t), year(y), address(a), books(b) {
	}
	BookStore(const BookStore& other)
		: title(other.title), year(other.year), address(other.address) {
		if (other.books) {
			books = new Book(*other.books);
		}
		else {
			books = nullptr;
		}
	}
	BookStore(BookStore&& other) noexcept
		: title(std::move(other.title)), year(other.year), address(std::move(other.address)), books(other.books) {
		other.books = nullptr;
	}
	~BookStore() {
		delete books;
		cout << "BookStore destructor called for " << title << endl;
	}
	BookStore& operator=(const BookStore& other) {
		if (this != &other) {
			title = other.title;
			year = other.year;
			address = other.address;
			delete books;
			if (other.books) {
				books = new Book(*other.books);
			}
			else {
				books = nullptr;
			}
		}
		return *this;
	}
	BookStore& operator=(BookStore&& other) noexcept {
		if (this != &other) {
			title = std::move(other.title);
			year = other.year;
			address = std::move(other.address);
			delete books;
			books = other.books;
			other.books = nullptr;
		}
		return *this;
	}

	string getTitle() const { return title; }
	int getYear() const { return year; }
	string getAddress() const { return address; }
	Book* getBooks() const { return books; }

	void setTitle(const string& t) { title = t; }
	void setYear(int y) { year = y; }
	void setAddress(const string& a) { address = a; }
	void setBooks(Book* b) { books = b; }

	void print() const {
		cout << "BookStore: " << title << ", Year: " << year
			<< ", Address: " << address << endl;
		if (books) {
			books->print();
		}
		else {
			cout << "No books available." << endl;
		}
	}
};