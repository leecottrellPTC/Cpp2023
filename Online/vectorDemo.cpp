#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

void populateVector(vector<string> &names){
    string input = "";
    do{
        cout << "Enter a name, DONE to quit ";
        cin >> input;
        if(input != "DONE"){
            names.push_back(input);//puts into the vector
        }
    }while(input != "DONE");
}

void printVector(vector<string> names){
  /*  for(int x=0; x < names.size(); x++){
        cout << names.at(x) << endl;
    }
    */
    vector<string>::iterator itr;
    for(itr = names.begin(); itr != names.end(); itr++){
        cout << *itr << endl;
    }
}

int main(){
    vector<string> names;
   

    populateVector(names);
    printVector(names);

}
