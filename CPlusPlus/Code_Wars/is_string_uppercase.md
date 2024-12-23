# Problem

Create a method to see whether the string is ALL CAPS.


## Solution

<details>
	<Summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

bool is_uppercase(const string &s) {

  //Checks for alphabetical letters & uppercase 
    for(char c : s){
        if (!isupper(c) && isalpha(c)){
            return false;
        }
    }
    
  return true; 
}

```

</details>