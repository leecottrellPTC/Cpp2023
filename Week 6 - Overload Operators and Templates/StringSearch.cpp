#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
void showVector(vector<int> found){
    for(int f=0; f < found.size(); f++){
        cout << found.at(f) << " ";
    }
    cout << endl;
}
vector<int> naiveSearch(string body, string search){
    int s = 0, b = 0;
    vector<int> found;
    /*
    walk through body
    if search[0] == body[b]
        compare rest of search to the next parts of body
        if a mismatch, break out of the loop
        if you get through entire search term, you found a copy
    */
    for(b = 0; b < body.size() - search.size()+1; b++){
        if(toupper(search.at(0)) == toupper(body.at(b)) ){
            for(s = 1; s < search.size(); s++){
                if(toupper(body.at(b+s)) != toupper(search.at(s))){
                    break;
                }//end inner if
            }//end for s
            if(s == search.size()){
                //found the search string at b
                found.push_back(b);
            }
        }//end if forst char
    }//end for b
    return found;
}

int main(){
    string body = "AAAAAABAABAAAABAAABAAA";
    string search="AAA";
    vector<int> found;
    found = naiveSearch(body, search);
    showVector(found);
}
