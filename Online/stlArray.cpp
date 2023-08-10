#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#define SIZE 5

using namespace std;

void printArray(array<int, SIZE> ray){
    for(int x=0; x < ray.size(); x++){
        cout << ray.at(x)<< endl;
    }
}

void fillArray(array<int, SIZE> &ray){
    for(int x=0; x < ray.size(); x++){
        cout << "Enter value at position " << x << "--> ";
        cin >> ray[x];
    }
}

int main(){
    array<int, SIZE> numbers;
    numbers[0] = 5;
    numbers.at(1) = 15;
    numbers.at(2) = 19;
    numbers.at(3) = 75;
    numbers[4] = 33;
    fillArray(numbers);
    printArray(numbers);
    
    array<string, 50> names;

}
