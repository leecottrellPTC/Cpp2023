#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main(){
    int age = 0;
    int dogage = 0;
    string name;

    std::cout <<"how old are you?\n";
    cin >> age;

    //use to solve skipped input problems
    cin.ignore(1000, '\n');//ignore 1000 cahrs or the first newline
    cin.clear();

    cout << "enter your name ";
    cin >> name;

    
    dogage = age * 7;

    cout << age << " you are " << dogage << " in dog years\n";

    cout << "Thank you!!" << endl;
    return 0;
}