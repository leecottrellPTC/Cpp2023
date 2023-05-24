#include "FoodItem.h"

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

//operators
FoodItem FoodItem::operator+(FoodItem &rhs){
    FoodItem sum;
    sum.calories = this->calories + rhs.calories;
    sum.setCost(this->cost + rhs.cost);
    sum.setName(this->getName() + " " + rhs.getName());
    return sum;
}

bool operator<(const FoodItem &lhs, const FoodItem &rhs)
{
    if(lhs.calories < rhs.calories){
        return true;
    }
    else {
        return false;
    }
}

bool operator>(const FoodItem &lhs, const FoodItem &rhs)
{
    return lhs.calories > rhs.calories;
}

bool operator==(const FoodItem &lhs, const FoodItem &rhs)
{
    //compare each property 
    if(!(lhs.name == rhs.name)){
        return false;
    }
    if(!(lhs.cost == rhs.cost)){
        return false;
    }
    if(!(lhs.calories == rhs.calories)){
        return false;
    }
    return true;    //only fires if the objects are equal

}

ostream &operator<<(ostream &out, const FoodItem &rhs)
{
    // TODO: insert return statement here
    out << rhs.name << " costs $" 
        << rhs.cost << " calories " << rhs.calories;
    
    return out;

}

istream &operator>>(istream &in, FoodItem &rhs)
{
   cout << "Enter the food name ->";
   in >> rhs.name;

   cout << "Enter the food calories ->";
   in >> rhs.calories;

   cout << "Enter the food cost ->";
   in >> rhs.cost;
   return in;
}
