#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
vector<int> temps;
int readFile(string filename){
    ifstream fin;
    int records = 0;//changed
    int temp;
    string input;
    fin.open(filename);
    if(fin.fail()){
        cout << filename << " did not open, quitting\n";
        return 0;
    }
    while(getline(fin, input)){
        records ++;
        try{
            temp = stoi(input);      
        }
        catch(exception ex){
            //ignore a bad read!
        }
        //cout << temp << " ";
        temps.push_back(temp);
        
    }

    fin.close();
    return records;
}

double naiveForecastTable();//build table, calc and return error
double absError(double actual, double forecast);
double avgPastValueTable();

int main(){
    int records;
    double naiveError;
    double avgPastError = 0;

    records = readFile("dailytemps.txt");
    if(records <= 0){
        cout << "file not read, quitting\n";
        return -1;
    }
    cout << records << " temperatures read\n";
    naiveError = naiveForecastTable();
    avgPastError = avgPastValueTable();

    cout << "Naive Error    = " << naiveError << endl;
    cout << "Avg Past Error = " << avgPastError << endl;

}

/**
 * @brief 
 * 
 * @return double 
 */
double avgPastValueTable(){
    double forecast;
    double actual;
    double error = 0;
    double totError = 0;
    double totTemps = 0;
    double MAE = 0; //mean absolute error
  //  cout << setw(5) << "Day"<< setw(10) << "Forecast" << setw(10) 
  //      << "Actual" << setw(10) << "Error" << endl; 
    for(int day = 1; day < temps.size(); day++){//walk forward
        for(int back = day -1; back >= 0; back --){ //walk backwards
            //cout << temps.at(back) << " " ;
            totTemps += temps.at(back);
        }//end inner for
        forecast = totTemps / day;
        actual = temps.at(day);
        error = absError(actual, forecast);
        totError += error;
        totTemps = 0;
        //cout << endl;
    //    cout << setw(5) << day<< setw(10) << forecast << setw(10) 
   //         << actual << setw(10) << error << endl;
    }
    MAE = totError / (temps.size() -1);
    return MAE;
}

double absError(double actual, double forecast){
    return abs(actual - forecast);
}
double naiveForecastTable(){
    double forecast;
    double actual;
    double error = 0;
    double totError = 0;
    double MAE = 0; //mean absolute error

    //logic here
 //   cout << setw(5) << "Day"<< setw(10) << "Forecast" << setw(10) 
 //       << "Actual" << setw(10) << "Error" << endl; 
    for(int day = 1; day < temps.size(); day ++){
        forecast = temps.at(day -1);
        actual = temps.at(day);
        error = absError(actual, forecast);
        totError += error;
  //      cout << setw(5) << day<< setw(10) << forecast << setw(10) 
  //      << actual << setw(10) << error << endl;
    }

    MAE = totError / (temps.size() - 1);
    return MAE;

}