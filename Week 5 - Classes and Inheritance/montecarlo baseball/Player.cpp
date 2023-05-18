#include "Player.h"
#include <random>



Player::Player()
{

}

Player::~Player()
{

}

Player::Player(std::default_random_engine randEngine)
{
    std::uniform_int_distribution<int> rndWalk(6, 30);//min,max
    std::normal_distribution<double> rndHit(117.0, 15.0);//avg, standard deviation

    hits = rndHit(randEngine);
    walks = rndWalk(randEngine);
    
    batAvg = hits / (double)(atBats - walks);

}
