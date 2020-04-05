#include <iostream>
#include "storage.hpp"
#include "ticket.hpp"
#include <random>

using namespace std;


int main(){
    //craeting a storage with a capacity of 3 bagages
    Storage myStorage(3);
    //creating 4 different bagages
    bagage bag1 ="1";
    bagage bag2 = "2";
    bagage bag3 = "3";
    bagage bag4 = "4";

    //creating 3 different tickets
    Ticket t1,t2,t3;
    
    cout <<"testing the class Ticket" << endl;

    cout <<"testing Ticket::getCodeTicket()" << endl;

    cout <<"the code of the ticket t1 :" << t1.getCodeTicket()<< endl;
    cout <<"the code of the ticket t2 :" << t2.getCodeTicket()<< endl;


    cout <<"testing Ticket::operator==" << endl;
    cout <<"testing t1 == t2 expect false (0)" << endl;
    cout <<" t1 == t2 : " << (t1==t2) << endl;

    cout <<"testing t1 == t1 expect true (1)" << endl;
    cout <<" t1 == t1 : " << (t1==t1) << endl;

    
    cout <<"testing Ticket::operator!=" << endl;
    cout <<"testing t1 != t2 expect true (1)" << endl;
    cout <<" t1 != t2 : " << (t1!=t2) << endl;

    cout <<"testing Ticket::operator!=" << endl;
    cout <<"testing t1 != t1 expect false (0)" << endl;
    cout <<" t1 != t1 : " << (t1!=t1) << endl;

    cout <<"testing the class Storage" << endl;

    cout <<"testing  Storage::isFull()" << endl;
    cout <<"before adding any baggage expect isFull() to be false (0)" << endl;
    cout <<"is mystorage full : " << myStorage.isFull() <<endl;

    cout <<"testing Storage::deposit by adding three bagage" << endl;
    t1 = myStorage.deposit(bag2);
    t2 = myStorage.deposit(bag1);
    t3 = myStorage.deposit(bag4);
    cout <<"after adding three bagage expect isFull() to be true (1)" << endl;
    cout <<"is mystorage full : " << myStorage.isFull() <<endl;

    cout <<"testing  Storage::collect by collecting three bagage" << endl;
    cout << "collecting the bagage linked to t1 expect 2 got : " << myStorage.collect(t1) << endl;
    cout << "collecting the bagage linked to t2 expect 1 got : " << myStorage.collect(t2) << endl;
    cout << "collecting the bagage linked to t3 expect 4 got : " << myStorage.collect(t3) << endl;


}