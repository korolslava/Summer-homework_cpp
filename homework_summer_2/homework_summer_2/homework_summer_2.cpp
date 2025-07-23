#include "CarSalon.h"

int main()
{
	Engine engine1(GASOLINE, 500);
	Engine engine2(DIESEL, 300);
	Engine engine3(ELECTRIC, 200);

	Car car1("Toyota Camry", 2020, engine1, 25000);
	Car car2("Honda Civic", 2019, engine2, 22000);
	Car car3("Tesla Model S", 2021, engine3, 80000);

	Car cars[] = { car1, car2, car3, Car() };

	CarSalon salon("Best Cars", cars);

	salon.print_info();
	return 0;
}
