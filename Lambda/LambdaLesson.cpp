// new project - Lamb dLesson
// add fooditem and food list

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "FoodItem.cpp"

using namespace std;
vector<FoodItem> yummy;
void fillFood()
{
    ifstream fin("foodlist.txt");
    string name;
    int calories, cost;
    FoodItem food;
    if (fin.fail())
    {
        cout << "file did not open\n";
        exit(42);
    }
    while (!fin.eof())
    {
        fin >> name >> calories >> cost;
        food = FoodItem(name, calories, cost);
        yummy.push_back(food);
    }
    cout << yummy.size() << " records read\n";
    fin.close();
}

template <class T>
void printVector(vector<T> vec)
{
    for_each(vec.begin(), vec.end(),
             [](T i)
             {
                 cout << i << endl;
             });
}

int main()
{

    // make lambda look like function
    auto addTax = [](double cost) -> double
    { return cost * 1.07; };
    // cout << addTax(100) << endl;
    fillFood();
    // override the default operator <
    sort(yummy.begin(), yummy.end(),
         [](FoodItem a, FoodItem b)
         {
             return a.getCost() < b.getCost();
         });
    double maxCost = 6;
    for_each(yummy.begin(), yummy.end(),
             [maxCost](FoodItem f)
             {
                 if (f.getCost() < maxCost)
                 {
                     cout << f << endl;
                 }
             });
    //call lambda in lambda
    for_each(yummy.begin(), yummy.end(),
             [maxCost, addTax](FoodItem f)
             {
                 if (f.getCost() < maxCost)
                 {
                     // cout << f << endl;
                     cout << addTax(f.getCost()) << endl;
                 }
             });
    // printVector(yummy);
    /* vector<int> ray;    //filled with rand between 0 - 99
     for(int x=0; x < 1000; x++){
         ray.push_back(int(rand()%100));
     }
     //ascending
     sort(ray.begin(), ray.end(),
         [](int a, int b) -> bool{
             //return a < b;
             return a > b;
         }
     );

     printVector(ray);
 */
    // fast brute force search
    /* auto p = find_if(ray.begin(), ray.end(),
         [](int i){
             return i > 90;
         }
     );

     cout << *p << " bigger than 90\n";*/
}
