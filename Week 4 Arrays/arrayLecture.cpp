#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#define SIZE 50
using namespace std;

void showArray(int array[]);
void inputArray(int array[]);
void fillArrayRand(int array[]);
int linearSearch(int array[], int toFind);


int main(){
    int value[SIZE];// = {4, 36, 75, 22, -1};
    srand(time(0));
    //inputArray(value);
    fillArrayRand(value);
    showArray(value);

    int found = linearSearch(value, 42);
    if(found >=0){
        cout << 42 << " is at position " << found <<endl;
    }
    else{
        cout << 42 << " is NOT in the list\n";
    }
}

int linearSearch(int array[], int toFind){
    int found = -1;
    for(int x=0; x < SIZE; x++){
        if(array[x] == toFind){
            return x;
            //found = x;
            //break;
        }//end if
    }//end for
    return found;
}

void fillArrayRand(int array[]){
    //rand() - returns a number between 1 and 65,535
    //var = rand() % yourLimit + 1
    for(int x=0; x < SIZE; x++){
        array[x] = rand() % 100 + 1;
    }
}
void inputArray(int array[]){
    for(int x=0; x < SIZE; x++){
        cout << "Enter the " << x << " value ";
        cin >> array[x];
    }
}

void showArray(int array[]){
    for(int x=0; x < SIZE; x++){
        cout << x << " " << array[x] << endl;
    }
}
