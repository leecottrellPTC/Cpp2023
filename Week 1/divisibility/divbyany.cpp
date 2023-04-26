#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main(){
    int check, divisor = 3, orignum = 15;
    check = orignum;

    while(check >= divisor){
        check -= divisor;
        //cout << check << endl;
    }
    if(check == 0){
        cout << orignum << " is divisible by " << divisor << endl;
    }
    else{
        
        cout << orignum << " is NOT divisible by " << divisor << endl;
    }
}