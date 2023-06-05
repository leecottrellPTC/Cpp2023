#pragma once
#include <string>

using namespace std;
class FoodItem
{
public:
	FoodItem();
	FoodItem(string Name, int Calories, double Cost);
	~FoodItem();
	void setName(string Name);
	void setCalories(int Cal);
	void setCost(double Cost);
	string to_string();

	string getName();
	int getCalories();
	double getCost();

	//operators
	//cookie + milk
	FoodItem operator + (FoodItem& item);
	friend ostream& operator <<(ostream& out, const FoodItem& item);
	friend istream& operator >>(istream& in, FoodItem& item);

	//if(cookie > milk)
	//    lhs      rhs
	friend bool operator>(FoodItem& lhs, const FoodItem& rhs);
	friend bool operator<(FoodItem& lhs, const FoodItem& rhs);
	friend bool operator>=(FoodItem& lhs, const FoodItem& rhs);
	friend bool operator<=(FoodItem& lhs, const FoodItem& rhs);
	friend bool operator==(FoodItem& lhs, const FoodItem& rhs);
	friend bool operator!=(FoodItem& lhs, const FoodItem& rhs);
	
	FoodItem operator * (double amt);

	//postfix and prefix ++
	//unary operators, work on one variable
	FoodItem operator++();	//prefix ++
	//++egg

	FoodItem operator++(int);	//postfix, the int is a dummy and is not used
	//egg++

protected:
	string name;
	int calories;
	double cost;
};


