#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#define SIZE 5

using namespace std;

void printArray(int ray[]){
    for(int x=0; x < SIZE; x++){
        cout << "Pos " << x << " value " << ray[x] << endl;
    }
}

void fillarrayKeyboard(int ray[]){
    for(int x=0; x < SIZE; x++){
        cout << "Enter value for position " << x << " --> ";
        cin >> ray[x];
    }
}

void addFive(int ray[]){
    for(int x=0; x < SIZE; x++){
        ray[x] += 5;
    }
}

int main(){
    int numbers[SIZE];
    float prices[] = {4.5, 2,3, 1.5, 6.7};
    /*numbers[0] = 15;
    numbers[1] = 33;
    numbers[2] = 22;
    numbers[3] = 11;
    numbers[4] = 77;*/
    //numbers[5] = 66;//don't go beyond edge of array
    fillarrayKeyboard(numbers);
    addFive(numbers);
    printArray(numbers);
}
