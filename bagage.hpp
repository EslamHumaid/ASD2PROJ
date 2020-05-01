#ifndef DEF_BAGAGE
#define DEF_BAGAGE

#include <string>

class Bagage{

    public:

    /**
     * @role: (constructor): create an instance of the class Bagage 
     * @param: string (ID) , float (the valume)  
    **/
    Bagage(std::string , float );


    /**
     * Destructor
     * @role: distroying the object Bagage
    * */
    ~Bagage();

    /**
     *@role: returns the ID of the bagage
     *@return: string: the ID 
    * */
    std::string getID() const;

    /**
     *@role: returns the valume of the bagage
     *@return: float: the valume 
    * */
    float getValume() const;

    /**
     *@role: changing the valume of the bagage
     *@parm: the new valume 
    * */
    void changeValume(float);



    private:

    // a string to represent the bagage
    std::string _ID;

    //the valume of the bagage
    float _valume;

};

#endif