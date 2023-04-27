/*
    Download frost.txt from week 2 lecture notes
    Save into same folder as .cpp
*/
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string line;
    string encrypted;
    ifstream fin;
    ofstream fout;
    int rotation = 5;
    char oneChar;
    char enc;
    int c;
    fin.open("frost.txt");
    if(fin.fail()){
        cout << "Frost.txt did not open\n";
        exit(-1);
    }

    fout.open("frost.enc");
    if(fout.fail()){
        cout << "Frost.enc did not open\n";
        exit(-1);
    }

    //do something here

    while(getline(fin, line)){
        //cout << line << endl;
        for(c = 0; c < line.length(); c++){
            oneChar = line.at(c);
            enc = oneChar + rotation;
            //if(enc > 90){
              //  enc -= 26;  //perhaps 27
            //}

            if(oneChar >=32 && oneChar <= 64){
                //punctuation
                //enc = oneChar + rotation;
                if(enc > 64){
                    enc -= 32;
                }
            }
            else if(oneChar >= 65 && oneChar <=90){
                //upper case
                if(enc > 90){
                    enc -= 26;
                }
            }
            else if(oneChar >= 97 && oneChar <= 122){
                //lower case
                if(enc > 122){
                    enc -= 26;
                }
            }
            else{
                enc = oneChar;  //set back to char from line
            }

            fout << enc;
        }
        fout << endl;

    }

    fout.close();
    fin.close();


}