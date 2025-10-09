//
//Miguel Salvador | Program #1 | October 8, 2025
//This will implement the fucntions. It currentluy only has the constructors and destructors
//implemented
#include "merch.h"

Merch::Merch() : Vendor(), merch_type(""), item_name(""), stock(0) {

}

Merch::Merch( const char * a_title, const string & a_description, int a_price,
const string & a_merch_type, const string & a_item_name, int a_stock) 
    : Vendor(a_title, a_description, a_price), //Call Vendor's argument constructor
    merch_type(a_merch_type), item_name(a_item_name), stock(a_stock) 
    {}// I don't need to put anything for the body since there is no dynamic memory

Merch::~Merch() {
    merch_type = "";
    item_name = "";
    stock = 0;

}
