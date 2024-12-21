# Problem

Complete the solution so that it reverses the string passed into it.

```cpp

#include <string>
using namespace std ; 

string reverseString (string str )
{
  // your Code is Here ... enjoy !!!
  return 1 ;
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

string reverseString (string str){

    //Using a Loop
    string reverse{};
    
    for(int i = *str.end(); i >= 0; i--){
        reverse += str[i];
    }
    return reverse;

    //Using std::string()
    return string(str.rbegin(), str.rend());

    //Using std::reverse()
    reverse(str.begin(), str.end());
    return str;
}

```

</details>