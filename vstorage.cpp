/**
* @file:  vstorage.cpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 04/05/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/


#include "ticket.hpp"
#include "vstorage.hpp"
#include "bagage.hpp"
#include "cassert"
#include <unordered_map>
#include<iostream>
#include <random>


using namespace std;

// A struct to represnt the cases by the bag in them and there index in the vector
struct t_casev {
      
      int indexInCasesVolumes;
      Bagage &bag;

};  


typedef std::pair<Ticket,t_casev> t_entree; //an entry in the map


  /**
    * @role: (constructor): create an instance of the class VStorage with a list of pairs (ni,vi)
    * @pre: The list must not be empty.
    * @param: the list of pairs (ni,vi) with:
    * ni: is the number of cases that has a specific volume
    * vi: the specific volume
  **/
VStorage::VStorage(vector<pair<int,float>> list){
  //the storage must have a capacity greater then 0
  assert(list.size()>0);

  //initializing the attributs
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
    * @pre: the two lists must have the same size but they must not be empty.
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
  * @pre: the storage must have enough space for the bag.
  * @param: the bagage.
  * @return: a ticket that is linked to the bagage.
* */
Ticket VStorage::deposit(Bagage &bagToAdd){
  
    float volumeOfBag = bagToAdd.getVolume();

    //stops the program if the storage does not have a big enough case
    assert(haveSpace(volumeOfBag));

    
    int index = -1;  //the index of the case in the vector(_casesVolumes)
    float currentvol; //the current volume to compare with each volume
    int indexInEmptyCases; //the index of the case used to add it in _emptyCases
    float caseVolume; //the volume of the case

    for(int i = 0 ; i<=_emptyCases.size() ; i++){ //going through the empty cases
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
          //since _emptyCases is ordered by time of collecting, 
          //the first case of each volume is the only one that may be choosed as optimal case
          //so in the end, we would have found the case with the minimal enough volume and the least recently used.
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
    //creating a t_case and giving it the bagage and the index of the case in _casesVolumes
    t_casev caseToAdd = {index, bagToAdd};

    //adding the new bagage to the unordered map
    _storage.insert(make_pair(T, caseToAdd));


    //incressing the number of  filledCases
    _filledCases++;


  return T;

}

/**
  * @role:takes a ticket and returns the bagage linked to the ticket.
  * @pre: the storage should not be empty.
  * @param: the ticket.
  * @return: the bagage
* */
Bagage& VStorage::collect(Ticket T){
    //if the storage is empty we can not collect any bagage 
    assert(_filledCases>0);

    //searching the unordered map (storage) for the bagage linked to ticket (T)
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
  * @role: verify whether the storage has a case big enough for a certain volume.
  * @param: the volume.
  * @return: a boolean:
  * true if there is case big enough.
  * false if there is not.
* */
bool VStorage::haveSpace(float val) const{
  bool res = false;

  //if the storage is not full we check the volumes of the empty cases
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

