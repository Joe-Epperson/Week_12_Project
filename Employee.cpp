// Joe Epperson, IV
// jee4cf@umsystem.edu
// 4/12/2021
// CS201L Lab 12

#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee()
{
	employeeID = 0;
	name = "";
	payRate = 10.00;
	balance = 0;
}

Employee::Employee(int id, string myName)
{
	employeeID = id;
	name = myName;
	payRate = 10.00;
	balance = 0;
}

int Employee::getEmployeeID()
{
	return employeeID;
}

double Employee::getPayRate()
{
	return payRate;
}

double Employee::getBalance()
{
	return balance;
}

string Employee::getName()
{
	return name;
}

void Employee::giveRaise(int rate)
{
	double rateDiff;
	rateDiff = payRate * (rate * 0.01);
	payRate += rateDiff;
}

void Employee::pay()
{
	balance += payRate;
}

void Employee::fire()
{
	payRate = 0;
	employed = false;
}

bool Employee::isEmployed()
{
	if (employed)
	{
		return true;
	}
	return false;
}
