#include "backbag.hpp"
#include<iostream>

using namespace std;

/**
 * @role: (constructor): create an instance of the class Bagage 
 * @param: string (ID) , float (the valume)  
**/
Backbag::Backbag(string id , float val){

    _ID = id;
    _volume = val;
}

/**
* Destructor
* @role: distroying the object storage
* since there aren't any dynamic allocations, no actions are needed.
* */
Backbag::~Backbag(){}


/**
 *@role: returns the ID of the bagage
 *@return: string: the ID 
* */
string Backbag::getID() {
    return _ID;
}


/**
 *@role: returns the valume of the bagage
 *@return: float: the valume 
* */
float Backbag::getVolume() {
    return _volume;
}


/**
 *@role: changing the valume of the bagage
 *@parm: the new valume 
* */
/*
void Bagage::changeValume(float newval){

    _valume = newval;
}
*/
