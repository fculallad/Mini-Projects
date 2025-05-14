#pragma once

#include <chrono>
#include <string>
#include <memory>

#include "constants.hpp"
#include "Payment.hpp"

using namespace std;

class Vehicle
{
    public :
        Vehicle(const string& licensePlate);
        virtual ~Vehicle();

        chrono::time_point<chrono::system_clock> getParkedTime();
        string getNumberPlate();
        virtual VehicleType getType() = 0;
        void setParkedTime();
        double calculateCost(double hours);

    protected :
        string licensePlate_;
        chrono::time_point<chrono::system_clock> parkedTime_;
        unique_ptr<Payment> payment_;
};

class Bike : public Vehicle
{
    public :
        Bike(const string& licensePlate);
        enum VehicleType getType();
};

class Truck : public Vehicle
{
    public :
        Truck(const string& licensePlate);
        enum VehicleType getType();
};

class Car : public Vehicle
{
    public :
        Car(const string& licensePlate);
        enum VehicleType getType();
};