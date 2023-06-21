#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include "FoodItem.cpp"
#include <iterator>
using namespace std;

map<string, FoodItem> foodMap;
multiset<FoodItem, less <FoodItem>> eaten;
//ordered but allow duplicates
void fillMap(){
    ifstream fin("foodlist.txt");
    if(fin.fail()){
        cout << "foodlist did not open\n";
        exit(-1);
    }

    string foodName;
    int calories;
    int price;
    FoodItem someFood;

    while(!fin.eof()){
        fin >> foodName >> calories >> price;
        someFood = FoodItem(foodName, calories, price);
        foodMap[foodName] = someFood;//add to the list
        cout << foodName << endl;
        //foodMap.insert(pair<string, FoodItem>(foodName, someFood));
    }
    cout << foodMap.size() << " elements read \n";

    fin.close();   
}
void trackFood(){
    string foodName;
    int totalCalories = 0;
    do{
        cout << "Enter food eaten, 'done' to quit-> ";
        cin >> foodName;
        if(foodMap[foodName].getName() != "no name"){
            //if food is in the database
            eaten.insert(foodMap[foodName]);
            totalCalories += foodMap[foodName].getCalories();
        }
        else if(foodName != "done"){
            cout << foodName << " is not found\n";
        }
        //cout << foodMap[foodName] << endl;
    }while(foodName != "done");

    //output using iterator
    ostream_iterator<FoodItem> screen(cout, "\n");
                        //valid output, line delimiter
    copy(eaten.begin(), eaten.end(), screen);

    cout << "You ate " << totalCalories << " calories of food\n";
}
void findFoodCosts(double cost){
    //search map and display food that costs less than value
    map<string, FoodItem>::iterator foodItr;
    for(foodItr = foodMap.begin(); foodItr != foodMap.end(); foodItr++)
    {
        if(foodItr->second.getCost() < cost){
            cout << foodItr->second << endl;
        }
    }
}
int main(){
    fillMap();
    trackFood();
    findFoodCosts(5);
}
