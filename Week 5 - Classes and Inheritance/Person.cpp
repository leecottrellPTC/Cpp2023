#include "Person.h"

Person::Person()
{
    //default cosntructor
}
Person::~Person()
{
    //destructor
    //called when variable goes out of scope
    //cout << "Killing " << fname << endl;
}

Person::Person(string fName, string lname, string username){
    this->lname =lname;
    fname = fName;
    this->username = username;
}

Person::Person(string fName, string lName){
    this->lname =lName;
    fname = fName;
    buildUserName();
}

string Person::to_string(){
    return fname + " " + lname + " username= " + username;
}

void Person::setFname(string fName)
{
    fname = fName;
}

void Person::setLname(string lName)
{
    lname = lName;
}

void Person::setUsername(string userName)
{
    username = userName;
}

string Person::getFname()
{
    return fname;
}

string Person::getLname()
{
    return lname;
}

string Person::getUsername()
{
    return username;
}

void Person::buildUserName(){
    username = fname.at(0) + lname;
}
