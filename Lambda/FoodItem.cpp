#include "FoodItem.h"
#include <iostream>
#include <iomanip>

FoodItem::FoodItem()
{
    name = "no name";
    calories = 0;
    cost = 0;
}

FoodItem::FoodItem(string Name, int Calories, double Cost)
{
    name = Name;
    calories = Calories;
    this->cost = Cost;
}

FoodItem::~FoodItem()
{
}

// setters and getters

void FoodItem::setName(string Name)
{
    this->name = Name;
}
string FoodItem::getName()
{
    return name;
}
void FoodItem::setCalories(int Calories)
{
    calories = Calories;
}
int FoodItem::getCalories()
{
    return calories;
}
void FoodItem::setCost(double Cost)
{
    cost = Cost;
}
double FoodItem::getCost()
{
    return cost;
}

string FoodItem::to_string()
{
    return name + " calories " + std::to_string(calories) + " costs " + std::to_string(cost);
}

double FoodItem::perCalorieCost()
{
    return cost / calories;
}

ostream &operator<<(ostream &out, const FoodItem &rhs)
{
    out << rhs.name << " costs " << fixed << setprecision(2) << rhs.cost;
    return out;
}

istream &operator>>(istream &in, FoodItem &rhs)
{
    cout << "Enter the food name ";
    in >> rhs.name;

    cout << "Enter " << rhs.name << " cost ";
    in >> rhs.cost;

    cout << "Enter " << rhs.name << " calories ";
    in >> rhs.calories;
    return in;
}

bool operator<(const FoodItem &lhs, const FoodItem &rhs)
{
    return lhs.calories < rhs.calories;
}

bool operator>(const FoodItem &lhs, const FoodItem &rhs)
{
    return lhs.calories > rhs.calories;
}

bool operator>=(const FoodItem &lhs, const FoodItem &rhs)
{
    return lhs.calories >= rhs.calories;
}
bool operator<=(const FoodItem &lhs, const FoodItem &rhs)
{
    return lhs.calories <= rhs.calories;
}
bool operator==(const FoodItem &lhs, const FoodItem &rhs)
{

    return ((lhs.name == rhs.name) && 
    (lhs.calories == rhs.calories) && 
    (lhs.cost == rhs.cost));
}

FoodItem FoodItem::operator+(FoodItem &rhs)
{
    FoodItem sum;

    sum.name = this->name + " and " + rhs.name;
    sum.calories = this->calories + rhs.calories;
    sum.cost = this->cost + rhs.cost;
    // sum.cost = (this->cost + rhs.cost) / 2;
    return sum;
}

FoodItem FoodItem::operator*(int number)
{
    FoodItem mulFood;
    string name = std::to_string(number) + " of " + name;
    mulFood.setName(name);
    mulFood.setCalories(calories * number);
    mulFood.setCost(cost * number);

    return mulFood;
    
}
