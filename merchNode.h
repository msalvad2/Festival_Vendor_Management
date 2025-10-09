//the node of merch
//Miguel Salvador | Program #1 | October 8, 2025
//This will declare the MerchNode which will inheret from the Merch
//It will be used to create the Circular Linked list
#pragma once

#include "merch.h"

class MerchNode : public Merch {
    
    public:
    //Constructor    
    MerchNode();
    //Argument constructor
    MerchNode(const Merch & a_merch);
    //This will set the current nodes next pointer to the node you pass in 
    void set_next( MerchNode * next);
    //This return the current nodes next pointers
    MerchNode * get_next() const;
    //Displays all data members
    int display() const;
    

    private:
    MerchNode * next;

};
