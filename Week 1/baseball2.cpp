#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//not important but doable
#define WID setw(10)
#define SHowMeTheMoney cout
using namespace std;

int main(){
    ifstream fin;
    int number, atbats, hits, walks;
    float batavg = 0;

    fin.open("baseball.txt");

    if(fin.fail()){
        cout << "File did not open, quitting\n";
        exit(1);//kills the program
    }
    //cout << setw(10) << "Number" << setw(10) << "Bat Avg" << endl;
    cout << WID << "Number" << WID << "Bat Avg" << endl;
    //different read style, may fix double line read
    while(fin >> number >> atbats >> hits >> walks){
    //while(!fin.eof()){//original line
        
        if(atbats == walks){
            batavg = 0;
        }else{
            batavg = hits / static_cast<float>(atbats - walks);
        }
        cout << setprecision(3) << fixed;
        cout << setw(10) << number << setw(10) << batavg << endl;
    }
    //do something with the file
    fin.close();

}