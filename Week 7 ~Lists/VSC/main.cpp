#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "FoodItem.cpp"
#include "unorderedlinkedList.h"
#include "orderedlinkedList.h"

using namespace std;

int main()
{
/*	orderedLinkedList <FoodItem> breakfast;
	breakfast.insertLast(FoodItem("Eggs", 100, 1));
	breakfast.insertLast(FoodItem("Bacon", 200, 1.5));
	breakfast.insertLast(FoodItem("Apple", 80, 1.5));
	breakfast.print();
	cout << "\n\n";*/
	unorderedLinkedList <FoodItem> dinner;
	dinner.insertLast(FoodItem("Steak", 430, 11));
	dinner.insertLast(FoodItem("Potato", 200, 11));
	dinner.insertLast(FoodItem("Salad", 90, 11));

	dinner.deleteSmallest();
	dinner.print();
}