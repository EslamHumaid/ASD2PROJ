#include "ticket.hpp"
#include "storage.hpp"
#include "cassert"
#include <unordered_map>

using namespace std;

  typedef struct 
    {
        
        int indexInVect;
        bagage bag;
        
    } t_case;

namespace std {
  template<> struct hash<Ticket> {
    size_t operator()(const Ticket& x) const
    {
      return x.hash_code();
    }
  };
}



Storage::Storage(size_t nb){
    nbCases = nb;
    filledCases = 0;
    usingCase = 0;

}

Storage::~Storage(){}

bool Storage::isFull() const{
    return filledCases == nbCases;
}

Ticket Storage::deposit(bagage bagToAdd){
    assert(!isFull());
    int index;
    if(usingCase < nbCases){
        index = usingCase;
    }else{
        index = emptyCases.front();
        emptyCases.pop();
    }

    t_case caseToAdd;
    caseToAdd.indexInVect = index;
    caseToAdd.bag = bagToAdd;
    Ticket T;

    storage.insert(make_pair(T, caseToAdd));

    auto it = Cases.begin();
    it += index;
    Cases.insert(it,T);

    usingCase++;
    filledCases++;


}

bagage Storage::collect(Ticket T){
    t_case obtainedCase = storage.at(T);
    int index = obtainedCase.indexInVect;
    auto it = Cases.begin() + index;
    Cases.erase(it);
    emptyCases.push(index);
    storage.erase(T);

    filledCases--;

    return obtainedCase.bag;


}


