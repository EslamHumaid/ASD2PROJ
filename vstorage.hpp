#ifndef DEF_VSTORAGE
#define DEF_VSTORAGE

#include <string>
#include "ticket.hpp"
#include <unordered_map>
#include <queue>
#include <vector>
#include "bagage.hpp"


class VStorage{

    public:

    /**
     * Role: (constructor): creat un object of the class Storage with a specific capacity
     * parameters: the size of the storage 
     **/
    VStorage(size_t);

    /**
     * Role:(Destructor) distroying the object storage
     * */
    ~VStorage();

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
    Ticket deposit(Bagage);

    /**
     * Role:takes a ticket and retuen the bagage linked to the ticket.
     * parameters: the ticket.
     * return: the bagage
     * */
    Bagage collect(Ticket);

    bool haveSpace(float);




    // A struct to represnt the cases by the bag in them and there valume
    private:
    typedef struct 
    {
        
        float valumeOfCase;
        Bagage bag;
        
    } t_case;



    // an unordered map to link each ticket and it's the bagage 
    std::unordered_map<Ticket,t_case, Ticket::ticketHasher> _storage;
    //the number of cases in the storage(capacity)
    size_t _nbCases;
    //the number of occupied cases 
    size_t _filledCases;
    //the number of cases that was used (not necessarily occupied at the moment)
    size_t _usingCase;
    //vector of the empty cases used to chose the oldest used case to fill first
    std::vector<float> _emptyCases;
    //A vector of the valume of eache case
    std::vector<float> _valume;
 
};

    


#endif