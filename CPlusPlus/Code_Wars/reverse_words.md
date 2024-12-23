# Problem

Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

```

"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"

```

## Template

```cpp

#include <string>

std::string reverse_words(std::string str)
{
  return "";
}

```



## Solution

<details>
	<summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

<details>
	<summary> Click Here </summary>

string reverse_words(string &str){

  string output{}, word{};

  for (char c : str){

    if( c == ' '){
      output += word;
      output += c;
      word = "";
      continue;
    }
    
    word = c + word;

  }

  output += word;
  return output;

}

```

```
This solution is efficient with both time (O(n) where n is string length)
and memory(it only uses extra space for the output string and one word at a time).
It also handles all edge cases naturally:

- Empty strings (loop never runs, returns empty string)
- Multiple spaces (each space is added to output immediately)
- Leading/trailing spaces (treated just like any other spaces)

```

</details>


