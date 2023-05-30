#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "FoodItem.cpp"
#include "GenClass.cpp"
#include "c:\data\myHeader.h"+

using namespace std;
using namespace mySpace;

// vector<string> words;
// vector<FoodItem> menu;
/*
    generic data type(s)
    setupfunctions and classes that determine data type when run
    build a generic data type
    code around the generic data type
*/

template <class T>
T bigger(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
template <class A, class B>
B addEm(A x, B y)
{
    return x + y;
}
/*
int bigger(int a, int b){
    if(a  > b){
        return a;
    }
    else{
        return b;
    }
}

string bigger(string a, string b){
    if(a  > b){
        return a;
    }
    else{
        return b;
    }
}
*/

int main()
{
    mySpace::printLine();
    cout << mySpace::PI << endl;
   /* GenClass<string> class1("Lee");
    GenClass<int> class2(15);

    cout << class1.getTheData() << endl;

    int x = 5;
    double y = 3.14;
    FoodItem apple("Apple", 3, 3);
    FoodItem cookie("Cookie", 3, 3);
    cout << addEm(apple, cookie) << endl;
    cout << addEm(x, y) << endl;
    cout << addEm(y, x) << endl;
    */
    /*
        cout << bigger(5, 3) << endl;
        cout << bigger<string>("Lee", "Zach") << endl;
        cout << bigger(3.15, 2.7)<<endl;
        //cout << bigger(3.15, "Lee")<<endl;*/
        
}



