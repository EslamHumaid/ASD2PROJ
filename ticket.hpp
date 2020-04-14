/**
* @file:  ticket.hpp
* @author: Eslam HUMAID , Abrahim BAMATRAF Groupe 485
* @date: 06/04/2020
* @git: https://github.com/EslamHumaid/ASD2PROJ
**/
#ifndef DEF_TICKET
#define DEF_TICKET

#include <string>

class Ticket{

    public:

    /**
     * @role:(constructor) create a ticket and generate the code of the ticket
     * */
    Ticket();


    /**
     * @role:(Destructor) distroying the object ticket
     * */
    ~Ticket();


    /**
     * @role: calculate the hashCode of the ticket.
     * @algo: the hashCode is obtained by the sum of all ASCII values of the characters of codeTicket multiplied by thier position in codeTicket.  
     * @return: the hash code
     * */
    size_t hash_code() const;

    /**
     * @role: overriding the operator == (testing the equality of two objects of the class Ticket )
     * */
    bool operator==(Ticket const& autre) const; 

    /**
     * Role: overriding the operator != (testing the inequality of two objects of the class Ticket )
     * */
    bool operator!=(Ticket const& autre) const; 

    /**
     * Specifying std::hash to the type ticket by defining the Hasher
     * */
    size_t operator()(const Ticket& x) const;

    struct ticketHasher{
        size_t operator()(const Ticket & obj) const{
            return obj.hash_code(); 
        } 
    };

    
    /**
     * @role: accesser for the code of the ticket
     * @return: the code of the ticket (string)
     * */
    std::string getCodeTicket() const;


    private:
    std::string _codeTicket;  //the randomly generated code of the ticket

  

    

    
};

#endif