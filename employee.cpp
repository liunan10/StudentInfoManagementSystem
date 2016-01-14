/* 
 * File:   employee.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
//Group Members: Nan Liu  liunan; Angela Sun sunangel
#include<iostream>
#include<vector>
using namespace std;

#include "employee.h"

/* 
constructor of Employee
*/
Employee::Employee(int ID, string Name, int Year, int Salary)
{
        Employee::m_ID=ID;
        Employee::m_Name=Name;
        Employee::m_Year=Year;
        Employee::m_Salary=Salary;
}

int Employee::getSalary(){
    return m_Salary;
}

int Employee::getYear(){
         return m_Year;
}

void Employee::print() const
{
        cout<<m_ID<<" " <<m_Name<<" "<<m_Year<<" "<<m_Salary;
}

/* 
constructor for Faculty 
*/
FacultyEmployee :: FacultyEmployee(int ID, string Name, int Year, int Salary, int StuNum):Employee(ID, Name, Year, Salary){
	FacultyEmployee::m_StuNum = StuNum; 
}

void FacultyEmployee :: print() const {
	Employee :: print();
	cout << " " << m_StuNum << endl;

}

/* 
constructor for Staff             
*/
StaffEmployee :: StaffEmployee(int ID, string Name, int Year, int Salary,string Dept):Employee(ID, Name, Year, Salary){
	StaffEmployee :: m_Dept = Dept;
}

void StaffEmployee :: print() const {
	Employee :: print();
	cout << " " << m_Dept << endl;
}
