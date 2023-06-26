#ifndef FOODITEM_H
#define FOODITEM_H

#pragma once

#include <string>
using namespace std;

class FoodItem
{
public:
    FoodItem();
    FoodItem(string Name, int Calories, double Cost);
    ~FoodItem(); // destructor

    void setName(string Name);
    string getName();

    void setCalories(int Calories);
    int getCalories();

    void setCost(double Cost);
    double getCost();

    string to_string();

    //functionality
    double perCalorieCost();

    //overloade operators
    friend ostream& operator<<(ostream &out, const FoodItem &rhs);
    friend istream& operator>>(istream &in , FoodItem &rhs);

    //comparison
    friend bool operator<(const FoodItem &lhs, const FoodItem &rhs);
    friend bool operator>(const FoodItem &lhs, const FoodItem &rhs);
    friend bool operator<=(const FoodItem &lhs, const FoodItem &rhs);
    friend bool operator>=(const FoodItem &lhs, const FoodItem &rhs);
    friend bool operator==(const FoodItem &lhs, const FoodItem &rhs);

    FoodItem operator+(FoodItem &rhs);
    FoodItem operator*(int number);//scalar multiplcation

    // methods
private:
    // variables
    string name;
    int calories;
    double cost;
};

#endif