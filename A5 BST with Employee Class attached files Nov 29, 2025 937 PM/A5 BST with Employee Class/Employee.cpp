#include <iostream>
#include <iomanip>
#include "Employee.h"

Employee::Employee()
{
    code = "";
    ssn = "";
    first = "";
    last = "";
    department = "";
    role = "";
    salary = -1;
}
Employee::Employee(vector<string> &fields)
{
    code = fields[0];
    ssn = fields[1];
    first = fields[2];
    last = fields[3];
    department = fields[4];
    role = fields[5];
    salary = stof(fields[6]);
}

Employee::~Employee()
{
}

string Employee::getEmpCode() const
{
    return code;
}

void Employee::setEmpCode(string newCode)
{
    code = newCode;
}

string Employee::getName() const
{
    return last + "," + first;
}

void Employee::setName(string first, string last)
{
    this->first = first;
    this->last = last;
}

string Employee::getSSN() const
{
    return ssn;
}

void Employee::setSSN(string ssn)
{
    this->ssn = ssn;
}

string Employee::getDept() const
{
    return department;
}

void Employee::setDept(string dept)
{
    this->department = dept;
}

string Employee::getRole() const
{
    return role;
}

void Employee::setRole(string role)
{
    this->role = role;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

bool Employee::operator<(const Employee &right)
{
    // You need to implement this part.
    return this->getSSN() < right.ssn;
}

Employee &Employee::operator=(const Employee &right)
{
    code = right.code;
    ssn = right.ssn;
    first = right.first;
    last = right.last;
    department = right.department;
    role = right.role;
    salary = right.salary;
}

Employee::Employee(const Employee& right)
{
    *this = right;
}

ostream &operator<<(ostream &out, const Employee &employee)
{
    // You need to implement this part.
    out << "Code: " << employee.code << endl
        << "SSN: " << employee.ssn << endl
        << "First Name: " << employee.first << endl
        << "Last Name: " << employee.last << endl
        << "Department: " << employee.department << endl
        << "Role: " << employee.role << endl
        << "Salary: " << employee.salary << endl;
}
