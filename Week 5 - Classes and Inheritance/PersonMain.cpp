#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Person.cpp"

using namespace std;

int main(){
    //parameterized constuctor call
    Person student("Kate", "Upton", "kupton");
    //default
    Person anotherStudent("Justin", "Timberlake");
   // anotherStudent.setFname("Joe");
   // anotherStudent.setLname("Smith");
   // anotherStudent.setUsername("joesmith");
    cout << student.to_string() << endl;
    cout << anotherStudent.to_string() << endl;

    //student.fn
}

