# Problem

Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.



# Solution


<details>
	<summary> Click Here </summary>

```cpp

#include <string>

using namespace std;

string even_or_odd(int number) 
{
  if(number % 2 == 0){
      return "Even";
  }else{
      return "Odd";
  }
}

```
</details>