#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#define SIZE 20

using namespace std;

const int atbats = 600;

default_random_engine randEngine;
//https://cplusplus.com/reference/random/

double batAvg(int hit, int walk);
void randomStats(int &hit, int &walk, uniform_int_distribution<int> rndHit, normal_distribution<double> rndWalk);
int main()
{
    int hit = 100, walk = 0;
    int totHit = 0, totWalk = 0;
    double walkAvg = 30.0;
    double walkStd = 6.0;
    double avg = 0, totAvg = 0;;
    int hitMin = 120;
    int hitMax = 260;
    randEngine.seed(time(NULL));

    uniform_int_distribution<int> rndHit(hitMin, hitMax);  // better than rand
    normal_distribution<double> rndWalk(walkAvg, walkStd); // random based on the normal curve
    
   //cout << left << setw(5) << "Hit" << setw(5) <<left <<"Walk" << left <<setw(6) <<"Avg" << endl;
    for (int itr = 0; itr < SIZE; itr++)
    {
        randomStats(hit, walk, rndHit, rndWalk);
        avg = batAvg(hit, walk);
        totAvg += avg;
        totHit += hit;
        totWalk += walk;
        //cout << setw(5) <<hit << right << setw(4) << walk << right << setw(6) << setprecision(3) << fixed << avg << endl;
    }//end for loop
    hit = totHit/SIZE;
    walk = totWalk/SIZE;
    avg = totAvg / SIZE;
    cout <<"Predicted stats\n";
    cout << left << setw(5) << "Hit" << setw(5) <<left <<"Walk" << left <<setw(6) <<"Avg" << endl;
    cout << setw(5) <<hit << right << setw(4) << walk << right << setw(6) << setprecision(3) << fixed << avg << endl;
}

void randomStats(int &hit, int &walk, uniform_int_distribution<int> rndHit, normal_distribution<double> rndWalk)
{

    // #include  <random>
    hit = rndHit(randEngine);
    // discrete prob hit
    // normal prob walk
    walk = rndWalk(randEngine);
}

double batAvg(int hit, int walk)
{
    double avg = 0;

    avg = hit / (float)(atbats - walk);

    return avg;
}
