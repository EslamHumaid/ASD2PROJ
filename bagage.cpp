#include "bagage.hpp"
#include<iostream>

using namespace std;

/**
 * @role: (constructor): create an instance of the class Bagage 
 * @param: string (ID) , float (the valume)  
**/
Bagage::Bagage(string id , float val){

    _ID = id;
    _valume = val;
}

/**
* Destructor
* @role: distroying the object storage
* since there aren't any dynamic allocations, no actions are needed.
* */
Bagage::~Bagage(){}


/**
 *@role: returns the ID of the bagage
 *@return: string: the ID 
* */
string Bagage::getID() const{
    return _ID;
}


/**
 *@role: returns the valume of the bagage
 *@return: float: the valume 
* */
float Bagage::getValume() const{
    return _valume;
}


/**
 *@role: changing the valume of the bagage
 *@parm: the new valume 
* */
void Bagage::changeValume(float newval){

    _valume = newval;
}
