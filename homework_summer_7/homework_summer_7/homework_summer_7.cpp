#include "TravelAgency.h"

int main() {
    TravelAgency agency("TravelAgency", 5, 5);

    Trip trip1("Trip1", "Destination1", 10, Tourist("Tourist1", 20, Bulgarian), 100.0);
    Trip trip2("Trip2", "Destination2", 20, Tourist("Tourist2", 30, American), 200.0);
    Trip trip3("Trip3", "Destination3", 30, Tourist("Tourist3", 40, French), 300.0);
    Trip trip4("Trip4", "Destination4", 40, Tourist("Tourist4", 50, German), 400.0);
    Trip trip5("Trip5", "Destination5", 50, Tourist("Tourist5", 60, Italian), 500.0);

    Trip* trips = new Trip[5];
    trips[0] = trip1;
    trips[1] = trip2;
    trips[2] = trip3;
    trips[3] = trip4;
    trips[4] = trip5;

    Voucher* vouchers = new Voucher[5];
    vouchers[0] = Voucher("Voucher1", 10.0);
    vouchers[1] = Voucher("Voucher2", 20.0);
    vouchers[2] = Voucher("Voucher3", 30.0);
    vouchers[3] = Voucher("Voucher4", 40.0);
    vouchers[4] = Voucher("Voucher5", 50.0);

    agency.setTrips(trips);
    agency.setVouchers(vouchers);

    agency.showInfo();
    agency.applyVouchers();

    delete[] trips;
    delete[] vouchers;

    return 0;

}