/* 
 * File:   employee.h
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using std::string;

class Employee
{
private:
	string m_Name;
	int  m_ID, m_Year, m_Salary;
public: 
	Employee(int ID, string Name, int Year, int Salary);
	virtual void print() const;
	virtual int getSalary();
	virtual int getYear();
	virtual ~Employee(){}
}; 

/* 
derived class for faculty
*/
class FacultyEmployee : public Employee
{
private:
	// number of students supervised 
	int m_StuNum;
public:
	FacultyEmployee(int ID, string Name, int Year, int Salary, int StuNum);
	void print() const;
};

/* 
derived class for staff
*/
class StaffEmployee : public Employee
{
private:
	string m_Dept;
public:
	StaffEmployee(int ID, string Name, int Year, int Salary,string Dept);
	void print() const;
};
#endif
