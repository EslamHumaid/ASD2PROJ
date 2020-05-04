/**
* @file:  ticket.cpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 06/04/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/


#include "ticket.hpp"


using namespace std;

/**
    * @role:(constructor) create a ticket and generate the code of the ticket
 * */
Ticket::Ticket() {
   
    //generating a random string of 8 characters.
    _codeTicket = "";    
     static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";


    for (unsigned int i = 0; i < 8 ; ++i)
    {
        _codeTicket += alphanum[rand() % (sizeof(alphanum) - 1)];
    }


    
}

/**
    * @role:(Destructor) distroying the object ticket
    * since there aren't any dynamic allocations, no actions are needed.
* */
Ticket::~Ticket() {}



 /**
 * @role: calculate the hashCode of the ticket.
 * @algo: the hashCode is obtained by the sum of all ASCII values of the characters of codeTicket multiplied by thier position in codeTicket.  
 * @return: the hash code
* */
size_t Ticket::hash_code() const{
    size_t hcode;

    //calculating the hash code based on the code of the ticket
    for (int i=0;i<8;i++) {
        hcode = hcode + i*(int)_codeTicket.at(i);
    }

    return hcode;
}


/**
    * @role: overriding the operator ==  (testing the equality of two objects of the class Ticket )
* */
bool Ticket::operator==(const Ticket & autre) const{
    return _codeTicket == autre._codeTicket;
}


/**
    * @role: overriding the operator != (testing the inequality of two objects of the class Ticket )
**/
bool Ticket::operator!=(const Ticket & autre) const{
    return _codeTicket != autre._codeTicket;

    
}


/**
    * @role: accesser for the code of the ticket
    * @return: the code of the ticket (string)
* */
string Ticket::getCodeTicket() const{
    return _codeTicket;
}







