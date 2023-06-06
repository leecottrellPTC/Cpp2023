#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <algorithm>
#include <conio.h>
#include "helpTicket.cpp"

using namespace std;
void fillIntPQueue(priority_queue<int> &);
void printIntPQueue(priority_queue<int> pQueue);

int main()
{
    priority_queue<int> intpQueue;
    fillIntPQueue(intpQueue);
    printIntPQueue(intpQueue);

    priority_queue<helpTicket> helpDesk;
    helpDesk.push(helpTicket("Server room is on fire!!", 100));
    helpDesk.push(helpTicket("Printer needs paper", 10));
    helpDesk.push(helpTicket("GODZILLA", 1000));

}
void printIntPQueue(priority_queue<int> pQueue){
    int node;
    char m;
    while(!pQueue.empty()){
        node = pQueue.top();
        pQueue.pop();   //at some point remove from queue
        cout << node << endl;
        //cin.get(m);
        //cout << "Press a key to continue... ";
        m = getch();
    }
}

void fillIntPQueue(priority_queue<int> &pQueue)
{
    int input = 0;
    string strInput;
    do
    {
        cout << "Enter an integer, 0 or lower to quit-> ";
        // cin >> input;
        getline(cin, strInput);
        try
        {
            input = stoi(strInput);
            if (input > 0)
            {
                pQueue.push(input);
            }
        }
        catch (exception ex)
        {
            input = 100;    //ensures input > 0, continue loop
        }//end catch

    } while (input > 0);
    cout << pQueue.size() << " elements in the queue\n";
}
