#include <iostream>
#include <vector>
#include <iomanip>
#include <array>

/*
    Product Catalog 

    - Display a minimum of 5 products,with name, price , and quantity
    - use appropriate column widths to ensure clean alignment
    - Include a header row with colum tiles
    - Add separator lines between the header and data
    - Format prices to display exactly 2 decimal places
    - Ensure all text is left aligned / numerical values are right aligned
*/

using namespace std;

void printHeaderRow()
{
    cout << setw(10) << left << "Name";
    cout << setw(8) << "Price";
    cout << setw(5) << "Qty";
    cout<< "\n---------------------\n";
}

void PrintTableItems(const array<string,5>& productName, 
                    const array<double,5>& productPrice, 
                    const array<int,5>& productQuantity)
{
    for(int i = 0; i < 3; i++)
    {
        cout << setw(10) << left << productName[i];
        cout << setw(8) << productPrice[i] ;
        cout << setw(5) << productQuantity[i];
        cout << '\n';
    }
}

int main()
{
     array<string,5> productName = {"Apple", "Orange", "Peach", "Watermelon", "Grapes"};
     array<double,5> productPrice = {1.5310, 2.3031, 5.9210, 2.6219, 4.2222};
     array<int,5> productQuantity = {20, 13, 2, 78, 41};

    cout << fixed << setprecision(2);
    printHeaderRow();
    PrintTableItems(productName, productPrice, productQuantity);
    
    return 0;
}
