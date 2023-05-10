#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#define HIRECORD 366
#define LORECORD 365
#define LOWCOL 0
#define HICOL 1

using namespace std;

int temps[367][2];  //lo temp, hi temp
//365 - hold low values
//366 - hold hi values

int readFile(string filename){
    ifstream fin;
    int records = -1;//changed
    int day;    //throwaway the day
    fin.open(filename);
    if(fin.fail()){
        cout << filename << " did not open, quitting\n";
        return 0;
    }
    while(!fin.eof()){
        records ++;
        fin >> day >> temps[records][0] >> temps[records][1];
    }

    fin.close();
    return records;
}

void processArray(){
    temps[LORECORD][LOWCOL] = temps[0][LOWCOL];    //use the first low value 
    temps[HIRECORD][HICOL] = temps[0][HICOL];

    temps[LORECORD][HICOL] = 100;//temps[0][HICOL];   //hightest of low
    temps[HIRECORD][LOWCOL] = temps[0][LOWCOL]; //lowest of high

    for(int row = 0; row < 365; row ++){
        //find lowest
        //temps[LORECORD][HICOL]
        if(temps[row][LOWCOL] < temps[LORECORD][LOWCOL]){
            temps[LORECORD][LOWCOL] = temps[row][LOWCOL];
        }

        if(temps[row][HICOL] < temps[LORECORD][HICOL]){
           // cout << "Fired row " << row << " " << temps[row][HICOL] << "\n";
            temps[LORECORD][HICOL] = temps[row][HICOL];
     }   //lowest hi

        //find highest
        if(temps[row][HICOL] > temps[HIRECORD][HICOL]){
            temps[HIRECORD][HICOL] = temps[row][HICOL];
        }

        //highest low
        if(temps[row][LOWCOL] > temps[HIRECORD][LOWCOL]){
            temps[HIRECORD][LOWCOL] = temps[row][LOWCOL];
        }

    }//end for
}//end function

int main(){
    int records = 0;
    records = readFile("temps.txt");

    if(records <= 0){
        cout << "No records read!!\n";
        return 0;
    }
    else{
        cout<< records << " records read!!\n";
    }

    processArray();

   /* cout << "Low in low col " << temps[LORECORD][LOWCOL] << endl;
    cout << "Hi in hi col " << temps[HIRECORD][HICOL] << endl;*/

    cout << "Summary  " << "Daily Low " << "Daily Hi " << endl;
    cout << "Low Temp " << setw(9) << temps[LORECORD][LOWCOL] 
        << setw(9) << temps[LORECORD][HICOL] << endl;
    cout << "Hi Temp  " << setw(9) << temps[HIRECORD][LOWCOL] 
        << setw(9) << temps[HIRECORD][HICOL] << endl;
    return 0;

}
