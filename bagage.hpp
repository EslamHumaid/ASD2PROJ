#ifndef DEF_BAGAGE
#define DEF_BAGAGE

#include <string>

class Bagage{

public:
/**
 *@role: returns the ID of the backbag
 *@return: string: the ID 
* */
virtual std::string getID()=0;


/**
 *@role: returns the volume of the backbag
 *@return: float: the volume 
* */
virtual float getVolume()=0;



protected:
    // a string to represent the bagage
    std::string _ID;
    //the volume of the bagage
    float _volume;
    
};


#endif