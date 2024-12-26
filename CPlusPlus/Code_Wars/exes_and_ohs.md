# Problem

Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.


```

Example Input / Output :

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false

```

## Template

```cpp

bool XO(const std::string& str)
{
  // your code here
  return true;
}

```


## Solution

<details>
	<summary> Click Here </summary>

```cpp

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool XO(const string& str){

    string x{};
    string o{};

    for (char c : str){
        if(tolower(c) == 'x'){
            x += c;
            continue;
        }

        if(tolower(c) == 'o'){
            o += c;
            continue;
        }
    }

    if(x.length() == o.length()){
      return true;
    }

    
    return false;
}

```cpp

</details>