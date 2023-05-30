#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <forward_list>
#include <iterator>
#include <cstring>
#include <cctype>
#include <algorithm>    //need for_each

using namespace std;

void fillTheList(forward_list <string> &theList, string fileName){
    string word;
    int count = 0;
    ifstream fin(fileName);

    if(fin.fail()){
        cout << fileName << " did not open\n";
        exit(-1);
    }
    while(!fin.eof()){
        fin >> word;
        theList.push_front(word);
        count ++;
    }
    cout << count << " words read from " << fileName << endl;
    theList.sort();
    fin.close();
}

void showTheList(forward_list<string> theList, int numToDisplay=50){
    forward_list<string>::iterator itr;
    int count = 1;
    for(itr = theList.begin(); itr != theList.end() && count <= numToDisplay; itr++){
        cout << left << setw(15) << *itr;    //*itr displays contents
        //if(count == numToDisplay){break;}
        if(count %5 == 0){
            cout << endl;
        }
        count++;
    }
}//end of show
void caseString(string &word){
    for(char&x : word){
        x = toupper(x);
    }
}

int main(){
    forward_list<string> adjectives, nouns, allWords;
    fillTheList(adjectives, "adjective.txt");
    fillTheList(nouns, "nouns.txt");


    for_each(nouns.begin(), nouns.end(), caseString);
    showTheList(nouns, 50);
    showTheList(adjectives, 50);
    allWords.splice_after(allWords.before_begin(), nouns);
    allWords.splice_after(allWords.before_begin(), adjectives);
    allWords.sort();
    //cout << nouns.front() << endl;
    //cout << adjectives.front() << endl;
}
