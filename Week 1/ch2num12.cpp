#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    int seconds=0, hours=0, minutes=0;
    //int const SECINHOUR = 60*60;
    int const CONVERT = 60;

//HI cALLE AND CHUCK
    cout << "Enter the number of seconds ";
    cin >> seconds;// >> hours >> minutes;
    cout << "You entered " << seconds << " seconds " << endl;

    hours = seconds / (CONVERT * CONVERT);
    seconds = seconds % (CONVERT * CONVERT);

    minutes = seconds / CONVERT;
    seconds = seconds % CONVERT;
    //alt seconds %= CONVERT;
    //seconds = seconds - minutes * CONVERT;
    cout << hours << ":" 
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) <<seconds << endl;
}