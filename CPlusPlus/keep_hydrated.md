# Problem

https://www.codewars.com/kata/582cb0224e56e068d800003c/train/cpp

Nathan loves cycling.

Because Nathan knows it is important to stay hydrated, he drinks 0.5 litres of water per hour of cycling.

You get given the time in hours and you need to return the number of litres Nathan will drink, rounded to the smallest value.

```
For example:

time = 3 ----> litres = 1

time = 6.7---> litres = 3

time = 11.8--> litres = 5

```

```
2 -> 3 (1 + 2)
8 -> 36 (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8)
```


## Solution

<details>
	<Summary> Click Here </summary>

```cpp


#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;

int litres(double time) {

  return static_cast<int>(time * 0.5);
    
}

</details>