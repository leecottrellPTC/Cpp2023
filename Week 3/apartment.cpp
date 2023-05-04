#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(){
    double rent = 600, units = 50;
    const double maintenance = 27;
    double prevProfit = 0, newProfit = 0;
    newProfit = units * (rent - maintenance);
    do{
        prevProfit = newProfit; //hold onto the last profit
        units -= 1;
        rent += 40;
        newProfit = (rent - maintenance) * units;
        
        //(profit >5) ? yes : (Profit > 6) ? aargh : nothanks;

        cout << units << " prev " << prevProfit << 
            " new profit " << newProfit << endl;
    }while(prevProfit < newProfit);
    //hav found the end condition
    units ++;   //add one unit to go back
    rent -= 40; //remove one iteration of rent
    cout << "Max Profit!!" << endl;
    cout << "Units       " << units << endl;
    cout << "Rent       $" << rent << endl;
    cout << "Profit     $" << prevProfit << endl;
}
