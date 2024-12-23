# Description

Retrieves the sum & average of  a dynamic vector after prompting the for user input.

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> integerInputConversion(string &num, vector<int> &nums){

  stringstream ss(num);
  int numbers{};

  while(ss >> numbers){
    nums.push_back(numbers);
  }

  return nums;
}

double vectorAverage(vector<int> nums){

  double sum{};
  double result{};
  for(int n : nums){
    sum += n;
  }
  
  result = sum / nums.size();
  return result;
}

int vectorSum(vector<int> nums){

  int sum{};
  
  for(int n : nums){
    sum += n;
    }
  return sum;
}

void vectorString(vector<int> nums){

  cout << "Input Vector: " << "{ ";

  bool first = true;
  for(int n : nums){

    if(!first){
      cout << ", ";
    }

    cout << n;
    first = false;
  }
  cout << " }\n";
}


int main(){

  cout << "-- Vector Average Program --" << "\n\n";
  
  vector<int> nums{};
  cout << "Enter Values (Separate with a space): ";
  string line;
  getline(cin, line);

  double result = vectorAverage(integerInputConversion(line, nums));
  vectorString(nums);
  cout << "Vector Sum : " << vectorSum(nums) << '\n';

  if(result == floor(result)){
    cout << "Vector Average: " << static_cast<int>(result);
  }else{
      printf("%.1lf", result);
  }

  return 0;
}



```