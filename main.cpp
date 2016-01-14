/* 
 * File:   main.cpp
 * Author: sunangel liunan Nan Liu Angie Sun
 *
 * Created on February 2, 2014, 11:28 AM
 */
#include "factory.h"
#include "student.h"
#include "BubbleSort.h"
using namespace std;

/*
 *questions: do we have to make employees separate like faculty and stuff, and can we put it in student.h or need employee.h, also how do we acces student's information if all private except for print  
 */
int main(int argc, char** argv) {
    	string studentInput= argv[1];
	//Error handling
	if (argc != 3){
		cout <<"Usage: <program_name> <input1> <input2>"<<endl;
		return 0;
	}
	ifstream studentFile(studentInput.c_str());
	if (!studentFile.is_open()){
		cout<<"Error: Error Opening Student File"<<endl;
		return 0;
	}
	else{
		studentFile.close();
	}
	
	string employeeInput= argv[2];
	ifstream employeeFile(employeeInput.c_str());
        if (!employeeFile.is_open()){
                cout<<"Error: Error Opening Employee File"<<endl;
                return 0;
        }
        else{
                employeeFile.close();
        }

    	AbstractDBFactory * studentDF = new StudentDBFactory(studentInput);
    	AbstractDBFactory *employeeDF = new EmployeeDBFactory(employeeInput);
	studentDF->buildDB();
	employeeDF->buildDB();    
	BubbleSort* studentBS = new BubbleSort();
    	studentBS->Sort(*studentDF);
    	BubbleSort* employeeBS = new BubbleSort();
    	employeeBS->Sort(*employeeDF);
    	cout <<"The list of students are : " << endl;
    	studentDF->print();
    	cout << "The list of employees are : " << endl;
    	employeeDF->print();
        
	//clean memory
	delete studentDF;
	delete employeeDF;
	delete studentBS;
	delete employeeBS;    
    	return 0;
}

