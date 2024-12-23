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

</details>

