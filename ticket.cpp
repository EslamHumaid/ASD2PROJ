#include "ticket.hpp"
#include <iostream>

using namespace std;

namespace std {
  template<> struct hash<Ticket> {
    size_t operator()(const Ticket& x) const
    {
      return x.hash_code();
    }
  };
}

Ticket::Ticket() {
   
    codeTicket = "";

    
     static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    

    for (unsigned int i = 0; i < 8 ; ++i)
    {
        codeTicket += alphanum[rand() % (sizeof(alphanum) - 1)];
    }


    
}

Ticket::~Ticket() {
}


size_t Ticket::hash_code() const{
    size_t hcode;

    for (int i=0;i<8;i++) {
        hcode = hcode + i*(int)codeTicket.at(i);
    }

    return hcode;
}

bool Ticket::operator==(Ticket const& autre) const{
    return codeTicket == autre.codeTicket;
}

bool Ticket::operator!=(Ticket const& autre) const{
    return codeTicket != autre.codeTicket;

    
}

string Ticket::getCodeTicket(){
    return codeTicket;
}







