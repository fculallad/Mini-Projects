# Problem

https://www.codewars.com/kata/57a429e253ba3381850000fb/train/cpp

Write function bmi that calculates body mass index (bmi = weight / height2).

if bmi <= 18.5 return "Underweight"

if bmi <= 25.0 return "Normal"

if bmi <= 30.0 return "Overweight"

if bmi > 30 return "Obese"


## Solution

<details>
	<Summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string bmi(double w, double h) 
{
    
    double bmi = w / (h * h);
    
    if (bmi <= 18.5) {
        return "Underweight";
    } else if (bmi <= 25.0) {
        return "Normal";
    } else if (bmi <= 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
    
}

```

</details>