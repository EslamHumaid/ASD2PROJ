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
        Bagage &bag;
        
    };  


typedef std::pair<Ticket,t_casev> t_entree;


/**
  * @role: (constructor): create an instance of the class VStorage with a specific number of
  *         cases and a random value of volumes for each case
  * @param: the size of the storage 
**/
VStorage::VStorage(size_t nb){
  //the storage must have a capacity greater then 0
  assert(nb>0);

  _nbCases = nb;
  _filledCases = 0;

  //adding the cases to _casesVolumes and _emptyCases after giving them a random value for the volume
  for(int i = 0; i < _nbCases ; i++){
    float v; //the volume of the case
    v = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100)); // a random value for the volume
    _casesVolumes.push_back(v);
    _emptyCases.push_back(i);
  }

}

  /**
    * @role: (constructor): create an instance of the class VStorage with a list of pairs (ni,vi)
    * @param: the list of pairs (ni,vi) with:
    * ni: is the number of cases that has a specific volume
    * vi: the specific volume
  **/
VStorage::VStorage(vector<pair<int,float>> list){
  //the storage must have a capacity greater then 0
  assert(list.size()>0);

  _nbCases = 0;
  _filledCases = 0;
  int indOfCase =0;

  for(int i = 0; i < list.size();i++){ //going through each volume
    float v = list.at(i).second;
    for(int j = 0; j < list.at(i).first ; j++ ){ //creating the cases with the specific volume
      
      //adding the case to the vector of all cases (_casesVolumes)
      _casesVolumes.push_back(v);
      //adding the indix of the case to the vector of empty cases (_casesVolumes)
      _emptyCases.push_back(indOfCase);

      //incressing the indOfCase
      indOfCase++;
      //incressing the number of _nbCases
      _nbCases++;
    }
  }
}

  /**
    * @role: (constructor): create an instance of the class Storage with two lists vi and ni 
    * @param: the two lists with:
    * ni: is the number of cases that has a specific volume
    * vi: the specific volume
  **/
VStorage::VStorage(vector<float> volume, vector<int>num){

  //the storage must have a capacity greater then 0
  assert(volume.size()>0);
  //the size of the two lists must be equal
  assert(volume.size()==num.size());

  _nbCases = 0;
  _filledCases = 0;

  int indOfCase =0;

  for(int i = 0; i < volume.size();i++){ //going through each volume
    float v = volume.at(i);
    for(int j = 0; j < num.at(i); j++ ){//creating the cases with the specific volume

      //adding the case to the vector of all cases (_casesVolumes)
      _casesVolumes.push_back(v);

      //adding the indix of the case to the vector of empty cases (_casesVolumes)
      _emptyCases.push_back(indOfCase);

      //incressing the indOfCase
      indOfCase++;
      
      //incressing the number of _nbCases
      _nbCases++;
    }
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
Ticket VStorage::deposit(Bagage &bagToAdd){
  
    float volumeOfBag = bagToAdd.getVolume();

    //stops the program if the storage does not have a big enough case
    assert(haveSpace(volumeOfBag));

    //the index of the case in the vector(_casesVolumes)
    int index = -1;
    float currentvol;
    int indexInEmptyCases;
    float caseVolume;

    for(int i = 0 ; i<=_emptyCases.size() ; i++){
      caseVolume = _casesVolumes[_emptyCases[i]];
      
      if(index == -1){ //if we have not found a big enough case yet

        if(caseVolume >= volumeOfBag){
          index = _emptyCases[i];
          indexInEmptyCases = i;
          currentvol =  caseVolume;
        }
      }else{//if we have already found a big enough case 
            //we keep looking until we find the smallest case that is big enough
        if((caseVolume >= volumeOfBag) && (caseVolume < currentvol) ){
          index = _emptyCases[i];
          indexInEmptyCases = i;
          currentvol =  caseVolume;
        }
      }

    }

    //deleting the case chosen from _emptyCases
    _emptyCases.erase(_emptyCases.begin()+indexInEmptyCases);

     
    
    
    //creating a ticket
    Ticket T;
    //craeting a t_case and give it the bagage and the volume
    t_casev caseToAdd = {index, bagToAdd};

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));


    //incressing the number of  filledCases
    _filledCases++;


  return T;

}

/**
  * @role:takes a ticket and retuen the bagage linked to the ticket.
  * @param: the ticket.
  * @return: the bagage
* */
Bagage& VStorage::collect(Ticket T){
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
  * @role: verify whether the storage hase a case big enough for a certain volume.
  * @param: the volume.
  * @return: a boolean:
  * true if there is case big enough.
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
 * @role: returns the vector _casesVolumes to show all volumes of the storage
 * @return: the vector _casesVolumes
 * */
vector<float> VStorage::getVolumes() const{
  return _casesVolumes;
}

/**
 * @role: returns the vector _emptyCases to show all indices of the empty cases
 * @return: the vector _emptyCases
 * */
vector<int> VStorage::getEmptyCases() const{
  return _emptyCases;
}

