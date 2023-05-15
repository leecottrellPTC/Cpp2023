#ifndef PERSON_H
#define PERSON_H

#pragma once
#include <string>
using namespace std;

class Person
{
public:
    Person();
    ~Person();
    Person(string fName, string lname, string username);
    Person(string fName, string lName); //use buildUsername
    
    string to_string();
    void setFname(string fName);
    void setLname(string lName);
    void setUsername(string userName);

    string getFname();
    string getLname();
    string getUsername();

    //functionality
    void buildUserName();

protected:
    string fname;
    string lname;
    string username;

};

#endif