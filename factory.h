/* 
 * File:   factory.h
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */

#ifndef FACTORY_H
#define	FACTORY_H
#include <string>
#include<fstream>
#include<iostream>
#include <utility>
#include <vector>
#include "student.h"
#include "employee.h"

using namespace std;

class AbstractDBFactory {
protected:
     AbstractDBFactory(){} 
public:
     virtual void buildDB()=0;
     virtual void swap (int i, int j)=0;
     virtual bool less(int i, int j)=0;
     virtual void print()=0;
     virtual int getSize()=0;
     virtual ~AbstractDBFactory(){}
};

class StudentDBFactory:public AbstractDBFactory {

private:
     vector<Student * > m_studentInfo; 
     string m_studentInput;    
public:
     StudentDBFactory(string studentInput);
     virtual void buildDB();
     virtual void print();
     virtual void swap (int i, int j);
     virtual bool less(int i, int j);
     virtual int getSize();
     ~StudentDBFactory();
};

class EmployeeDBFactory:public AbstractDBFactory {
private:
     vector<Employee*> m_employeeInfo;
     string m_employeeInput;
public:
     EmployeeDBFactory(string employeeInput);
     virtual void buildDB();
     virtual void print();
     virtual void swap (int i, int j);
     virtual bool less(int i, int j);
     virtual int getSize();
     ~EmployeeDBFactory();
};
#endif

