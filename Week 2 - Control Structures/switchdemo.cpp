#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    //switch works on char, int, long
    int choice = 5;
    //fill choice before switch
    switch(choice){
        case 1:
            cout << "First";
            //do lots of work here
            break;
        case 2:
            cout << "Second";
            break;
        case 3:
        case 4:
            cout << "Handles three and four";
            break;
        //repeat for every valid case
        default:
            cout << "Error";
            break;
    }
}