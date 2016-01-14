/* 
 * File:   student.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
//Group Members: Nan Liu  liunan; Angela Sun sunangel
#include<iostream>
#include<vector>
using namespace std;

#include "student.h"

/*
Student Constructor
*/

Student::Student(int StudentID, string Name, int Year, float Grade)
{
        Student::m_StudentID=StudentID;
        Student::m_Name=Name;
        Student::m_Year=Year;
        Student::m_Grade=Grade;
}

void Student::print() const
{
        cout<<m_StudentID<<" "<<m_Name<<" "<<m_Year<<" "<<m_Grade;
}


float Student::getGrade(){
	return m_Grade;
}


string Student::getName()
{
	return m_Name;
}


/* 
derived class for undergrad students 
*/
UndergradStudent :: UndergradStudent(int StudentID, string Name, int Year, float Grade, string Major, string Minor):Student(StudentID, Name, Year, Grade){
	UndergradStudent::m_Major = Major;
	UndergradStudent::m_Minor = Minor;
}


void UndergradStudent :: print() const {
	Student :: print();
	cout <<" "<< m_Major <<" "<< m_Minor << endl;

}

/* 
derived class for grad students
*/
GraduateStudent :: GraduateStudent(int StudentID, string Name, int Year, float Grade, string Dept, string Advisor):Student(StudentID, Name, Year, Grade){
        GraduateStudent::m_Dept = Dept;
        GraduateStudent::m_Advisor = Advisor;
}

void GraduateStudent :: print() const {
	Student :: print();
	cout <<" "<< m_Dept <<" "<< m_Advisor << endl;
}
