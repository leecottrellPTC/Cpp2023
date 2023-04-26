#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main(){
    string number = "1457";
    int len = number.length();
    int total = 0;
    for(int c=0; c < len; c++){
        //cout << number.at(c) << endl;
        total += (number.at(c) - '0');
    }
    //cout << total << endl;
    if(total % 3 == 0){
        cout << number << " is divisible by 3" << endl;
    }
    else{
        cout << number << " is NOT divisible by 3" << endl;
    }
}