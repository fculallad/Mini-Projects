#pragma once

#include <map>
#include <memory>
#include <iomanip>

#include "Vehicle.hpp"

using namespace std;

class ParkingLot
{
    public :
        ParkingLot(int floors, int rows, int spotsPerRow);

        bool park(int floor, int row, shared_ptr<Vehicle> vehicle);
        bool leave(shared_ptr<Vehicle> vehicle);
        double calculateParkHours(shared_ptr<Vehicle> vehicle);
        int getAvailableSpots(int floor);

    private :
        map<int, map<int, map<string, shared_ptr<Vehicle>>>> spots_;
        int floors_, rows_, spotsPerRow_;
};

ostream& operator<<(ostream& os, const VehicleType& vehicle);