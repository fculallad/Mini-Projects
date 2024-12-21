# Problem

Given an array of integers your solution should find the smallest integer.

```
Given [34, 15, 88, 2] your solution will return 2
Given [34, -345, -1, 100] your solution will return -345
```
You can assume, for the purpose of this kata, that the supplied array will not be empty.

# Solution


<details> 
	<summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int findSmallest(vector <int> list){
    
    int min = *min_element(list.begin(), list.end());
    return min;
}

```

</details>