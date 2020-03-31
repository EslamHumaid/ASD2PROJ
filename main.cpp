#include <iostream>
#include "storage.hpp"
#include "ticket.hpp"
#include <random>

using namespace std;


int main(){
    Storage myStorage(3);
    bagage bag1 ="1";
    bagage bag2 = "2";
    bagage bag3 = "3";
    bagage bag4 = "4";
    
    Ticket t1,t2,t3;
    
    t1 = myStorage.deposit(bag2);
    t2 = myStorage.deposit(bag1);
    t3 = myStorage.deposit(bag4);
    


    cout << myStorage.isFull() << endl;


    cout << myStorage.collect(t1) << endl;
    cout << myStorage.isFull() << endl;
    t3 = myStorage.deposit(bag4);
    cout << myStorage.isFull() << endl;
    cout << myStorage.collect(t3) << endl;


    



   




}