# Problem 

Create a function that removes the first and last characters of a string. You're given one parameter, the original string. You don't have to worry about strings with less than two characters.

## Template

```cpp

#include <string>

using namespace std; 

string sliceString (string str )
{
  // your code is here ... Hope You Enjoy !!
  return 1 ; 
}

```

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
