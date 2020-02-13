// compile: g++ -std=c++11 -o pointers pointers.cpp
// Bernadette Dehnert
// https://github.com/bmcecilia3/OSAssignment1
#include <iostream>
#include <string>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    int flag = 0;
	student.f_name = (char *)malloc(sizeof(char) * 128);
	student.l_name = (char *)malloc(sizeof(char) * 128);
    // Sequence of user input -> store in fields of `student`
    while(flag == 0)
    {
    	char idTry[9];
    	printf("Please enter the student's id number: ");
    	std::cin >> idTry;
    	if(string(to_string(atoi(idTry))).length() < string(idTry).length() || idTry == NULL || !isdigit(idTry[0]))
    	{
    		printf("Sorry, I cannot understand your answer\n");
    	}
    	else{
    		student.id = atoi(idTry);
    		flag = 1;
    	}
    }
    flag = 0;
    while(flag == 0)
    {
    	char first[128];
    	printf("Please enter the student's first name: ");
    	std::cin >> first;
    	if(first == NULL)
    	{
    		printf("Sorry, I cannot understand your answer\n");
    	}
    	else{
    		student.f_name = first;
    		flag = 1;
    	}
    }
    flag = 0;
    while(flag == 0)
    {
    	char last[128];
    	printf("Please enter the student's last name: ");
    	std::cin >> last;
    	if(last == NULL)
    	{
    		printf("Sorry, I cannot understand your answer\n");
    	}
    	else{
    		student.l_name = last;
    		flag = 1;
    	}
    }
    flag = 0;
    while(flag == 0)
    {
    	char assignment[10];
    	printf("Please enter how many assignments were graded: ");
    	std::cin >> assignment;
    	if(string(to_string(atoi(assignment))).length() < string(assignment).length() || assignment == NULL || !isdigit(assignment[0]))
    	{
    		printf("Sorry, I cannot understand your answer\n");
    	}
    	else{
    		student.n_assignments = atoi(assignment);
    		flag = 1;
    	}
    }
    int i;
    printf("\n");
    double allGrades[student.n_assignments];
    for(i = 0; i < student.n_assignments; i++)
    {
    	flag = 0;
    	while(flag == 0)
   		{
    		char grade[10];
    		printf("Please enter grade for assignment %d: ", i);
    		std::cin >> grade;    		
    		if(string(grade).find(".") == std::string::npos)
    		{
    			if(string(to_string(atoi(grade))).length() < string(grade).length() || grade == NULL || !isdigit(grade[0]))
    			{
    				printf("Sorry, I cannot understand your answer\n");
    			}
    			else{
    				allGrades[i] = atof(grade);
    				flag = 1;
    			}
    		}
    		else{
    			string g = string(grade);
    			size_t dot = g.find(".");
    			string after = g.substr(dot + 1);
    			string before = g.substr(0, dot);
    			if(string(to_string(atoi(before.c_str()))).length() < string(before.c_str()).length() || before.c_str() == NULL || !isdigit(before.c_str()[0]))
    			{
    				printf("Sorry, I cannot understand your answer\n");
    			}
    			else if(string(to_string(atoi(after.c_str()))).length() < string(after.c_str()).length() || after.c_str() == NULL || !isdigit(after.c_str()[0]))
    			{
    				printf("Sorry, I cannot understand your answer\n");
    			}
    			else{
    				allGrades[i] = atof(grade);
    				flag = 1;
    			}
    		}
    	}
    }

    // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, allGrades);
    // Output `average`
    printf("\n");
    printf("Student: %s %s [%d]\n\tAverage grade: %f\n", student.f_name, student.l_name, student.id, allGrades[0]);
    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    int i;
    double sum = 0;
    Student student = *(Student*)(object);
    for(i = 0; i < student.n_assignments; i++)
    {
    	sum = sum + avg[i];
    } 
    avg[0] = (sum / ((Student*)object)->n_assignments);
}
