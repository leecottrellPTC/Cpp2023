#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    double principal = 10000;
    double rate = 18;
    double term = 5;
    double payment = 0;
    //if cin interest, check 
    //if > 1 then divide by 100
    if(rate > 1){
        rate = rate / 100.0;
    }
    rate = rate / 12;   //this was my error, set to monthy rate
    int mon = term * 12;

    double numerator = rate * pow(1 + rate, mon);
    double denominator = pow(1 + rate, mon) -1;
    payment = principal * (numerator/denominator);
    //payment = principal * (rate * pow(1 + rate, mon))/ (pow(1 + rate, mon) -1);
    //payment = 253.93;     //hard code cheat

    
    cout << setprecision(2) << fixed;
    cout << "$" << payment << endl;

    double actualPay = 0;
    //build a header for the table
    cout << setw(3) << "Mon" << setw(11) << "Principal"
         << setw(11) << "Total Pay"<< endl;
    cout << setfill('-') << setw(25) << "\n";   //complicated line
    //turn off setfill
    cout << setfill(' ');
    for(mon = 1; mon <= term * 12; mon++){  //I had < term*12 - error

        actualPay += payment;           //total payments
        principal += principal * rate;  //add interest
        principal -= payment;           //subtract payment
       
        cout << setw(3) << mon << setw(11) << principal
         << setw(11) << actualPay<< endl;
       
    }
    cout << "Your total payment is $" << actualPay << endl;
    cout << "You paid $" << actualPay - principal 
        << " in interest" << endl;


}