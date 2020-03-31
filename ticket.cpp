#include "ticket.hpp"

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
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string codeTicket = "";

    for (int i=0;i<8;i++) {
        codeTicket = codeTicket + letters.at(rand() % letters.size());
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







