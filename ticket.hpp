#ifndef DEF_TICKET
#define DEF_TICKET

#include <string>

class Ticket{

    public:

    Ticket();
    ~Ticket();
    size_t hash_code() const;
    bool operator==(Ticket const& autre) const; 
    bool operator!=(Ticket const& autre) const; 
    size_t operator()(const Ticket& x) const;

    struct ticketHasher{
        size_t operator()(const Ticket & obj) const{
            return obj.hash_code(); 
        } 
    };

    
    std::string getCodeTicket();


    private:
    std::string codeTicket;

  

    

    
};

#endif