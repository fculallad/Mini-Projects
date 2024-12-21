# Problem

Write a function that accepts an integer n and a string s as parameters, and returns a string of s repeated exactly n times.

```
6, "I"     -> "IIIIII"
5, "Hello" -> "HelloHelloHelloHelloHello"
```


## Solution

<details>
	<Summary> Click Here </summary>

```cpp


#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string repeat_str(size_t repeat, const string &str) {

    string result{};
    
    for(int i = 0; i < repeat; i++){
        result += str;
    }
    
    return result;
}

</details>