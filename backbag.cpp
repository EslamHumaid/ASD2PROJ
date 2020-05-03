#include "backbag.hpp"
#include<iostream>

using namespace std;

/**
 * @role: (constructor): create an instance of the class Bagage of the type Backbag
 * @param: string (ID) , float (the volume)  
**/
Backbag::Backbag(string id , float vol){

    _ID = id;
    _volume = vol;
}

/**
* Destructor
* @role: distroying the object storage
* since there aren't any dynamic allocations, no actions are needed.
* */
Backbag::~Backbag(){}


/**
 *@role: returns the ID of the backbag
 *@return: string: the ID 
* */
string Backbag::getID() {
    return _ID;
}


/**
 *@role: returns the volume of the backbag
 *@return: float: the volume 
* */
float Backbag::getVolume() {
    return _volume;
}


/**
 *@role: changing the volume of the backbag
 *@parm: the new volume 
* */
/*
void Backbag::changeVolume(float newvol){

    _volume = newvol;
}
*/
