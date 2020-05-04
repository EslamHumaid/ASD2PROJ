/**
* @file:  vstorage.hpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 04/05/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/


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
     * @role: (constructor): create an instance of the class VStorage with a list of paires (ni,vi)
     * @pre: The list must not be empty.
     * @param: the list of paires (ni,vi) with:
     * ni: is the number of cases that has a specific volume
     * vi: the specific volume
     **/
    VStorage(std::vector<std::pair<int,float>>);

    /**
     * @role: (constructor): create an instance of the class VStorage with two lists vi and ni 
     * @pre: the two lists must have the same size but they must not be empty.
     * @param: the two lists with:
     * ni: is the number of cases that has a specific volume
     * vi: the specific volume
     **/
    VStorage(std::vector<float> , std::vector<int>);

    /**
     * @role:(Destructor) distroying the object VStorage
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
     * @pre: the storage must have enough space for the bag.
     * @param: the bagage.
     * @return: a ticket that is linked to the bagage.
     * */
    Ticket deposit(Bagage&);

    /**
     * @role:takes a ticket and returns the bagage linked to the ticket.
     * @pre: the storage should not be empty.
     * @param: the ticket.
     * @return: the bagage
     * */
    Bagage& collect(Ticket);

    /**
     * @role: verify whether the storage hase a case big enough for a certain volume.
     * @param: the volume.
     * @return: a boolean:
     * true if there is a big enough case.
     * false if there is not.
     * */
    bool haveSpace(float) const;


    /**
        * @role: returns the vector _casesVolumes to show all volumes of the storage
        * @return: the vector _casesVolumes
    * */
    std::vector<float> getVolumes() const;


    /**
        * @role: returns the vector _emptyCases to show all indices of the empty cases
        * @return: the vector _emptyCases
    * */
    std::vector<int> getEmptyCases() const;




    
    private:

    // A struct to represnt the cases by the bag in them and their index in _casesVolumes
    struct t_casev {
        
        int indexInCasesVolumes;
        Bagage &bag;
        
    }; 



    
    std::unordered_map<Ticket,t_casev, Ticket::ticketHasher> _storage; // an unordered map to link each ticket and its bagage 
    size_t _nbCases;   //the number of cases in the storage(capacity)
    size_t _filledCases;   //the number of occupied cases 
    std::vector<int> _emptyCases;   //vector containing the indices of the empty cases in _casesVolumes, used to choose the oldest used case to fill first
    std::vector<float> _casesVolumes;   //A vector of volumes to represent all the cases
 
};

    


#endif