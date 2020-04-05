#ifndef DEF_TICKET
#define DEF_TICKET

#include <string>

class Ticket{

    public:

    /**
     * Role:(constructor) creat a ticket and generate the code of the ticket
     * */
    Ticket();


    /**
     * Role:(Destructor) distroying the object ticket
     * */
    ~Ticket();


    /**
     * Role: craet the hash code.
     * return: the hash code
     * */
    size_t hash_code() const;

    /**
     * Role: overriding the operator ==
     * */
    bool operator==(Ticket const& autre) const; 

    /**
     * Role: overriding the operator !=
     * */
    bool operator!=(Ticket const& autre) const; 

    /**
     * 
     * */
    size_t operator()(const Ticket& x) const;

    struct ticketHasher{
        size_t operator()(const Ticket & obj) const{
            return obj.hash_code(); 
        } 
    };

    
    /**
     * Role: accesser for the code of the ticket
     * return: the cord of the ticket (string)
     * */
    std::string getCodeTicket();


    private:
    std::string _codeTicket;

  

    

    
};

#endif