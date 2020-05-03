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
     * @role: (constructor): create an instance of the class Storage with a specific capacity
     * @param: the size of the storage 
     **/
    VStorage(size_t);

    /**
     * @role: (constructor): create an instance of the class Storage with a list of paires (ni,vi)
     * @param: the list of paires (ni,vi) with:
     * ni: is the number of cases that has a specific volume
     * vi: the specific volume
     **/
    VStorage(std::vector<std::pair<int,float>>);

    /**
     * @role: (constructor): create an instance of the class Storage with two lists vi and ni 
     * @param: the two lists with:
     * ni: is the number of cases that has a specific volume
     * vi: the specific volume
     **/
    VStorage(std::vector<float> , std::vector<int>);

    /**
     * @role:(Destructor) distroying the object storage
     * */
    ~VStorage();

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
    Ticket deposit(Bagage&);

    /**
     * @role:takes a ticket and returns the bagage linked to the ticket.
     * @param: the ticket.
     * @return: the bagage
     * */
    Bagage& collect(Ticket);

    /**
     * @role: verify whether the storage hase a case bigger enough for a certain volume.
     * @param: the volume.
     * @return: a boolean:
     * true if there is case bigger enough.
     * false if there is not.
     * */
    bool haveSpace(float) const;


    /**
        * @role: returns the vector _casesVolumes to show all volumes of the storage
        * @return: the vector _casesVolumes
    * */
    std::vector<float> getVolumes() const;


    /**
        * @role: returns the vector _emptyCases to show all volumes of the empty cases
        * @return: the vector _emptyCases
    * */
    std::vector<int> getEmptyCases() const;




    
    private:

    // A struct to represnt the cases by the bag in them and their volume
    struct t_casev 
    {
        
        int indexInCasesVolumes;
        Bagage &bag;
        
    }; 



    // an unordered map to link each ticket and it's the bagage 
    std::unordered_map<Ticket,t_casev, Ticket::ticketHasher> _storage;
    //the number of cases in the storage(capacity)
    size_t _nbCases;
    //the number of occupied cases 
    size_t _filledCases;
    //the number of cases that was used (not necessarily occupied at the moment)
    size_t _usingCase;
    //vector containing the indices of the empty case in _casesVolumes, used to choose the oldest used case to fill first
    std::vector<int> _emptyCases;
    //A vector of the valume of eache case
    std::vector<float> _casesVolumes;
 
};

    


#endif