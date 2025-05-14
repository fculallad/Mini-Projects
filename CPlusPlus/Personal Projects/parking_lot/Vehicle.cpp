#include "Vehicle.hpp"

using namespace std;

Vehicle::Vehicle(const string& licensePlate) : licensePlate_(licensePlate) {}
Vehicle::~Vehicle() = default;

chrono::time_point<std::chrono::system_clock> Vehicle::getParkedTime()
{
    return parkedTime_;
}

string Vehicle::getNumberPlate() { return licensePlate_; }

void Vehicle::setParkedTime()
{
    parkedTime_ = chrono::system_clock::now();
}

double Vehicle::calculateCost(double hours)
{
    return payment_-> calculateCost(hours);
}

Bike::Bike(const string& licensePlate)
: Vehicle(licensePlate)
{
    payment_ = make_unique<BikePayment>();
}

VehicleType Bike::getType()
{
    return VehicleType::Bike;
}

Car::Car(const string& licensePlate)
: Vehicle(licensePlate)
{
    payment_ = make_unique<CarPayment>();
}

VehicleType Car::getType()
{
    return VehicleType::Car;
}

Truck::Truck(const string& licensePlate)
: Vehicle(licensePlate)
{
    payment_ = make_unique<TruckPayment>();
}

VehicleType Truck::getType()
{
    return VehicleType::Truck;
}