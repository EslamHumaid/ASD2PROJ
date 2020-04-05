#include "ticket.hpp"
#include <iostream>

using namespace std;

/**
    * Role:(constructor) creat a ticket and generate the code of the ticket
 * */
Ticket::Ticket() {
   
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
    * Role:(Destructor) distroying the object ticket
* */
Ticket::~Ticket() {
}


/**
    * Role: craet the hash code.
    * return: the hash code
* */
size_t Ticket::hash_code() const{
    size_t hcode;

    //creating the hash code based on the code of the ticket
    for (int i=0;i<8;i++) {
        hcode = hcode + i*(int)_codeTicket.at(i);
    }

    return hcode;
}


/**
    * Role: overriding the operator ==
* */
bool Ticket::operator==(Ticket const& autre) const{
    return _codeTicket == autre._codeTicket;
}


/**
    * Role: overriding the operator !=
**/
bool Ticket::operator!=(Ticket const& autre) const{
    return _codeTicket != autre._codeTicket;

    
}


/**
    * Role: accesser for the code of the ticket
    * return: the cord of the ticket (string)
* */
string Ticket::getCodeTicket(){
    return _codeTicket;
}







