#include <iostream>
#include "storage.hpp"
#include "ticket.hpp"

using namespace std;

int main(){
    Storage myStorage(3);
    bagage bag1 ="1";
    bagage bag2 = "2";
    bagage bag3 = "3";
    bagage bag4 = "4";

    Ticket t1;
    Ticket t2 = myStorage.deposit(bag2);
    Ticket t3 = myStorage.deposit(bag3);


    cout << "Ticket1" << t1.getCodeTicket() <<endl;






}