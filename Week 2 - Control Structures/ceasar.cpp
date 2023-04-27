#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
/*
        open the file
        walk through the file (parse)
        encrypt the letters
        write the encryption out to a file
        close the files
    */
using namespace std;

int main(){
    string line;
    string encrypted;
    ifstream fin;
    ofstream fout;
    int rotation = 5;
    //there is a random weird letter in frost, kill it
    //open the files
    fin.open("frost.txt");
    if(fin.fail()){
        cout << "Frost.txt not opened\n";
        return -1;
    }
    fout.open("frost.enc");
    if(fout.fail()){
        cout << "Frost.enc not opened\n";
        return -2;
    }
    while(getline(fin, line)){
        //keep looping as long as there are lines in the file
        //cout << line << endl;
        char theChar;
        char enc;
        encrypted = "";//clear out the encryption
        for(int c=0; c < line.length(); c++){
            theChar = toupper(line.at(c));
            if(theChar >=65 && theChar <= 90){
                enc = (theChar + rotation) % 26 + 65;
            }
            else if(theChar >=32 && theChar <= 64){
                //orig 
                //enc = theChar;
                enc = (theChar + rotation) % 32 + 32;   //32 punc and numbers
            }
            else{
                enc = theChar;
            }
           encrypted += enc;
           //cout << enc << endl;
        }
        fout << encrypted << endl;
    }

    fout.close();
    fin.close();

    return 0;
}