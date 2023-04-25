#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(){
    double townA = 5000, townB=8000;
    double growA = .04, growB = .02;
    int year = 0;

    while(townA < townB){
        townA *= (1 + growA);
        //townA = townA + townA(growA);
        townB *= (1 + growB);
        year ++;
        cout << townA << " " << townB << endl;
    }
    //cout << townA << " " << townB << " " << year << endl;
    //townA = round(townA);
    cout << setprecision(0) << fixed;
    cout << "Town A pop = " << townA << endl;
    cout << setprecision(0) << fixed;
    cout << "Town B pop = " << townB << endl;
    cout << "A beats B in " << year << " years" << endl;
}