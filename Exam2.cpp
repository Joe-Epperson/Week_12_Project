// Joe Epperson, IV
// jee4cf@umsystem.edu
// 4/12/2021
// CS201L Lab 12

#include "Employee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void main()
{
	//Declaring vector of employees, input/output files, and user input
	vector<Employee> employees;
	ifstream fileInput;
	ofstream fileOutput;
	string usrChoice;

	// Opening the input file
	fileInput.open("input.txt");
	while (fileInput.good())
	{
		fileInput >> usrChoice;
		if (usrChoice == "NEW")
		{
			// Declaring temporary variables for storage in the employee info
			int idNum;
			string employeeFirst;
			string employeeLast;
			string employeeName;

			// Storing the data from the input file into the temporary variables for later assignment
			fileInput >> idNum >> employeeFirst >> employeeLast;
			employeeName = employeeFirst + " " + employeeLast;

			// Creating the new employee and storing it with all other employees
			Employee newEmployee(idNum, employeeName);
			employees.push_back(newEmployee);

		}
		else if (usrChoice == "RAISE")
		{
			// Declaring temporary variables for storage in the employee info
			int idNum;
			double raiseVal;

			// Storing the data from the input file into the temporary variables for later assignment
			fileInput >> idNum >> raiseVal;

			// Finding the correct employee for the raise
			for (int i = 0; i < employees.size(); ++i)
			{
				if (idNum == (employees.at(i).getEmployeeID()))
				{
					employees.at(i).giveRaise(raiseVal);
					break;
				}
			}

		}
		else if (usrChoice == "PAY")
		{
			// Cycling through all employees and paying all of them
			for (int i = 0; i < (employees.size()); ++i)
			{
				// Only paying those employees who still work there
				if (employees.at(i).isEmployed())
				{
					employees.at(i).pay();
				}
			}
		}
		else if (usrChoice == "FIRE")
		{
			// Declaring temporary variables for storage in the employee info
			int idNum;

			// Storing the data from the input file into the temporary variables for later assignment
			fileInput >> idNum;

			// Finding the correct employee for the raise
			for (int i = 0; i < employees.size(); ++i)
			{
				if (idNum == (employees.at(i).getEmployeeID()))
				{
					// Firing the correct employee
					employees.at(i).fire();
					break;
				}
			}

		}
	}
	// Closing input file
	fileInput.close();

	// Opening the output file
	fileOutput.open("output.txt");

	// Cycling through all employees for output into output file
	for (int i = 0; i < (employees.size()); ++i)
	{
		// Outputting the basic name and id to the output file for each employee
		fileOutput << employees.at(i).getName() << ", ID Number " << employees.at(i).getEmployeeID() << ":" << endl;
		
		//Checking if the employee is currently employed
		if (employees.at(i).isEmployed())
		{
			// Outputting information for currently employed people
			fileOutput << "Current pay rate: $" << employees.at(i).getPayRate() << endl;
			fileOutput << "Pay earned to date: $" << employees.at(i).getBalance() << endl;
		}
		else
		{
			// Outputting information for unemployed people
			fileOutput << "Not employed with the company." << endl;
			fileOutput << "Pay earned to date: $" << employees.at(i).getBalance() << endl;
		}
		fileOutput << endl;
	}

	// Opening the output file
	fileOutput.close();
}