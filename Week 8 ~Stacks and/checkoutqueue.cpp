#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Customer.h"
#include <queue>

using namespace std;

queue<customer> checkoutline;
int curCustTime = 0;
int itemsSold = 0;
int custCount = 0;
int totItemsSold = 0;
int totCustCount = 0;
int totCustLeft = 0;

void addCustomer();
void checkOut();
int main()
{
    srand(time(NULL));
    int runs = 10000;
    for (int r = 0; r < runs; r++)
    {
        for (int min = 1; min <= 120; min++)
        {
            addCustomer();
            checkOut();
        }
        
        totCustLeft += checkoutline.size();
        totCustCount += custCount;
        totItemsSold += itemsSold;
        //clear out data
        custCount = 0;
        itemsSold = 0;
        //clear out queue
        while(!checkoutline.empty()){
            checkoutline.pop();
        }
    }//end of runs for loop
    cout << "After " << runs << " simulations of 2 hours\n";
    cout << "People left in queue " << totCustLeft / runs << endl;
    cout << "Customers serviced   " << totCustCount / runs << endl;
    cout << "Items sold           " << totItemsSold / runs << endl;
}
void addCustomer()
{
    int newCust = int(rand()) % 20;
    switch (newCust)
    {
        /* case 0:
         case 1:
         case 2:
         case 3:
         case 4:
             //no customers in line
             break;*/
    case 5:
    case 6:
    case 7:
        checkoutline.push(customer());
        break;
    case 8:
        checkoutline.push(customer());
        checkoutline.push(customer());
        break;
    case 9:
        checkoutline.push(customer());
        checkoutline.push(customer());
        checkoutline.push(customer());
        break;
    default:
        // default no customers
        break;
    };
}

void checkOut()
{
    if (checkoutline.empty())
    {
        return;
    }

    customer current = checkoutline.front();
    curCustTime++; // assume minimum 1 minute per customer
    if (curCustTime >= current.getCheckoutTime())
    {
        // customer is done and has paid
        custCount++;
        curCustTime = 0; // reset to 0 for next customer
        itemsSold += current.getItemsInBuggy();
        checkoutline.pop();
    }
}
