/**
* @file:  bagage.hpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 04/05/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/

#ifndef DEF_BAGAGE
#define DEF_BAGAGE

#include <string>

class Bagage{

public:
/**
 *@role: returns the ID of the bagage
 *@return: string: the ID 
* */
virtual std::string getID()=0;


/**
 *@role: returns the volume of the bagage
 *@return: float: the volume 
* */
virtual float getVolume()=0;



protected:

    std::string _ID; // a string to represent the bagage
    float _volume; //the volume of the bagage
    
};


#endif