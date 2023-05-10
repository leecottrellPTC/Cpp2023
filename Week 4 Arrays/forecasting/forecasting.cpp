#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
vector<int> temps;
int readFile(string filename){
    ifstream fin;
    int records = 0;//changed
    int temp;
    string input;
    fin.open(filename);
    if(fin.fail()){
        cout << filename << " did not open, quitting\n";
        return 0;
    }
    while(getline(fin, input)){
        records ++;
        try{
            temp = stoi(input);      
        }
        catch(exception ex){
            //ignore a bad read!
        }
        //cout << temp << " ";
        temps.push_back(temp);
        
    }

    fin.close();
    return records;
}

int main(){
    int records;

    records = readFile("dailytemps.txt");
    if(records <= 0){
        cout << "file not read, quitting\n";
        return -1;
    }
    cout << records << " temperatures read\n";

}
