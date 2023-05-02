#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

//function prototype here
void printMyName();
double grossPay(double rate, int hours);
void inputData(double &rate, int &hours);
void output(double, int, double);

int main(){
    //call whereever
    double rate = 15.5;
    int hours = 40;
    double gross = 0;
    string again = "Y";
    do{
        printMyName();  //function call
        inputData(rate, hours);
        gross = grossPay(rate, hours);
        output(rate, hours, gross);
        cout << "More payroll to calculate <Y/N> ";
        cin >> again;
        //must be uppercase
        cin.ignore(1000, '\n');
        cin.clear();
    }while(toupper(again.at(0)) == 'Y');
}

//function definition here
void output(double rate, int hours, double gross){
    cout << setprecision(2) << fixed;
    cout << "Rate = $" << rate << endl;
    cout << "Hours = " << hours << endl;
    cout << "Gross pay is $" << gross << endl;
}
void inputData(double &rate, int &hours){
    cout << "Enter the rate $ ";
    cin >> rate;

    cout << "Enter the hours worked (whole numbers)";
    cin >> hours;
}
double grossPay(double rate, int hours){
    //create a variable, do the math to the variabe, return the var
    double gross = 123; //I do not know hte math, this is just a cheat

    if(hours >= 0 && hours <= 40){
        gross = rate * hours;
    }
    else if(hours > 40){
        gross = 40 * rate + (hours - 40) * rate * 1.5;
    }
    else{
        gross = -1;
    }

    return gross;
}
void printMyName(){
    cout << "Lee Cottrell\n";
}