#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Employee {
protected:
    string code;
    string ssn;
    string first;
    string last;
    string department;
    string   role;
    double   salary;
    

public:

    Employee();
    Employee(vector<string>&);
    //Employee(const Employee&); optional
    ~Employee();
    //Employee& operator=(const Employee&); optional

    string getName() const;
    void   setName(string, string);

    string getSSN() const;
    void   setSSN(string);

    string getDept() const;
    void   setDept(string);

    string getEmpCode() const;
    void   setEmpCode(string);

    string   getRole() const;
    void     setRole(string);

    double   getSalary() const;
    void     setSalary(double);
    //operator< should work based on ssn
    bool    operator<(const Employee&);
    //operator<< is to print info of an employee.
    friend  ostream& operator<<(ostream&, const Employee&);
};
#endif

