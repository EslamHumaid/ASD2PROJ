#include "bagage.hpp"
#include<iostream>

using namespace std;

Bagage::Bagage(string id , float val){

    _ID = id;
    _valume = val;
}

Bagage::~Bagage(){}

string Bagage::getID(){
    return _ID;
}

float Bagage::getValume(){
    return _valume;
}

float Bagage::getValume(){
    return _valume;
}

void Bagage::changeValume(float newval){

    _valume = newval;
}
