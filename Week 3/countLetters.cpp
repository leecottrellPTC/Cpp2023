//new file - countLetters.cpp
//copy frost.txt to the same folder (or know the path)
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;
void parseFile(string path, int letters[], 
    int &numWords, int &numLines, int &numLetters);

void showCounts(int letters[], int numWords, int numLetters,
    int numLines);
void countLetters(string line, int letters[], int &numLetters);
void countWords(string line, int &numWords);


int main(){
    int numLetters = 0;
    int numWords = 0;
    int numLines = 0;
    int letters[26];
    
    for(int x=0; x < 26; x++){
        letters[x] = 0;
        /*if(x %2 == 0){
            letters[x+1] = letters[x]/2;
        }
        else{
            letters[x+1] = letters[x] *3 + 1;
        }*/
    }
    parseFile("frost.txt", letters, numWords, numLines, numLetters);
    showCounts(letters, numWords, numLetters, numLines);

}//end main

void parseFile(string path, int letters[], 
    int &numWords, int &numLines, int &numLetters){
        ifstream fin;
        string line = "";
        fin.open(path);
        if(fin.fail()){
            cout << path << " did not open\n";
            exit(1);
        }
        while(getline(fin, line)){
            countLetters(line, letters, numLetters);
            countWords(line, numWords);
            numLines ++;
        }
        fin.close();

}//end parse file
void countWords(string line, int &numWords){
    char *token;
    char *nextToken;
    char *cstr = new char[line.length() + 1];

    strcpy_s(cstr, line.length() + 1, line.c_str());
    //strcpy(cstr, line.c_str());

    token = strtok_s(cstr, " ", &nextToken);
    //token = strtok(cstr, " ");
    while(token != NULL){
        numWords ++;
        token = strtok_s(NULL, " ", &nextToken);
        //token = strtok(NULL, " ");
    }

}


void countLetters(string line, int letters[], int &numLetters){
    char let;
    for(int c = 0; c < line.length(); c++){
        let = toupper(line.at(c));

        if(let >= 65 && let <= 90){
            //ASCII A = 65
            letters[let - 65]++;    //count letters
            numLetters ++;
        }
    }
}

void showCounts(int letters[], int numWords, int numLetters,
    int numLines){
        for(int let = 'A'; let <= 'Z'; let ++){
            cout << left << setw(10) << (char) let << 
                right << setw(6) << letters[let -65] <<endl;
        }
        cout << left << setw(10) << "Lines " << right <<
            setw(6) << numLines << endl;
        cout << left << setw(10) << "Words " << right <<
            setw(6) << numWords << endl;
        cout << left << setw(10) << "Letters " << right <<
            setw(6) << numLetters << endl;
    }

