#include "Cinema.h"

int main()
{
	Movie m1("Inception", "Christopher Nolan", 148);
	Movie m2("The Matrix", "Lana Wachowski, Lilly Wachowski", 136);

	Session s1(m1, Regular, 1200, Hall1);
	Session s2(m2, ThreeD, 1400, Hall2);

	Session sessions[] = { s1, s2 };

	Cinema cinema("Cineplex", sessions);

	cinema.print();

	return 0;
}
