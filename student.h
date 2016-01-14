/* 
 * File:student.h   
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;

class Student {
private:
	string m_Name;
	int    m_StudentID, m_Year;
	float  m_Grade;
	
public: 
	Student(int StudentID, string Name, int Year, float Grade);
	virtual void print() const;
	virtual float getGrade();
	virtual string getName();
	virtual ~Student(){}
}; 


class UndergradStudent : public Student
{
private:
	// student major and minor department
	string m_Major;
	string m_Minor;
public:
	UndergradStudent(int StudentID, string Name, int Year, float Grade, string Major, string Minor);
	void print() const;
};

/* 
derived class for grad students
*/
class GraduateStudent : public Student
{
private:
	string m_Dept;
	string m_Advisor;
public:
	GraduateStudent(int m_StudentID, string Name, int Year, float Grade, string Dept, string Advisor);
	void print() const;
};
#endif
