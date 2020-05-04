#ifndef DEF_BACKBAG
#define DEF_BACKBAG

#include <string>
#include"bagage.hpp"

class Backbag : public Bagage{

    public:

    /**
     * @role: (constructor): create an instance of the class Bagage of the type Backbag
     * @param: string (ID) , float (the volume)  
    **/
    Backbag(std::string , float );


    /**
     * Destructor
     * @role: distroying the object backbag
    * */
    ~Backbag();

    /**
     *@role: returns the ID of the backbag
     *@return: string: the ID 
    * */
    std::string getID() ;

    /**
     *@role: returns the volume of the backbag
     *@return: float: the volume 
    * */
    float getVolume() ;



};

#endif