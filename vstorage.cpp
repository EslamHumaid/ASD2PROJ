#include "ticket.hpp"
#include "vstorage.hpp"
#include "cassert"
#include <unordered_map>
#include<iostream>
#include "bagage.hpp"


using namespace std;

  // A struct to represnt the cases by the bag in them and there index in the vector
    typedef struct 
    {
        
        float valumeOfCase;
        Bagage bag;
        
    } t_case;


typedef std::pair<Ticket,t_case> t_entree;

/**
  * Role: (constructor): creat un instante of the class Storage with a specific capacity
  * parameters: the size of the storage 
**/
VStorage::VStorage(size_t nb){
  //the storage must have a capacity greater then 0
  assert(nb>0);
  _nbCases = nb;
  _filledCases = 0;
  _usingCase = 0;

  for(int i = 0; i <= _nbCases ; i++){
    float v; //the valume of the case
    v = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100)); // a random value of the valume

    _valume[i]=v;
    _emptyCases[i] = v;
  }

}

/**
* Destructor
* Role: distroying the object storage
* */
VStorage::~VStorage(){}

/**
  * Role: verify whether the storage is full or not.
  * returns a boolean :
  * true if the storage is full
  * false if the storage is not full
* */
bool VStorage::isFull() const{
    //returns true if the number of filledCases is equal to the nbCases(capacity)
    return _filledCases == _nbCases;
}


/**
  * Role: takes a bagage and puts it in a Case.
  * parameters: the bagage.
  * returns a ticket that is linked to the bagage.
* */
Ticket VStorage::deposit(Bagage bagToAdd){
  
    float valumeOfBag = bagToAdd.getValume();
    //stops the program if the storage if full
    assert(!haveSpace(valumeOfBag));
    //the index of the case in the vector(Cases)
    int index = -1;
    float currentval;
    for(int i = 0 ; i<=_emptyCases.size() ; i++){

      if(index == -1){
        if(_emptyCases[i] >= valumeOfBag){
          index = i;
          currentval =  _emptyCases[i];
        }
      }else{
        if((_emptyCases[i] >= valumeOfBag) and (_emptyCases[i] < currentval) ){
          index = i;
          currentval =  _emptyCases[i];
        }
      }

    }

    //deleting the case chosen from _emptyCases
    _emptyCases.erase(_emptyCases.begin()+index);

    //craeting a t_case and give it the bagage and the index in the vector(Cases)
    t_case caseToAdd;
    caseToAdd.valumeOfCase = currentval;
    caseToAdd.bag = bagToAdd;
    //creating a new ticket
    Ticket T;

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));


    //incressing the number of usingCase and filledCases
    _usingCase++;
    _filledCases++;


  return T;

}

/**
  * Role:takes a ticket and retuen the bagage linked to the ticket.
  * parameters: the ticket.
  * return: the bagage
* */
Bagage VStorage::collect(Ticket T){
    //if the storage is empty we can not collect any bagage 
    assert(_filledCases>0);

    //searching the unordered map (storage) for the bagage linked to tickit (T)
    t_case obtainedCase = _storage.at(T);
    //adding the index of the empty case to the queue(emptyCases)
    _emptyCases.push_back(obtainedCase.valumeOfCase);
    //erasing the cases from the unordered map (storage)
    _storage.erase(T);

    //decressing the number of filledCases
    _filledCases--;

    //returning the bagage
    return obtainedCase.bag;


}


bool VStorage::haveSpace(float val){
  bool res = false;

  if(!isFull()){

    int ind = _emptyCases.size();
    while ((ind >= 0) and (!res)){
      if(_emptyCases[ind] >= val){
      res = true;
      }
      ind--;
    }
  }
  
  return res;
}

