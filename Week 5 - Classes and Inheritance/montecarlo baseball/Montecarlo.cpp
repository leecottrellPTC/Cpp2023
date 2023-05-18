#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Player.cpp"
#include <random>
#include <array>
#define SIZE 10000

using namespace std;
default_random_engine randEngine;

int main(){
    randEngine.seed(time(NULL));
    array<Player, SIZE> players;
    Player totPlayer;
    for(int x=0; x < SIZE; x++){
        players[x] = Player(randEngine);
        totPlayer.addHits(players[x].getHits());
        totPlayer.addWalks(players[x].getWalks());
        //totPlayer.addBatAvg(players[x].getBatAvg());
    }

    double batAvg = totPlayer.getHits() / (double)(450 * SIZE - totPlayer.getWalks());
    cout << "Bat avg = " << batAvg << endl;
    /*double atBats[SIZE];
    int hits[SIZE];
    int walks[SIZE];
    double batAvg[SIZE];*/
    /*Player p1(randEngine);
    cout << "at Bats "<< p1.getAtBats() << endl;
    cout << "walks "<< p1.getWalks() << endl;
    cout << "hits "<< p1.getHits() << endl;
    cout << "batAvg "<< p1.getBatAvg() << endl;*/
}
