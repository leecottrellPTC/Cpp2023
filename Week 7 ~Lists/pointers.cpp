#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    double payroll = 12345.67;
    double tax = payroll * .07;     //* is multiplication
    char *name = "Lee";

    //pointers hold address of a variable
    double *payPtr, *taxPtr;
        //* is called the dereferencing operator
    //assign memory location to pointer using & - address of
    payPtr = &payroll;

    cout << "Payroll is at " << payPtr << endl;
    *payPtr = 54321;
    cout << "Payroll value is " << *payPtr << endl;
    cout << "Payroll value is " << payroll << endl;


}
