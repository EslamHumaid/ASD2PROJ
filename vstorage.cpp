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
        
        int indexInCasesVolumes;
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
    _casesVolumes.push_back(v);
    _emptyCases.push_back(i);
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
    int index = -1;
    float currentval;
    int indexInEmptyCases;
    for(int i = 0 ; i<=_emptyCases.size() ; i++){

      if(index == -1){

        if(_casesVolumes[_emptyCases[i]] >= valumeOfBag){
          index = _emptyCases[i];
          indexInEmptyCases = i;
          currentval =  _casesVolumes[_emptyCases[i]];
        }
      }else{
        if((_casesVolumes[_emptyCases[i]] >= valumeOfBag) && (_casesVolumes[_emptyCases[i]] < currentval) ){
          index = _emptyCases[i];
          indexInEmptyCases = i;
          currentval =  _casesVolumes[_emptyCases[i]];
        }
      }

    }

    //deleting the case chosen from _emptyCases
    _emptyCases.erase(_emptyCases.begin()+indexInEmptyCases);

    //craeting a t_case and give it the bagage and the valume 
    t_casev caseToAdd = {currentval, bagToAdd};
    
    //creating a ticket
    Ticket T;
    t_casev caseToAdd = {index, bagToAdd};

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
    //adding the index of the empty case to the queue(emptyCases)
    _emptyCases.push_back(obtainedCase.indexInCasesVolumes);
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
      if(_casesVolumes[_emptyCases[ind]] >= val){
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
  return _casesVolumes;
}

/**
 * @role: returns the vector _emptyCases to show all valumes of the empty cases
 * @return: the vector _emptyCases
 * */
vector<int> VStorage::getEmptyCases() const{
  return _emptyCases;
}

