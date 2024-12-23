# Problem 

https://www.codewars.com/kata/576bb71bbbcf0951d5000044/train/cpp

Given an array of integers.

Return an array, where the first element is the count of positives numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.

If the input is an empty array or is null, return an empty array.

### Example
```
For input :

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].

```

<details>
	<summary> Click Here </summary>

 ## Solution 1

```cpp

#include <vector>
#include <string>
using namespace std;

vector<int> countPositivesSumNegatives(vector<int> input)
{
    vector<int> ret{};
    int positiveNumbers{};
    int sum{};
    

    if (input.empty()) {  
        return {};   
    }
    
    for(int n : input) {
        if (n > 0) {
            positiveNumbers++;
        }
        if(n < 0) {
            sum += n;
        }
    }
    

    return {positiveNumbers, sum};
}


```

## Solution 2 : Better


```cpp

#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if(input.empty())
      return {};
    int countPositives {0}, sumNegatives {0};
    for(int x: input)
      x>0 ? countPositives++ : (x!=0 ? sumNegatives+=x : 0);
    return {countPositives, sumNegatives};

// You can remove second if statement too since adding 0 to negative 
// numbers won't affect the sum.


}

```

</details>
