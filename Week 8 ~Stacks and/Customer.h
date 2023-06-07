#ifndef CUST_CLASS
#define CUST_CLASS
using namespace std;
#include <string>
#include <cmath>
const int IPM = 15;
//items processed per minute

class customer {
protected:
	int items;
	string payment;
	int checkoutTime;
	 void calcCheckoutTime() {
		if (payment == "cash") {
			checkoutTime = 1;	//2 minute for cash
		}
		else
		{
			checkoutTime = 0;	//1 minute for credit
		}
		checkoutTime += round(items / IPM);
		//not perfect but it should average out
		
	}
public:
	customer() {
		items = int(rand() % 120) +1;//1 - 60 items
		if ((int)(rand() % 4) == 0) {
			payment = "cash";
		}
		else {
			payment = "card";
		}
		calcCheckoutTime();
		
		
	}
	
	void setPayment(string pay) {
		payment = pay;
		calcCheckoutTime();
	}
	void setItems(int buggy) {
		items = buggy;
		calcCheckoutTime();
	}
	int getItemsInBuggy() {
		return items;
	}
	int getCheckoutTime() {
		return checkoutTime;
	}
	string getPayment() {
		return payment;
	}
	void removeItemsFromBuggy(int num = IPM) {
		items -= num;
	}

	string to_string() {
		
		return "items: " + std::to_string(items) + " payment: " + payment + " checkoutTime: " + std::to_string(checkoutTime);		
	}
	friend bool operator <(customer& lhs, customer& rhs) {
		return lhs.items < rhs.items;
	}
	friend bool operator >(customer& lhs, customer& rhs) {
		return lhs.items > rhs.items;
	}
	friend ostream& operator <<(ostream& out, customer& rhs) {
		out << "items: " << rhs.items << " payment: " << rhs.payment << " checkoutTime: " << rhs.checkoutTime;
		return out;
	}
	customer operator=(const customer& rhs) {
		items = rhs.items;
		payment = rhs.payment;
		checkoutTime = rhs.checkoutTime;
		return *this;
	}

	friend bool operator==(customer& lhs, customer& rhs) {
		if (lhs.items == rhs.items && lhs.payment == rhs.payment && lhs.checkoutTime == rhs.checkoutTime) {
			return true;
		}
		else {
			return false;
		}
	}

};

#endif