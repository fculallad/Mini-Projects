#CGPA Calculator

### C++

```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

#define CREDIT_HOURS 3

void numCourses(int &coursesTaken){

    cout << "\nHow Many Courses? : \n";
    
    while (!(cin >> coursesTaken) || coursesTaken <= 0) {
        cout << "Please enter a valid positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
}
void initGrades(int &coursesTaken, vector<char> &letterGrades){

    cout<< "\nEnter grades from " << coursesTaken << " courses\n";
    
    char letterGrade{};
    
    for (int i = 0; i < coursesTaken; i++){

        bool validGrade{false};

        while(!validGrade){
            cout << "Course " << i + 1 << " : ";
            cin >> letterGrade;

            letterGrade = toupper(letterGrade);

            if(letterGrade == 'A' || letterGrade == 'B' ||
                letterGrade == 'C' || letterGrade == 'D' ||
                letterGrade == 'F'){
                validGrade = true;
            } else{cout << "\nInvalid Letter Grade " << 
                  ("Enter : A, B, C, D, F \n");
                  }

        }

        letterGrades.push_back(letterGrade);
    }
}
int gradePoints(vector<char> letterGrades){

    int gradePoints{0};
    
    for(char c : letterGrades){
        switch (c){

            case 'A' : gradePoints += 4; break;
            case 'B' : gradePoints += 3; break;
            case 'C' : gradePoints += 2; break;
            case 'D' : gradePoints += 1; break;
            case 'F' : gradePoints += 0; break;
            
        }
    }

    return gradePoints * CREDIT_HOURS;
    
}
int totalCredits(int coursesTaken){
    return coursesTaken * 3;
}
int CGPA(int totalCredits, int gradePoints){
    return gradePoints / totalCredits;
}


int main(){

    cout << " --- CGPA Calculator ---" << '\n';

    int coursesTaken{};
    vector<char> letterGrades{};
    
    numCourses(coursesTaken);
    initGrades(coursesTaken, letterGrades);
    

    cout << "\nGrade Summary : ";
    for (char c : letterGrades){
        cout << c << " ";
    }
    
    printf("\n");


    cout << "Total Credits: " << totalCredits(coursesTaken) << '\n';
    cout << "Total Grade Points: " << gradePoints(letterGrades)<< '\n';;
    cout << "CGPA: " << CGPA(totalCredits(coursesTaken), gradePoints(letterGrades));

return 0;    
}


```