#include "Payment.hpp"

Payment::~Payment() = default;

double BikePayment::calculateCost(double hours)
{ return hours * 1; }

double CarPayment::calculateCost(double hours)
{ return hours * 2; }

double TruckPayment::calculateCost(double hours)
{ return hours * 5; }