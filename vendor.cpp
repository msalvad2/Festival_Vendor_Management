//You got this remember!
//Miguel Salvador | Program #1 | October 8, 2025
//This will implement all of the functions for the vendor classs which includes,
//the constructor, destructor, assignment operator, comparing names, and handling payment

#include "vendor.h"

#include <cstring>

using namespace std;

//default constructor
Vendor::Vendor(): title(nullptr), description(""), price(0) {
}
//argument constructor
Vendor::Vendor(const char* a_title, const string & a_description, int a_price)
    :title(nullptr), description(a_description), price(a_price) {
    
    //performs a deep copy of the dynamic memory
    if(a_title) {
        title = new char[strlen(a_title) + 1];
        strcpy(title, a_title);
    }

    }
//copy constructor
Vendor::Vendor(const Vendor & a_vendor): title(nullptr), description(a_vendor.description), 
                                        price(a_vendor.price) {
    
    //perform deep copy
    if(a_vendor.title) {
        title = new char[strlen(a_vendor.title) + 1];
        strcpy(title, a_vendor.title);
    }
    //shallow copy
}
Vendor& Vendor:: operator=(const Vendor & a_vendor) {

    if(this == &a_vendor)
        return *this;

    if(title)
        delete[] title;
    title = nullptr;

    if(a_vendor.title) {
        title = new char[strlen(a_vendor.title) + 1];
        strcpy(title, a_vendor.title);
    }
    description = a_vendor.description;
    price = a_vendor.price;

    return *this;

}
//deconstructor
Vendor::~Vendor() {
    if(title)
        delete[] title;
    title = nullptr;
    description = "";
    price = 0;

}
//This function will check if the user paid enough money, if they did it will return the change
float Vendor::charge(int payment, double multiplier) {

    if(payment < price*multiplier)
        return -1;

    return (payment - (price*multiplier));
}


bool Vendor::compare_title(const char * a_title) {

    if(strcmp(title, a_title) == 0) return true;
    return false;
}
int Vendor::display() const {
    
    if(!title) {
        return -1;
    }
    cout << " Title: " << title << endl;
    cout << " Description: " << description << endl;
    cout << " Price: " << price << endl;
    return 1;
}
bool Vendor::display_title() const {
    cout << title << endl;
    return true;
}
float Vendor::display_cost(float multiplier) const {
    
        return price*multiplier;
}
