#include "ticket.hpp"

using namespace std;

//hash function to override the (operator())
namespace std {
  template<> struct hash<Ticket> {
    size_t operator()(const Ticket& x) const
    {
      return x.hash_code();
    }
  };
}

 /**
    * Role:(constructor) creat a ticket and generate the code of the ticket
 * */
Ticket::Ticket() {
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string _codeTicket = "";

    //picking random characters from letters
    for (int i=0;i<8;i++) {
        _codeTicket = _codeTicket + letters.at(rand() % letters.size());
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







