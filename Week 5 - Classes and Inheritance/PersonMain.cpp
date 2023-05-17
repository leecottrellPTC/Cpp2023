#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include "Person.cpp"
#include "Employee.cpp"
#include <Vector>
#include <string.h>

using namespace std;
array <Person, 2> people;
vector <Employee> employees;

void fillEmployeesFromFile(string file){
    ifstream fin;
    string line;
    Employee emp;
    int counter = 0;
    char *token;
    char *nextToken;
    char *cstr;//the line
    fin.open(file);
    if(fin.fail()){
        cout << file << " did not open, quitting\n";
        exit(1);
    }
    while(getline(fin, line)){
        //cout << line << endl;
        cstr = new char[line.length()+1];   //size cstr
        strcpy_s(cstr, line.length() +1, line.c_str());
       // strcpy(cstr, line.c_str()); //mac or linux
       token = strtok_s(cstr, ",", &nextToken);//find first comma
       //token = strtok(cstr, ",");  //mac
       // cout << token << endl;
        emp.setFname(token);
        while(token != NULL){
            counter ++; //determine hte column
            token = strtok_s(NULL, ",", &nextToken);
            //token = strtok(NULL, ",");
            switch(counter){
                case 1:
                    emp.setLname(token);
                    break;
                case 2:
                    emp.setJobTitle(token);
                    break;
                case 3:
                    emp.setSalary(stod(token));
                    break;
                default:
                    break;
            }//end of switch

        }//strtok while
        //cout << emp.getFname() << endl;
        //need to read each part of the line
        //add to the employee variable
        //add to the vector
        employees.push_back(emp);
        emp = Employee();   //reset to default values, erase current
        counter = 0;    //reset counter
    }//line while
    fin.close();
}
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
    fillEmployeesFromFile("MOCK_DATA.csv");
    cout << employees.at(5).to_string() << endl;

    //fillTheArray();
    //showPeople();

    /*vector <string>skills;
    skills.push_back("Math");
    skills.push_back("Logic");

    Employee emp("Kate", "Bush", "Nurse", 50000, skills);
    cout << emp.to_string() << endl;

    for(int s = 0; s < emp.getSKills().size() ; s++){
        cout << emp.getSKills().at(s) << endl;
    }
    */

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

