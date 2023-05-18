#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <random>

class Player
{
public:
    Player();
    ~Player();
    Player(std::default_random_engine randEngine);
    inline int getAtBats(){
        return atBats;
    }
    inline int getHits(){
        return hits;
    }
    inline int getWalks(){
        return walks;
    }
    inline double getBatAvg(){
        return batAvg;
    }
    inline void addHits(int h){
        hits += h;
    }
    inline void addWalks(int w){
        walks += w;
    }
  /*  inline void addBatAvg(double ){
        batAvg += hits / (double)(atBats - walks);
    }
    */
private:
    int atBats = 450;
    int hits = 0;
    int walks = 0;
    double batAvg = 0.0;
};

#endif