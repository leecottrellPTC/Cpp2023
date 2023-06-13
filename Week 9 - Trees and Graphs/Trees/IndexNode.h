#ifndef INDEXNODE_H
#define INDEXNODE_H

#pragma once
#include <string>
#include <iostream>
using namespace std;

class IndexNode
{
public:
    IndexNode();
    ~IndexNode();
    IndexNode(string k, int p){
        key = k;
        position = p;
    }

    string key;     //must be unique
    int position;   //array index

    friend bool operator==(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key == rhs.key;
    }

    friend bool operator>(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key > rhs.key;
    }

    friend bool operator<(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key < rhs.key;
    }

    friend bool operator<=(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key <= rhs.key;
    }

    friend bool operator>=(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key >= rhs.key;
    }

    friend bool operator!=(const IndexNode &lhs, const IndexNode &rhs){
        return lhs.key != rhs.key;
    }

    friend ostream &operator<<(ostream &out, const IndexNode &rhs){
        out << rhs.key << " at " << rhs.position << "\n";
        return out;
    }

private:

};

#endif