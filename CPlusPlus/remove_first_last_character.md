# Problem 

Create a function that removes the first and last characters of a string. You're given one parameter, the original string. You don't have to worry about strings with less than two characters.

# Solution

<details> 
	<summary> Click Here </summary>

```cpp

#include <string>
using namespace std; 

string sliceString (string str ){
  return str.substr(1, str.size() - 2); 
}

```
</details>