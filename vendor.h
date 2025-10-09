//Base class (parent)
//Miguel Salvador | Program #1 | October 8, 2025
//This .h file creates the base class Vendor which is the parent to all nodes


#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;

class Vendor {

    public: 
    Vendor();//default constructor
    Vendor(const char* a_title, const string & a_description,  int price);//argument constructor
    Vendor(const Vendor & a_vendor);//copy constructor
    Vendor& operator=(const Vendor & a_vendor);//assignment operator
    ~Vendor();

    //This function will see if customer has enought money if so
    //returns change
    int charge(int payment, double multiplier);
    //Returns true if match found
    bool compare_title(const char * a_title);
    //Display the contents 
    int display() const;

    private:
    char  * title;
    string description;
    protected:
    int price;

};


