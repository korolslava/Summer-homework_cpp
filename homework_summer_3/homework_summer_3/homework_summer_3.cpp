#include "BookStore.h"

int main()
{
	Author author1("J.K. Rowling", "United Kingdom");
	Book book1("Harry Potter and the Philosopher's Stone", author1, 1997, 19.99f);
	BookStore store1("Fantasy Books", 2023, "123 Magic Lane", &book1);
	store1.print();

	BookStore store2 = store1;
	store2.print();

	BookStore store3 = std::move(store2);
	store3.print();
	return 0;
}

