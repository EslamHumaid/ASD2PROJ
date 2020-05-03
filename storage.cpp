/**
* @file:  storage.cpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 06/04/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/

#include "ticket.hpp"
#include "storage.hpp"
#include "cassert" //for the assertions
#include <unordered_map>



using namespace std;

  // A struct to represnt the cases by the bag in them and there index in the vector _cases
  typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;


typedef std::pair<Ticket,t_case> t_entree;

/**
  * @role: (constructor): create an instance of the class Storage with a specific capacity
  * @param: the size of the storage 
**/
Storage::Storage(size_t nb){
    //the storage must have a capacity greater then 0
    assert(nb>0);

    _nbCases = nb;
    _filledCases = 0;
    _usingCase = 0;

}

/**
* @role: (Destructor) distroying the object storage
* since there aren't any dynamic allocations, no actions are needed.
* */
Storage::~Storage(){}

/**
  * @role: verify whether the storage is full or not.
  * @return: a boolean :
  * true if the storage is full
  * false if the storage is not full
* */
bool Storage::isFull() const{
    //returns true if the number of filledCases is equal to the nbCases(capacity)
    return _filledCases == _nbCases;
}


/**
  * @role: takes a bagage and puts it in a Case in the storage.
  * @param: the bagage.
  * @return: a ticket that is linked to the bagage.
* */
Ticket Storage::deposit(bagage bagToAdd){
    
    assert(!isFull());  //stops the program if the storage if full
    int index;  //the index of the case in the vector(_cases)


    //verifing whether all the cases were used for the first time or not
    if(_usingCase <= _nbCases){
        //if theres a case which have never been used
        //then it's index in the vector(Cases) will be equal to usingCase.
        index = _usingCase;
    }else{
        //if all the cases have been used for at least one time
        //then we check the queue(emptyCases) for the oldest empty case
        index = _emptyCases.front();
        _emptyCases.pop();
    }

    //creating a t_case and giving it the bagage and the index in the vector(_cases)
    t_case caseToAdd;
    caseToAdd.indexInVect = index;
    caseToAdd.bag = bagToAdd;


    //creating a new ticket
    Ticket T;

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));

    //creating un iterator 
    auto it = _cases.begin();
    it += index;
    //adding the ticket to the vector(Cases)
    _cases.insert(it,T);

    //incressing the number of usingCase and filledCases
    _usingCase++;
    _filledCases++;


  return T;

}

/**
  * @role:takes a ticket and retuen the bagage linked to the ticket.
  * @param: the ticket.
  * @return: the bagage
* */
bagage Storage::collect(Ticket T){
    //if the storage is empty we can not collect any bagage 
    assert(_filledCases>0);

    //searching the unordered map (storage) for the bagage linked to tickit (T)
    t_case obtainedCase = _storage.at(T);
    int index = obtainedCase.indexInVect;
    auto it = _cases.begin() + index;

    //erasing the cases from the vector(Cases)
    _cases.erase(it);

    //adding the index of the empty case to the queue(emptyCases)
    _emptyCases.push(index);

    //erasing the cases from the unordered map (storage)
    _storage.erase(T);

    //decressing the number of filledCases
    _filledCases--;

    //returning the bagage
    return obtainedCase.bag;


}


