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

    /**
     * Role: (constructor): creat un object of the class Storage with a specific capacity
     * parameters: the size of the storage 
     **/
    Storage(size_t);

    /**
     * Role:(Destructor) distroying the object storage
     * */
    ~Storage();

    /**
     * Role: verify whether the storage is full or not.
     * returns a boolean :
     * true if the storage is full
     * false if the storage is not full
     * */
    bool isFull() const;

    /**
     * Role: takes a bagage and puts it in a Case.
     * parameters: the bagage.
     * returns a ticket that is linked to the bagage.
     * */
    Ticket deposit(bagage);

    /**
     * Role:takes a ticket and retuen the bagage linked to the ticket.
     * parameters: the ticket.
     * return: the bagage
     * */
    bagage collect(Ticket);




    // A struct to represnt the cases by the bag in them and there index in the vector
    private:
    typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;


    //A vector of tickets to represent all the cases after there first use
    std::vector<Ticket> _Cases; 
    // an unordered map to link each ticket and it's the bagage 
    std::unordered_map<Ticket,t_case, Ticket::ticketHasher> _storage;
    //the number of cases in the storage(capacity)
    size_t _nbCases;
    //the number of occupied cases 
    size_t _filledCases;
    //the number of cases that was used (not necessarily occupied at the moment)
    size_t _usingCase;
    //queue of the empty cases used to chose the oldest used case to fill first
    std::queue<int> _emptyCases;





 
};

    


#endif