//newẇproject called mapLecture
//add the FoodItem class to the project folded

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

using namespace std;
map <string, double> gradePoints;
void basicMap(){
    gradePoints["A+"] = 4.25;
    gradePoints["A"] = 4.00;
    gradePoints["A-"] = 3.75;

    gradePoints["B+"] = 3.5;
    gradePoints["B"] = 3.0;
    gradePoints["B-"] = 2.75;

    gradePoints["C+"] = 2.5;
    gradePoints["C"] = 2.0;
    gradePoints["C-"] = 1.75;

    gradePoints["D+"] = 1.5;
    gradePoints["D"] = 1;
    gradePoints["D-"] = 0.75;

    gradePoints["F"] = 0.1;
}

void calcGrade(){
    int count = 0;
    double totalGrade = 0;
    string grade = "";
    do{
        cout << "Enter a letter grade, X to quit ";
        cin >> grade;
        if(gradePoints[grade] != NULL){    //0 
            count ++;
            totalGrade += gradePoints[grade];
            cout << grade << " is worth " << gradePoints[grade] << endl;
        }
    }while(grade != "X");
    cout << "GPA = " << totalGrade / count << endl;
}
int main(){
    basicMap();
    calcGrade();

}

