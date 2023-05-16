#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once
#include "Person.h"
#include <vector>

class Employee: public Person
{
public:
    Employee();
    Employee(string fname, string lname, string title, double sal);
    Employee(string fname, string lname, 
        string title, double sal, vector<string> list);
    Employee(Person peep, string title, double sal);
    ~Employee();
    string to_string();
    inline void setJobTitle(string title){
        jobTitle = title;
    }
    inline void setSalary(double sal){
        salary = sal;
    }
    inline string getJobTitle(){
        return jobTitle;
    }
    inline double getSalary(){
        return salary;
    }

    inline void setSkills(vector<string> list){
        skills = list;
    }

protected:
    string jobTitle;
    double salary;
    vector<string> skills;


};

#endif