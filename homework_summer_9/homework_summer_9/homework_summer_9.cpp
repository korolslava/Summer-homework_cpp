#include "Airport.h"

int main()
{
    Passenger p1("John Doe", "AB123456", 23.5);
    Passenger p2("Jane Smith", "CD789012", 15.0);
    Passenger p3("Bob Johnson", "EF345678", 32.1);

    Flight f1("FL123", "New York", p1);
    Flight f2("FL456", "London", p2);
    Flight f3("FL789", "Paris", p3);

    Airport airport("International Airport");
    airport.addFlight(f1);
    airport.addFlight(f2);
    airport.addFlight(f3);

    airport.listFlights();
    cout << "Total luggage weight: " << airport.calculateTotalLuggage() << " kg" << endl;

    return 0;
}
