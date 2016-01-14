/* 
 * File:   factory.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
#include "factory.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
using namespace std;

/*
StudentDBFactory constructor
*/

StudentDBFactory::StudentDBFactory(string studentInput){
	StudentDBFactory::m_studentInput = studentInput;
}

//constructs a DB from the file with all the given information
void StudentDBFactory::buildDB(){
	string line;
	ifstream file (m_studentInput.c_str());
        //gets each line of file 
	while (getline (file,line)){
		//breaks file down by spaces into words
		istringstream iss(line);
		string word;
		int year;
		int id;
		string major;
		float GPA;
		string minor;
		string stutype;
		string name;
		for (int i=0; i<7 && line.length()>1; i++){
			iss >> word;
			switch(i){
			case 0:
				stutype=word;
				break;
			case 1:
				stringstream(word) >> id;
				break;
			case 2:
				name=word;
				break;
			case 3:
				stringstream(word) >> year;
				break;
			case 4:
				stringstream(word) >> GPA;
				break;
			case 5:
				major=word;
				break;
			case 6:
				minor=word;
				break;
			}
		}
		if (line.length()>1){
                 //adds the correct student to the vector
			if (stutype=="U"){
				m_studentInfo.push_back(new UndergradStudent(id, name, year, GPA, major, minor));
               		}
			if (stutype=="G"){
				m_studentInfo.push_back(new GraduateStudent(id, name, year, GPA, major, minor));
			}
		}
	
	}
	file.close();
}

//clean memory
StudentDBFactory::~StudentDBFactory(){
	for (unsigned int i =0; i< m_studentInfo.size(); i++){
                delete m_studentInfo[i];
        }
	m_studentInfo.clear();
//	cout << "studentInfo been cleaned"<<endl;
}

//prints the values of all students in the dbfactory
void StudentDBFactory::print(){
	for (unsigned int i =0; i< m_studentInfo.size(); i++){
		m_studentInfo[i]->print();
	}
}

int StudentDBFactory::getSize(){
	return m_studentInfo.size();
}

//swaps the elements at indexes i and j
void StudentDBFactory::swap(int i, int j){
	Student* tmp = m_studentInfo[i];
	m_studentInfo[i] = m_studentInfo[j];
	m_studentInfo[j]=tmp;
}

//returns true if i greater than j
bool StudentDBFactory::less(int i, int j){
    	Student* stu1 = m_studentInfo[i];
    	Student* stu2 = m_studentInfo[j];
    	float grade1=stu1->getGrade();
    	float grade2=stu2->getGrade();
   	 //first compares grades
   	 if (grade1<grade2){
    		return true;
   	 }
   	 if (grade1>grade2){
        	return false;
   	 }
   	 //if grades are same, compares names 
   	 else {
        	string name1=stu1->getName();
        	string name2=stu2->getName();
        	if (name1>name2){
            		return true;
       		}
        	else {
            		return false;
       		}
   	 }
}

//constructs employee db factory from file, uses same procedure as student constructor, but constructs different objects
EmployeeDBFactory::EmployeeDBFactory(string employeeInput){
	EmployeeDBFactory::m_employeeInput=employeeInput;
}

void EmployeeDBFactory::buildDB(){
  	string line;
      	ifstream file (m_employeeInput.c_str());
        while (getline (file,line)){
              	istringstream iss(line);
              	string word;
              	int year;
              	int id;
              	int salary;
              	string emplotype, dept;
		int stuNum;
              	string name;
              	for (int i=0; i<6 && line.length()>1; i++){
                	iss >> word;
                 	switch (i){
			case 0:
                      		emplotype=word;
                 		break;
                  	case 1:
                     		stringstream(word) >> id;
                 		break;
                  	case 2:
                     		name=word;
                 		break;
                 	case 3:
                      		stringstream(word) >> year;
				break;
                  	case 4:
                     		stringstream(word) >> salary;
                  		break;
                  	case 5:
                     		dept=word;
				stringstream(word) >> stuNum;
                 		break;
              		}
		}
              	if (line.length()>1){
			if (emplotype =="F"){
              			m_employeeInfo.push_back(new FacultyEmployee(id, name, year, salary, stuNum));
          		}
			if (emplotype =="S"){
                       		m_employeeInfo.push_back(new StaffEmployee(id, name, year, salary, dept));
                       	}
		}
	}
     	file.close();
}

//clean memory
EmployeeDBFactory::~EmployeeDBFactory(){
        for (unsigned int i =0; i< m_employeeInfo.size(); i++){
                delete m_employeeInfo[i];
        }
	m_employeeInfo.clear();
//	cout<<"m_employeeInfo been cleaned."<<endl; 
}

void EmployeeDBFactory::print(){
	for (unsigned int i =0; i< m_employeeInfo.size(); i++){
        	m_employeeInfo[i]->print();
    	}
}

int EmployeeDBFactory::getSize(){
	return m_employeeInfo.size();
}

void EmployeeDBFactory::swap(int i, int j){
    	Employee* tmp = m_employeeInfo[i];
    	m_employeeInfo[i] = m_employeeInfo[j];
    	m_employeeInfo[j]=tmp;
}

//returns true if employee at index i greater than j
bool EmployeeDBFactory::less(int i, int j){
    
    	Employee * emp1 = m_employeeInfo[i];
    	Employee * emp2 = m_employeeInfo[j];
    	int sal1 = emp1->getSalary();
    	int sal2 = emp2->getSalary();
    	int year1 = emp1->getYear();
    	int year2 = emp2->getYear();
    	if (sal1>sal2){
    		return true;
   	}
    	else if (sal1<sal2){
        	return false;
    	}
    	else {
        	if (year1>year2){
            		return true;
        	}
        	else{
            		return false;
        	}
    	}
}

