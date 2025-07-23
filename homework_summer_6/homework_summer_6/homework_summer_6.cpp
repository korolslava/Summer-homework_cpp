#include "Hotel.h"

int main()
{
	Guest guest1("John Doe", 3, Breakfast);
	Guest guest2("Jane Smith", 2, All);

	Room room1(1, Luxury, 1000, guest1);
	Room room2(2, Standard, 500, guest2);

	Hotel hotel("Grand Hotel", 2);
	hotel.setRooms(new Room[2]{ room1, room2 });
	hotel.printHotelInfo();
	hotel.calculateIncome();
}

