#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    /*
    c++ strings
    old school strings are char arrays
        char name[] = "Lee";
        char *lname = "Cottrell";
        string delimiter \0

        name = lname
        strcpy(name, lname);
        string name = "Lee";
        name = "Jacob";
    */

   string sentence = "Four Score and seven years ago";
   string check = "Yes";
   if (check == "Yes"){
    //this is OK
   }
//replace all the e with 3
//sentence.replace(5, 13, "this is weird");
int pos = 0;
while((pos=sentence.find('e')) != string::npos){
    sentence.replace(pos, 1, "3");
}

replace(sentence.begin(), sentence.end(), 'o', '0');
cout << sentence << endl;

for(int p = sentence.size()-1; p >=0; p --){
    cout << sentence.at(p);
}
string name = "Dylan";
//cout << endl << sizeof("Dylan") << " chars in " << name << endl;
cout << endl;
reverse(sentence.begin(), sentence.end());
cout << sentence << endl;

}