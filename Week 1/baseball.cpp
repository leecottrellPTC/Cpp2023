#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
    cout << WID << "Number" << WID << "Bat Avg" << endl;
    while(!fin.eof()){
        fin >> number >> atbats >> hits >> walks;
        //cout << number << " " << atbats << " " << hits 
        //   << " " << walks << endl;
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