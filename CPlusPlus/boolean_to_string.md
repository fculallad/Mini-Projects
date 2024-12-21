# Problem

Complete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false.

# Solution


<details>
	<summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string bool_to_word(bool value){

    if(value == 0){
        return "No";
    }
    else{
        return "Yes";
    }

}

```
</details>