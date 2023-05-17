#include "Employee.h"

Employee::Employee():Person()
{

}

Employee::~Employee()
{

}
Employee::Employee(string fname, string lname, 
        string title, double sal, 
        vector<string> list):Person(fname, lname)
        {
            this->setJobTitle(title);
            salary = sal;
            skills = list;
        }

Employee::Employee(string fname, 
    string lname, string title, double sal):Person(fname, lname)
    {
        //jobTitle = title;
        this->setJobTitle(title);
        salary = sal;
    }

   //either way
    Employee::Employee(Person peep, 
        string title, double sal):Person(peep.getFname(), peep.getLname())
    {
        //Person::fname = peep.getFname();
    }

  /*  Employee::Employee(Person peep, 
        string title, double sal)//:Person(peep.getFname(), peep.getLname())
    {
        Person::fname = peep.getFname();
    }
*/

string Employee::to_string(){
    char salOutput[10]; //need a size here
    string output = Person::to_string();    //use parent to_string
    output += "Job title " + jobTitle;
    std::sprintf(salOutput, " $%.2f", salary);//two decimal places
    output += salOutput;
    //to_string(salary)

    return output;
}