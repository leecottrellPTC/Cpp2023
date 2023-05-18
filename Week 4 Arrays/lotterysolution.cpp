#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

using namespace std;

array<int, 5> lottery;
array<int, 100> picked;  //defaults to 0, add one when the number is selected
void pickLotteryNumbers();

int main(){
    srand(time(NULL));
    pickLotteryNumbers();

    cout << "Winning numbers \n";
    for(int x=0; x < lottery.size(); x++){
        cout << lottery[x] << " ";
    }
    cout << endl;

    return 0;
}

void pickLotteryNumbers(){
    //generate 5 numbers from 1 - 100, each selected one time. 
    //imagine a vat with 100 balls
    int ball = 0;
    for(int rn = 0; rn < lottery.size(); rn ++){
        do{
            ball = (rand() % picked.size()) + 1;  //between 1 and max digit
            picked[ball] ++;    //count the number of times a number is selected.
        } 
        while(picked[ball] > 1);    //repeat the pick if the ball is already chosen
                                    //if you want to allow 2 of something, just change the 1 to a 2...
        lottery[rn] = ball;         //store the ball in the lottery array
    }
    std::sort(lottery.begin(), lottery.end());  //just to display in order
}