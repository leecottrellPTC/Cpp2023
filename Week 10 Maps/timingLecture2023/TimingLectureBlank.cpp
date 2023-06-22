// TimingLecture1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <fstream>
#include <random>		
#include <vector>
#include <sys/time.h>
#include "IndexNode.cpp"
#include "binarySearchTree.h"
#include <set>
#include <queue>
#include <map>
//stl array

using namespace std;
int WORDS = 0;
array<string, 370099> wordArray;
vector<string> wordVector;
bSearchTreeType<string> wordTree;
map<string, string> wordMap;

void swap(string* xp, string* yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}
// A function to implement bubble sort  
/*
void bubbleSort()
{
	int i, j;
	for (i = 0; i < WORDS - 1; i++) {
		// Last i elements are already in place  
		for (j = 0; j < WORDS - i - 1; j++) {
			if (wordArray[j] > wordArray[j + 1])
				swap(&wordArray[j], &wordArray[j + 1]);
		}
		cout << i << "\n";
		//cout << i << " ";
	}
}
*/

void fillStructure() {
	//int counter = 0;
	string aWord = "";
	ifstream fin("words.txt");
	if (fin.fail()) {
		cout << "words failed\n";
		exit(1);
	}

	while (!fin.eof()) {
		fin >> aWord;
		wordArray[WORDS] = aWord;
		//wordVector.push_back(aWord);
		//wordTree.insert(aWord);
		//wordMap[aWord] = aWord;
		WORDS++;
		//cout << WORDS << " ";

	}
	fin.close();
	cout << WORDS << " words read\n";
	
}
int main()
{
	fillStructure();

	timeval time;
	gettimeofday(&time, NULL);
	long start = (time.tv_sec * 1000) + (time.tv_usec/1000);

	for(int x=0; x < WORDS; x++){
		if(wordArray[x] == "parch"){
			cout << "found it" << endl;
			break;
		}
	}
	//cout << wordMap["parch"] << endl;

	gettimeofday(&time, NULL);
	long end = (time.tv_sec * 1000) + (time.tv_usec/1000);

	long elapsed = end - start;
	cout << elapsed << " milliseconds " << endl;

}
