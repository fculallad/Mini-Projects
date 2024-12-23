# Problem 
You get an array of numbers, return the sum of all of the positives ones.

## Template

```cpp

#include <vector>

int positive_sum (const std::vector<int> arr){
  // Your code here
  return -1;
}

```

# Solution

<details> 
	<summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int positive_sum (vector<int> arr){

    int sum{};
    
    for(char c : arr){
        if(c > 0){
            sum += c;
        }
    }
    return sum;
}

```
</details>
