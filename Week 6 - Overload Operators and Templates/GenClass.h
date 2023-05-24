#ifndef GENCLASS_H
#define GENCLASS_H

#pragma once

template <class C>
class GenClass
{
public:
    inline GenClass(){}
    inline ~GenClass(){}
    inline GenClass(C data){
        this->theData = data;
    }

    inline void setTheData(C theData){
        this->theData = data;
    }
    inline C getTheData(){
        return theData;
    }

private:
    C theData;
};

#endif