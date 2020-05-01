/**
* @file:  main.cpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 06/04/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/

#include <iostream>
#include "storage.hpp"
#include "ticket.hpp"
#include "bagage.hpp"
#include "backbag.hpp"
#include "vstorage.hpp"
#include <random>

using namespace std;

//making a function that prints a vector

void printFloatVector(vector<float> const &input)
{
	for (auto it = input.begin(); it != input.end(); it++){
		cout << *it << ' ';
	}
    cout << " " <<endl;
}

void printIntVector(vector<int> const &input)
{
	for (auto it = input.begin(); it != input.end(); it++){
		cout << *it << ' ';
	}
    cout << " " <<endl;
}


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
    
    cout <<"----------testing the class Ticket-----------" << endl;
    cout << " " << endl;
    cout << " " << endl;
    cout <<"testing Ticket::getCodeTicket()" << endl;

    cout <<"the code of the ticket t1 :" << t1.getCodeTicket()<< endl;
    cout <<"the code of the ticket t2 :" << t2.getCodeTicket()<< endl;
    cout << " " << endl;
    cout << " " << endl;

    cout <<"testing Ticket::operator==" << endl;
    cout <<"testing t1 == t2 expect false (0)" << endl;
    cout <<" t1 == t2 : " << (t1==t2) << endl;
    cout << " " << endl;
    cout << " " << endl;


    cout <<"testing t1 == t1 expect true (1)" << endl;
    cout <<" t1 == t1 : " << (t1==t1) << endl;
    cout << " " << endl;
    cout << " " << endl;
    
    cout <<"testing Ticket::operator!=" << endl;
    cout <<"testing t1 != t2 expect true (1)" << endl;
    cout <<" t1 != t2 : " << (t1!=t2) << endl;
    cout << " " << endl;
    cout << " " << endl;

    cout <<"testing Ticket::operator!=" << endl;
    cout <<"testing t1 != t1 expect false (0)" << endl;
    cout <<" t1 != t1 : " << (t1!=t1) << endl;
    cout << " " << endl;
    cout << " " << endl;


    cout <<"-----------testing the class Storage----------" << endl;
    cout << " " << endl;
    cout << " " << endl;


    cout <<"testing  Storage::isFull()" << endl;
    cout <<"before adding any baggage expect isFull() to be false (0)" << endl;
    cout <<"is mystorage full : " << myStorage.isFull() <<endl;
    cout << " " << endl;
    cout << " " << endl;


    cout <<"testing Storage::deposit by adding three bagage" << endl;
    t1 = myStorage.deposit(bag2);
    t2 = myStorage.deposit(bag1);
    t3 = myStorage.deposit(bag4);
    cout <<"after adding three bagage expect isFull() to be true (1)" << endl;
    cout <<"is mystorage full : " << myStorage.isFull() <<endl;
    cout << " " << endl;
    cout << " " << endl;


    cout <<"testing  Storage::collect by collecting three bagage" << endl;
    cout << "collecting the bagage linked to t1 expect 2 got : " << myStorage.collect(t1) << endl;
    cout << "collecting the bagage linked to t2 expect 1 got : " << myStorage.collect(t2) << endl;
    cout << "collecting the bagage linked to t3 expect 4 got : " << myStorage.collect(t3) << endl;


    
    cout <<"testing the second part of the project" <<endl;

    cout <<"----------testing the class Bagage-----------" << endl;

    //creating a couple of Bagages
    Backbag vbag1("a",10);
    Backbag vbag2("b",5);
    Backbag vbag3("c",200);
    Backbag vbag4("d",4);
    Backbag vbag5("e",30);

    cout <<"testing Bagage::getValume" << endl;
    cout << "show the valume of vbag1 expect 10 got  : " << vbag1.getVolume() <<endl;
    cout << "show the valume of vbag2 expect 5 got   : " << vbag2.getVolume() <<endl;

    cout <<"testing Bagage::getID" << endl;

    cout << "show the ID of vbag1 expect a got  : " << vbag1.getID() <<endl;
    cout << "show the ID of vbag2 expect b got  : " << vbag2.getID() <<endl;

    /*
    cout <<"testing Bagage::changeValume" << endl;

    cout << "show the valume of vbag1 expect 10 got  : " << vbag1.getVolume() <<endl;

    cout << "changing the valume of vbag1 to 20" << endl;

    vbag1.changeValume(20);

    cout << "show the valume of vbag1 expect 20 got  : " << vbag1.getValume() <<endl;
    */


    cout <<"----------testing the class VStorage-----------" << endl;

    //creating a VStorage
    VStorage vmyStorage(4);

    cout <<"testing VStorage::getValumes" << endl;

    vector<float> listOfVector = vmyStorage.getValumes();

    cout <<"showing the list of the valumes" << endl;
    printFloatVector(listOfVector);

    cout << "testing VStorage::isFull " <<endl;
    cout << "before adding any bagage expect 0 got : " << vmyStorage.isFull() <<endl;

    cout << "testing VStorage::deposit" <<endl;
    cout << "adding vbag1 and vbag2 expected to work" <<endl;
    Ticket vt1 = vmyStorage.deposit(vbag1);
    Ticket vt2 = vmyStorage.deposit(vbag2);
    cout << "vbag1 and vbag2 were added" <<endl;
    /*
    cout << "adding vbag3 expected not to work because vbag3 valume is 200" <<endl;
    Ticket vt3 = vmyStorage.deposit(vbag3);
    */

    cout << "testing VStorage::getEmptyCases" <<endl;
    cout <<"showing the list of the empty cases" << endl;

    vector<int> listOfEmptyCases = vmyStorage.getEmptyCases();
    printIntVector(listOfEmptyCases); //vbag1 and vbag2 took the smallest and least recently empty cases 

    
    cout << "adding vbag4 and vbag5 expected to work" <<endl;
    Ticket vt4 = vmyStorage.deposit(vbag4);
    Ticket vt5 = vmyStorage.deposit(vbag5);
    cout << " vbag4 and vbag5 were added" <<endl;

    cout << "testing VStorage::isFull " <<endl;
    cout << "after adding 4 bagages expect 1 got : " << vmyStorage.isFull() <<endl;


    cout << "testing VStorage::getEmptyCases" <<endl;
    cout <<"showing the list of the empty cases expected to be empty" << endl;

    listOfEmptyCases = vmyStorage.getEmptyCases();
    printIntVector(listOfEmptyCases);

    cout << "testing VStorage::collect" <<endl;
    cout << "collecting vbag1" <<endl;
    Bagage& cbag1 = vmyStorage.collect(vt1);

    cout << "getting the ID of cbag1 expect a got : " << cbag1.getID() << endl;

    
    cout << "testing VStorage::isFull " <<endl;
    cout << "after coolecting 1 bagage expect 0 got : " << vmyStorage.isFull() <<endl;

    cout << "testing VStorage::getEmptyCases" <<endl;
    cout <<"showing the list of the empty cases expected to have one case" << endl;

    listOfEmptyCases = vmyStorage.getEmptyCases();
    printIntVector(listOfEmptyCases);

}