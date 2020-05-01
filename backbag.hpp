#ifndef DEF_BACKBAG
#define DEF_BACKBAG

#include <string>
#include"bagage.hpp"

class Backbag : public Bagage{

    public:

    /**
     * @role: (constructor): create an instance of the class Bagage 
     * @param: string (ID) , float (the valume)  
    **/
    Backbag(std::string , float );


    /**
     * Destructor
     * @role: distroying the object Bagage
    * */
    ~Backbag();

    /**
     *@role: returns the ID of the bagage
     *@return: string: the ID 
    * */
    std::string getID() ;

    /**
     *@role: returns the valume of the bagage
     *@return: float: the valume 
    * */
    float getVolume() ;


    /*
    /
     *@role: changing the valume of the bagage
     *@parm: the new valume 
    
    void changeValume(float);
    */

};

#endif