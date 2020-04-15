#include "ticket.hpp"
#include "vstorage.hpp"
#include "bagage.hpp"
#include "cassert"
#include <unordered_map>
#include<iostream>
#include <random>


using namespace std;

  // A struct to represnt the cases by the bag in them and there index in the vector
   struct t_casev 
    {
        
        float valumeOfCase;
        Bagage bag;

        
        
    }; 


typedef std::pair<Ticket,t_casev> t_entree;
/**
  * @role: (constructor): create an instance of the class Storage with a specific capacity
  * @param: the size of the storage 
**/
VStorage::VStorage(size_t nb){
  //the storage must have a capacity greater then 0
  assert(nb>0);

  _nbCases = nb;
  _filledCases = 0;
  _usingCase = 0;

  //adding the cases to _valumes and _emptyCases after giving them a random value for the valume
  for(int i = 0; i < _nbCases ; i++){
    float v; //the valume of the case
    v = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100)); // a random value of the valume
    _valumes.push_back(v);
    _emptyCases.push_back(v);
  }

}

/**
* Destructor
* @role: distroying the object storage
* since there aren't any dynamic allocations, no actions are needed.
* */
VStorage::~VStorage(){}

/**
  * @role: verify whether the storage is full or not.
  * @return: a boolean :
  * true if the storage is full
  * false if the storage is not full
* */
bool VStorage::isFull() const{
    //returns true if the number of filledCases is equal to the nbCases(capacity)
    return _filledCases == _nbCases;
}


/**
  * @role: takes a bagage and puts it in a Case.
  * @param: the bagage.
  * @return: a ticket that is linked to the bagage.
* */
Ticket VStorage::deposit(Bagage bagToAdd){
  
    float valumeOfBag = bagToAdd.getValume();
    //stops the program if the storage does not have a big enough case
    assert(haveSpace(valumeOfBag));
    //the index of the case in the vector(Cases)
    int index = -1; //the starting value is -1 to indicate that we didn't find a case yet 

    float currentval; // the valume of the chosen case that will be used

    //going through the vector _emptyCases to choose the oldest case that is 
    //big enough for the bagage
    for(int i = 0 ; i<=_emptyCases.size() ; i++){

      if(index == -1){ // if we don't have a case yest 
        if(_emptyCases[i] >= valumeOfBag){ // we only need to check that the current case is big enough
          index = i;
          currentval =  _emptyCases[i];
        }
      }else{// if we already have a case big enough we need to check 
            //if the current case is big enough for the bagage and it's smaller then the chosen case
        if((_emptyCases[i] >= valumeOfBag) and (_emptyCases[i] < currentval) ){
          index = i;
          currentval =  _emptyCases[i];
        }
      }

    }

    //deleting the case chosen from _emptyCases
    _emptyCases.erase(_emptyCases.begin()+index);

    //craeting a t_case and give it the bagage and the valume 
    t_casev caseToAdd = {currentval, bagToAdd};
    
    //creating a ticket
    Ticket T;
    

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));


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
Bagage VStorage::collect(Ticket T){
    //if the storage is empty we can not collect any bagage 
    assert(_filledCases>0);

    //searching the unordered map (storage) for the bagage linked to tickit (T)
    t_casev obtainedCase = _storage.at(T);
    //adding the case (it's valume) back to the vector _emptyCases
    //the case will be added to the end of the vector to maintain the order from old to new
    _emptyCases.push_back(obtainedCase.valumeOfCase);
    //erasing the cases from the unordered map (storage)
    _storage.erase(T);

    //decressing the number of filledCases
    _filledCases--;

    //returning the bagage
    return obtainedCase.bag;


}



/**
  * @role: verify whether the storage hase a case bigger enough for a certain valume.
  * @param: the valume.
  * @return: a boolean:
  * true if there is case bigger enough.
  * false if there is not.
* */
bool VStorage::haveSpace(float val) const{
  bool res = false;

  //if the storage is not full we check the sizes of the cases
  if(!isFull()){

    int ind = _emptyCases.size();

    while ((ind >= 0) and (!res)){
      if(_emptyCases[ind] >= val){ //if we found at least one case big enough we exit the loop
      res = true;
      }
      ind--;
    }
  }
  
  return res;
}

/**
 * @role: returns the vector _valumes to show all valumes of the storage
 * @return: the vector _valumes
 * */
vector<float> VStorage::getValumes() const{
  return _valumes;
}

/**
 * @role: returns the vector _emptyCases to show all valumes of the empty cases
 * @return: the vector _emptyCases
 * */
vector<float> VStorage::getEmptyCases() const{
  return _emptyCases;
}

