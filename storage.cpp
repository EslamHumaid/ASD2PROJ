#include "ticket.hpp"
#include "storage.hpp"
#include "cassert"
#include <unordered_map>
#include<iostream>


using namespace std;

  // A struct to represnt the cases by the bag in them and there index in the vector
  typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;


typedef std::pair<Ticket,t_case> t_entree;

/**
  * Role: (constructor): creat un instante of the class Storage with a specific capacity
  * parameters: the size of the storage 
**/
Storage::Storage(size_t nb){
    //the storage must have a capacity greater then 0
    assert(nb>0);
    _nbCases = nb;
    _filledCases = 0;
    _usingCase = 0;

}

/**
* Destructor
* Role: distroying the object storage
* */
Storage::~Storage(){}

/**
  * Role: verify whether the storage is full or not.
  * returns a boolean :
  * true if the storage is full
  * false if the storage is not full
* */
bool Storage::isFull() const{
    //returns true if the number of filledCases is equal to the nbCases(capacity)
    return _filledCases == _nbCases;
}


/**
  * Role: takes a bagage and puts it in a Case.
  * parameters: the bagage.
  * returns a ticket that is linked to the bagage.
* */
Ticket Storage::deposit(bagage bagToAdd){
    //stops the program if the storage if full
    assert(!isFull());
    //the index of the case in the vector(Cases)
    int index;
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

    //craeting a t_case and give it the bagage and the index in the vector(Cases)
    t_case caseToAdd;
    caseToAdd.indexInVect = index;
    caseToAdd.bag = bagToAdd;
    //creating a new ticket
    Ticket T;

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));

    //creating un iterator 
    auto it = _Cases.begin();
    it += index;
    //adding the ticket to the vector(Cases)
    _Cases.insert(it,T);

    //incressing the number of usingCase and filledCases
    _usingCase++;
    _filledCases++;


}

/**
  * Role:takes a ticket and retuen the bagage linked to the ticket.
  * parameters: the ticket.
  * return: the bagage
* */
bagage Storage::collect(Ticket T){
    //if the storage is empty we can not collect any bagage 
    assert(_filledCases>0);

    //searching the unordered map (storage) for the bagage linked to tickit (T)
    t_case obtainedCase = _storage.at(T);
    int index = obtainedCase.indexInVect;
    auto it = _Cases.begin() + index;
    //erasing the cases from the vector(Cases)
    _Cases.erase(it);
    //adding the index of the empty case to the queue(emptyCases)
    _emptyCases.push(index);
    //erasing the cases from the unordered map (storage)
    _storage.erase(T);

    //decressing the number of filledCases
    _filledCases--;

    //returning the bagage
    return obtainedCase.bag;


}


