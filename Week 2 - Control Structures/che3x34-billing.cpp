#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
int main(){
    double bill = 150;
    double pay = 0;
    double adjustment = 0;
    
    do{
        cout << " Enter the payment $";
        cin >> pay;
        if(pay >= bill){
            cout << "Pay in full!!\n";
            //determine the credit/penalty
            //adjust the balance
            //credit is 10 or 1% of balance
            adjustment = pay * .01;
            if(adjustment > 10){
                adjustment = 10;
            }
            cout << "Credit $" << adjustment << endl;
            bill -= pay;//subtract off the payment
            bill -= adjustment;
        }
        else if(pay >= bill / 2.0){
            cout << "Pay at least half\n";
            adjustment = bill * .1;
            bill += adjustment;
            bill -= pay;
            cout << "Penalty 10% $" << adjustment << endl;
        }
        else if(pay >= bill / 5.0 && pay < bill / 2.0){
            cout << "Pay betweeen 20 and 50%\n";
            //calc the penalty on balance BEFORE payment
            //cal new balance
            adjustment = bill * .2;
            bill += adjustment;
            bill -= pay;
            cout << "Penalty 10% $" << adjustment << endl;
        }
        else{
        cout << "Invalid payment amount, must pay at least $" 
            << bill * .2 << endl;
    }
    }while(pay < bill / 5.0);

    cout << "Bill is now $" << bill << endl;


}