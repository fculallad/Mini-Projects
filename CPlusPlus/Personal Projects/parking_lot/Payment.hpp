#pragma once

class Payment
{
    public :
        virtual double calculateCost(double hours) = 0;
        virtual ~Payment();
};

class BikePayment : public Payment
{
    public :
        double calculateCost(double hours);
};

class CarPayment : public Payment
{
    public :
        double calculateCost(double hours);
};

class TruckPayment : public Payment
{
    public :
        double calculateCost(double hours);
};