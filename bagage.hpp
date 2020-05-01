#ifndef DEF_BAGAGE
#define DEF_BAGAGE

#include <string>

class Bagage{

public:
virtual std::string getID()=0;
virtual float getVolume()=0;



protected:
    // a string to represent the bagage
    std::string _ID;
    //the volume of the bagage
    float _volume;
    
};


#endif