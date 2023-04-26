#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main(){
    string name = "Tyler Makrush";
    int len = name.length();
    int total = 0;
    for(int c=0; c < len; c++){
        cout <<left << setw(5)<< c <<  name.at(c) << endl;
    }
}
   