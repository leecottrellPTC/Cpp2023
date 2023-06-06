#ifndef HELPTICKET_H
#define HELPTICKET_H
#pragma once
#include <string>
using namespace std;
class helpTicket
{
public:
    helpTicket();
    ~helpTicket();
    helpTicket(string desc, int pri = 0){
        description = desc;
        priority = pri;
    }
    string getDescription(){
        return description;
    }

    friend bool operator<(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority < rhs.priority;
    }

    friend bool operator>(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority > rhs.priority;
    }

    friend bool operator<=(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority <= rhs.priority;
    }

    friend bool operator>=(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority >= rhs.priority;
    }

    friend bool operator==(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority == rhs.priority;
    }

    friend bool operator!=(const helpTicket &lhs, const helpTicket &rhs){
        return lhs.priority != rhs.priority;
    }
    
private:
    int priority;
    string description;
};

#endif