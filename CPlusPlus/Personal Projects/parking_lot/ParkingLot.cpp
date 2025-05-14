#include "ParkingLot.hpp"

ParkingLot::ParkingLot(int floors, int rows, int spotsPerRow)
: floors_(floors)
, rows_(rows)
, spotsPerRow_(spotsPerRow)
{}

ostream& operator<<(ostream& os, const VehicleType& vehicle)
{
    switch(vehicle)
    {
        case VehicleType::Car : return os << "Car";
        case VehicleType::Bike : return os << "Bike";
        case VehicleType::Truck : return os << "Truck";
    }
}


bool ParkingLot::park(int floor, int row, shared_ptr<Vehicle> vehicle)
{
    string numberPlate = vehicle -> getNumberPlate();
    
    if(spots_[floor][row].size() > spotsPerRow_)
    {
        cerr << "The Row on this floor is already full!." << endl;
        return false;
    }

    spots_[floor][row][numberPlate] = vehicle;
    vehicle->setParkedTime();
    
    cout << vehicle -> getType() << " parked successfully at floor " << floor << ", row " << row << ".";
    return true;
}

bool ParkingLot::leave(shared_ptr<Vehicle> vehicle)
{
    for(int i = 0; i < floors_; i++)
    {
        for(int j = 0; j < rows_; j++)
        {
            string licensePlate = vehicle->getNumberPlate();
            
            if(spots_[i][j].find(licensePlate) != spots_[i][j].end())
            {
                weak_ptr<Vehicle> owner = spots_[i][j][vehicle->getNumberPlate()];
                double hours = calculateParkHours(owner.lock());
                double cost = owner.lock()->calculateCost(hours);
                spots_[i][j].erase(licensePlate);

                cout << setprecision(2) << fixed;
                cout << endl << vehicle->getType() << " left successfully!" << endl;
                cout << "Total Cost : $" << cost << endl;
                return true;
            }
        }
    }
    return false;
}

double ParkingLot::calculateParkHours(shared_ptr<Vehicle> vehicle)
{
    for(int i = 0; i < floors_; i++)
    {
        for(int j = 0; j < rows_; j++)
        {
            string numberPlate = vehicle->getNumberPlate();
            
            if(spots_[i][j].find(numberPlate) != spots_[i][j].end())
            {
                weak_ptr<Vehicle> vehicleOwner = spots_[i][j][numberPlate];
                auto currentTime = chrono::system_clock::now();
                auto parkedTime = vehicleOwner.lock()->getParkedTime();
                auto duration = chrono::duration_cast<chrono::seconds>(currentTime - parkedTime);

                return duration.count();
            }
        }
    }
    return 0;
}

int ParkingLot::getAvailableSpots(int floor)
{
    int count = 0;

    for(int i = 0; i < rows_; i++)
    {
        count += spotsPerRow_ - static_cast<int>(spots_[floor][i].size());
    }
    return count;
}