#include <iostream>
#include <vector>
#include <iomanip>
#include <array>
#include <chrono>
#include <thread>

using namespace std;

/*
    Student Grade Calculator

    - Accept Input for Student Name, ID, and grades in three subjects
    - Calculate the avg grade for each student
    - generate a formatted report showing results
*/

class InputHandler
{
    public : 
        static void trim(string& input)
        {
            input.erase(0, input.find_first_not_of(" \t\n\r"));
            input.erase(input.find_last_not_of(" \t\n\r") + 1);
        }

        inline static string getInput()
        {
            while(1)
            {
                string input{};
                getline(cin, input);
        
                if(input.empty())
                {
                    cerr << "Empty Input. Try Again : ";
                    continue;
                }

                if(input.length() > 20)
                {
                    cerr << "Name is too long. Try Again.\nEnter Name (Max : 20 Characters) : ";
                    continue;
                }
                
                trim(input);
                
        
                return input;
            }
}

        inline static int getstudentID()
        {
            while(1)
            {
                try
                {
                    int number = stoi(getInput());  

                    if(number > 99999)
                    {
                        cerr << "Invalid Student ID. Try Again.\nEnter Valid Student ID (6 Digits) : ";
                        continue;
                    }
                    
                    return number;
                }
                catch(invalid_argument)
                {
                    cerr << "Invalid Numeric Input. Try Again\nEnter Input : ";
                    continue;
                }
                
            }
        }

        inline static char getSubjectGrades()
        {
            while(1)
            {
                array<char, 5> validLetterGrades = {'A','B','C','D','F'};
                
                string input = getInput();

                char letterGrade = toupper(input[0]);
    
                for(char c : validLetterGrades)
                {
                    if(letterGrade == c)
                    {
                        return c;
                    }
                }
    
                cerr << "Invalid Letter Grade. Try Again.\nEnter Grade (A-F) : ";
                continue;
            }
            
        }

        inline static double getGPA()
        {
            while(1)
            {
                try
                {
                    double GPA = stod(getInput());

                    if(GPA > 4.0)
                    {
                        cerr << "Invalid GPA Input. Try Again.\nEnter GPA (0 - 4.0)";
                        continue;
                    }
                    return GPA;
                }
                catch(invalid_argument)
                {
                    cerr << "Invalid Numeric Input. Try Again.\nEnter GPA (0 - 4.0)";
                    continue;
                }
                
            }
            
        }
};

struct Student
{
    string studentName{};
    int studentID{};
    array<char, 3> subjectGrades{};
    string combinedSubjectGrades{};
    double studentGPA{};
};

void calculateGPA(array<Student, 3>& totalStudents)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            switch(totalStudents[i].subjectGrades[j])
            {
                case 'A' : totalStudents[i].studentGPA += 4.0; break;
                case 'B' : totalStudents[i].studentGPA += 3.0; break;
                case 'C' : totalStudents[i].studentGPA += 2.0; break;
                case 'D' : totalStudents[i].studentGPA += 1.0; break;
                case 'F' : totalStudents[i].studentGPA += 0.0; break;
            }
        }
    } 


    for(int i = 0; i < 3; i++)
    {
        totalStudents[i].studentGPA = ( totalStudents[i].studentGPA / 3 );
    }
}

void printHeaderRow()
{
    cout << setw(20) << left << "Name";
    cout << setw(10) << "ID";
    cout << setw(10) << "Grades";
    cout << setw(10) << "GPA";

    cout<< "\n-------------------------------------------\n";
}

void PrintTableItems(const array<Student, 3>& totalStudents)
{
    for(int i = 0; i < 3; i++)
    {
        cout << setw(20) << left << totalStudents[i].studentName;
        cout << setw(10) << totalStudents[i].studentID;
        cout << setw(10) << totalStudents[i].combinedSubjectGrades;
        cout << setw(10) << totalStudents[i].studentGPA;
        cout << '\n';
    }
}

void showLoadingBar()
{
    cout << "Loading Table ";
    for(int i = 0; i < 25; i++)
    {
        cout << "█";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));   
    }
}

int main()
{
    Student studentOne{};
    Student studentTwo{};
    Student studentThree{};

    array<Student,3> totalStudents{studentOne, studentTwo, studentThree};
    array<string, 3> courseSubjects{"Math", "English", "Computer Science"};

    cout << fixed << setprecision(1);    

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter Student " << i + 1<< "'s Name : ";
        totalStudents[i].studentName = InputHandler::getInput();
        
        cout << "Enter Student " << i + 1 << "'s' Student ID : ";
        totalStudents[i].studentID = InputHandler::getstudentID();
    } 

    cout << "\033[2J\033[1;1H";

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter " << totalStudents[i].studentName << "'s Grade for " << courseSubjects[0] << " : ";
        totalStudents[i].subjectGrades[0] = InputHandler::getSubjectGrades();
    
        cout << "Enter " << totalStudents[i].studentName << "'s Grade for " << courseSubjects[1] << " : ";
        totalStudents[i].subjectGrades[1] = InputHandler::getSubjectGrades();
    
        cout << "Enter " << totalStudents[i].studentName << "'s Grade for " << courseSubjects[2] << " : ";
        totalStudents[i].subjectGrades[2] = InputHandler::getSubjectGrades();
    
        for(int j = 0; j < 3; j++)
        {
            totalStudents[i].combinedSubjectGrades += totalStudents[i].subjectGrades[j];
    
            if(j < 2)
            {
                    totalStudents[i].combinedSubjectGrades += ",";
            }
        }
    }

    cout << "\033[2J\033[1;1H";
    
    calculateGPA(totalStudents);

    showLoadingBar();
    cout << "\033[2J\033[1;1H";
    
    printHeaderRow();
    PrintTableItems(totalStudents);

    return 0;
}