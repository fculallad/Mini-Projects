# Problem

Complete the square sum function so that it squares each number passed into it and then sums the results together.


## Solution

<details>
	<Summary> Click Here </summary>

```cpp


int square_sum(const vector<int>& numbers) {

    int sum = 0;
    
    for (int num : numbers) {
        sum += num * num;
    }
    
    return sum;
}

</details>