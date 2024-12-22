# Problem

https://www.codewars.com/kata/57eae65a4321032ce000002d/cpp

Given a string of digits, you should replace any digit below 5 with '0' and any digit 5 and above with '1'. Return the resulting string.

Note: input will never be an empty string

# Solution


<details>
	<summary> Click Here </summary>

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

#include <string>

string fakeBin(string str){

      string ret{};
  
    for (char c : str){
      if (c - '0' >= 5 ){
        
        ret += '1';
        
      }else{
        
        ret += '0';
        
      }
    }
  
      return ret;

  }
      

```
</details>