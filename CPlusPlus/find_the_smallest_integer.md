# Problem
Given an array of integers your solution should find the smallest integer.

For example:

Given [34, 15, 88, 2] your solution will return 2
Given [34, -345, -1, 100] your solution will return -345
You can assume, for the purpose of this kata, that the supplied array will not be empty.

## Template

```cpp

#include <vector>

using namespace std; 

int findSmallest(vector <int> list)
{
   // Your Code is Here ... Hope you Enjoy 
  return 1 ;
}

```


## Solution

<details>
	<summary> Click Here </summary>

```cpp
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 


int findSmallest(vector <int> list){

    int smallest = *min_element(list.begin(), list.end());
    return smallest;
    
}

```

</details>
