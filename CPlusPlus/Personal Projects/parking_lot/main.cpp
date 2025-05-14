#include <iostream>
#include <memory>
#include <thread>

#include "ParkingLot.hpp"
#include "Payment.hpp"
#include "Vehicle.hpp"
#include "constants.hpp"

using namespace std;

void wait(int seconds);

int main()
{
    shared_ptr<Car> tacoma = make_shared<Car>("8NJU760");
    shared_ptr<Car> BMWRR1000 = make_shared<Car>("782NZ29");
    shared_ptr<Car> porsche = make_shared<Car>("98NG2J5");

    ParkingLot parkingLot(4, 12, 10);

    parkingLot.park(0, 0, porsche);

    wait(5);

    parkingLot.leave(porsche);


    return 0;
}

void wait(int seconds)
{
    this_thread::sleep_for(std::chrono::seconds(seconds));
}