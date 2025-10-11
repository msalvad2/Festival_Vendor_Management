//

#include "merchNode.h"

class C_list {
    
    public:
    C_list();
    C_list(const C_list & a_list);
    C_list& operator=(const C_list & a_list);
    ~C_list();
    //will display the entire CLL
    int display() const;
    //This will add at the end fo the CLL (rear)
    int enqueue(const Merch & a_merch);
    //This will remove the first node(rear->next) but before it removes will copy the data over
    int dequeue( Merch & a_merch);
    //This Will find a node by title and return true if found
    bool find_match( const char* a_title);
    int peek(Merch & a_merch);


    private:
    MerchNode* rear;

    //This function will copy all information from the provided list to the new list
    //We will pass in rear(new_list), rear->next(old_list), rear(old_list)
    //We are treating it like a LLL and the old list rear will be the stopping condition
    int copy_all(MerchNode *& dest, MerchNode * src, MerchNode *rear);
    //Will remove all the nodes, by passing in rear->next and treating it like
    //a LLL
    int remove_all(MerchNode *& head);
    //recursively display all nodes
    int display(MerchNode * head) const;
    //recursively traverse list until finds match else NOT MATCH
    bool find_match( MerchNode* head, const char* a_title);

};
