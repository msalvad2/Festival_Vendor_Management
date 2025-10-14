//merch sub-child CLL
//Miguel Salvador | Program #1 | October 8, 2025
//This will create the merch class inheriting the vendor class, its unique members are merch_type,
//item_name, and stock. You will be able to buy merch, check how much of it is available,
//You will be able to display and sell to the booth.

#pragma once
#include "vendor.h"
#include <string>

class Merch:public Vendor {
    
    public:
    Merch();
    Merch( const char* a_title, const string & a_description, int a_price, 
    const string & a_merch_type, float a_discount, int a_stock); //argument constructor
    //Merch(const Merch & a_merch);//copy constructor
    //Merch& operator=(const Merch & a_merch); //assignment operator
    ~Merch();

    //This function will get the # of merch the user wants to buy from what the specific vendor
    //is selling (e.g five shirts, or seven posters);
    //Also if stock is less than specific # than apply discount(e.g 3 posters left, 20% discount)
    int buy_merch(int quantity, int payment);

    //This returns the total amount of merch that the specific vendor has (e.g five shirts left)
    //Also if stock is low then will apply a discount and promote that sale
    int check_availability() const;

    //This function will get the amount of merch the customer is wanting to sell, then buy it at a
    //70 percent, return the amount the customer made and update the new stock #
    float sell_to_booth(int quantity);
    
    //Display all private members
    int display();

    protected:

    private:

    string merch_type;
    float discount;
    int stock;

};
