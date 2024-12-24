# Problem

Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.


```

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.

```

## Template

```cpp

#include <vector>

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
    return 0;
}

```


## Solution

<details>
	<summary> Click Here </summary>

```cpp
#include <vector>
#include <algorithm>

using namespace std;

long sumTwoSmallestNumbers(vector<int> numbers){

    nth_element(numbers.begin(), numbers.begin() + 1, numbers.end());
    return numbers[0] + numbers[1];
  
}
```cpp

</details>