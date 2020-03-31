#include <iostream>
#include <random>

using namespace std; 

string generateCipher(){

    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string cipher; 

    for (unsigned int i = 0; i < 8 ; ++i)
    {
        cipher += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return cipher; 
    
}

int main(){
    cout << generateCipher()<<endl;
    cout << generateCipher()<<endl;
    cout << generateCipher()<<endl;

}