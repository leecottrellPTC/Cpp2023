#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <forward_list>
#include "FoodItem.cpp"
#include <iterator>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    forward_list<FoodItem> dinner;
    forward_list<FoodItem>::iterator foodItr;
    array<FoodItem, 100>::iterator arrayItr;
    FoodItem f;
    dinner.push_front(FoodItem("Steak", 300, 35.00));
    dinner.push_front(FoodItem("Potato", 1200, 5.00));
    dinner.push_front(FoodItem("Asparagus", 1100, 2.5));
    dinner.sort();
    //sort(dinner.begin(), dinner.end());

    for(foodItr = dinner.begin(); foodItr != dinner.end(); foodItr++){
        cout << * foodItr << endl;
    }
    
    //search for food in a list
    //searching for a property in the list
    string foodName = "Asparagus";

    for(foodItr = dinner.begin(); foodItr != dinner.end(); foodItr++){
        //if(foodItr == object)
        if(foodItr->getName() == foodName){
            cout << foodName << " Found ";
            break;
        }
    }
    


}
