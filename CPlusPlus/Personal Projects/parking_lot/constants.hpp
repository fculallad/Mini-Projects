#pragma once

#include <iostream>

enum class VehicleType
{
    Bike, Car, Truck
};

struct Location
{
    std::string streetAdress, city, state;
    std::string zipCode, country;
};