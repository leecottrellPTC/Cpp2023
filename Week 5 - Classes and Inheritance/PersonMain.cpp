#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include "Person.cpp"

using namespace std;
array <Person, 2> people;
void fillTheArray(){
    Person aPerson;
    string fname, lname;
    for(int x=0; x < people.size(); x++){
        //ask for elements of the class
        cout << "Enter first name ";
        cin >> fname;
        cout << "Enter last name ";
        cin >> lname;
        aPerson = Person(fname, lname); //called constructor
        //aPerson.buildUserName();    //class maintenance
        people[x] = aPerson;
    }
}

void showPeople(){
    for(int x=0; x < people.size(); x++){
        cout << people[x].to_string() << endl;
        //or
        //cout << people[x].getFname();
    }
}

int main(){

    fillTheArray();
    showPeople();

    //parameterized constuctor call
   // Person student("Kate", "Upton", "kupton");
    //default
   // Person anotherStudent("Justin", "Timberlake");
   // anotherStudent.setFname("Joe");
   // anotherStudent.setLname("Smith");
   // anotherStudent.setUsername("joesmith");
 //   cout << student.to_string() << endl;
   // cout << anotherStudent.to_string() << endl;

    //student.fn
}

