//Data
//68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999
 
#include <iostream>
#include "binarySearchTree.h"
#include "IndexNode.cpp"
#include <fstream>
#include <vector>
using namespace std; 

int fillWords(string filename, vector<string> &words, 
	bSearchTreeType<IndexNode> &index)
{
	ifstream fin(filename);
	string line;
	int count = 0;
	if(fin.fail()){
		cout << filename << " did not open " << endl;
		exit(-1);}//end if
	while(getline(fin, line)){
		words.push_back(line);	
		index.insert(IndexNode(line, count));
		count ++;}//end while
	fin.close();
	return count;
}
int main()
{
	vector<string> wordList;
	bSearchTreeType<IndexNode> index;
	int count = fillWords("adjective.txt", wordList, index);
	
	return 0;
	
}