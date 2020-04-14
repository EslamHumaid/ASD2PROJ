/**
* @file:  storage.hpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 06/04/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/

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
     * @role: (constructor): create an instance of the class Storage with a specific capacity
     * @param: the size of the storage 
     **/
    Storage(size_t);

    /**
     * @role:(Destructor) distroying the object storage
     * */
    ~Storage();

    /**
     * @role: verify whether the storage is full or not.
     * @return: a boolean :
     * true if the storage is full
     * false if the storage is not full
     * */
    bool isFull() const;

    /**
     * @role: takes a bagage and puts it in a Case in the storage.
     * @param: the bagage.
     * @return: a ticket that is linked to the bagage.
     * */
    Ticket deposit(bagage);

    /**
     * @role:takes a ticket and returns the bagage linked to the ticket.
     * @param: the ticket.
     * @return: the bagage
     * */
    bagage collect(Ticket);




    
    private:

    // A struct to represnt the cases by the bag in them and their index in the vector
    typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;


    
    std::vector<Ticket> _cases;   //A vector of tickets to represent all the cases
    std::unordered_map<Ticket,t_case, Ticket::ticketHasher> _storage;  // an unordered map to link each ticket and it's bagage 
    size_t _nbCases;   //the number of cases in the storage(capacity)
    size_t _filledCases;  //the number of occupied cases 
    size_t _usingCase;   //the total number of deposit operations
    std::queue<int> _emptyCases;  //queue of the empty cases used to chose the oldest used case to fill first





 
};

    


#endif