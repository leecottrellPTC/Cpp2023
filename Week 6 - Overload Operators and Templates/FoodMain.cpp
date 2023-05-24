#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "FoodItem.cpp"
using namespace std;
int main(){
    FoodItem apple("Apple", 100, 1.5);
    FoodItem cookie("Oreo", 150, 2);
    FoodItem sum = apple + cookie;
    cout << sum.getName() << " " << sum.getCalories() << endl;

    cout << apple << " " << cookie << endl;

    if(apple > cookie){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
