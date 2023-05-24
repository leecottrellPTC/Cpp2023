#pragma once
#include <iostream>
#include <iomanip>

namespace mySpace{
    const double PI = 3.1415927;
    const double PA_TAX = .06;
    const double ALLEG_TAX = .01;

    void printLine(int length = 80){
        for(int x=0; x < length; x++){
            std::cout << "-";
        }
        std::cout << "\n";
    }
}



