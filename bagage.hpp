#ifndef DEF_BAG
#define DEF_BAG

#include <string>

class Bagage{

    public:

    Bagage(std::string s , float v);

    ~Bagage();

    std::string getID();

    float getValume();

    void changeValume(float);



    private:

    std::string _ID;

    float _valume;

};

#endif