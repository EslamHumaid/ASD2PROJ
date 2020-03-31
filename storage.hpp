#ifndef DEF_STORAGE
#define DEF_STORAGE

#include <string>
#include "ticket.hpp"
#include <unordered_map>
#include <queue>
#include <vector>




typedef std::string bagage;

class Storage{

    public:

    Storage(size_t);
    ~Storage();
    bool isFull() const;
    Ticket deposit(bagage);
    bagage collect(Ticket);




    private:
    typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;


    std::vector<Ticket> Cases; 
    std::unordered_map<Ticket,t_case> storage;
    size_t nbCases;
    size_t filledCases;
    size_t usingCase;
    std::queue<int> emptyCases;





 
};

    


#endif