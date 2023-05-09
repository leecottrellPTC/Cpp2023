#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;
void fillIntVector(vector<int> &theVector){
    string input;
    int value;
    do{
        cout << "Enter a number, type QUIT when done --> ";
        cin >> input;

        try{
            value = stoi(input);
        }
        catch(invalid_argument error){
            //handle the error
            if (input !="QUIT"){
                cout << input << " is invalid, converting to 0\n";
            }
            value = 0;
        }
        theVector.push_back(value);
    }while(input != "QUIT");
    theVector.pop_back();//remove QUIT 0
}

void displayIntVector(vector<int> theVector){
    vector<int>::iterator aNum;
    for(aNum = theVector.begin();aNum != theVector.end(); aNum++){
        cout << *aNum << endl;
    }
}

void displayIntVectorReverse(vector<int> theVector){
    vector<int>::reverse_iterator aNum;
    for(aNum = theVector.rbegin();aNum != theVector.rend(); aNum++){
        cout << *aNum << endl;
    }
}

int main(){

    vector<int> myVector = {1, 2, 3, 4};
    vector<string> words;

    array<double, 1000> myArray;
    

    
    fillIntVector(myVector);

    sort(myVector.begin(), myVector.end());

    displayIntVector(myVector);
 
 
    //put into a vector
    words.push_back("Hello");
    cout << words.at(0) << endl;
    //remove from the list
    words.pop_back();

}
