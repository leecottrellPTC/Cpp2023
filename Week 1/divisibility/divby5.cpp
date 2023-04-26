#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main(){
    int num = 47;
    int lastDigit = num % 10;

    //cout << lastDigit << endl;
    if(lastDigit == 5 || lastDigit == 0){
        cout << num << " is divisible by 5"<< endl;
    }
    else{
        cout << num << " is NOT divisible by 5"<< endl;
    }

    return 0;
}