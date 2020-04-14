#ifndef DEF_BAGAGE
#define DEF_BAGAGE

#include <string>

class Bagage{

    public:

    Bagage(std::string , float );

    ~Bagage();

    std::string getID() const;

    float getValume() const;

    void changeValume(float);



    private:

    std::string _ID;

    float _valume;

};

#endif