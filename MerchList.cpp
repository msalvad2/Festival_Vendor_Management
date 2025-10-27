//This declares the list implementation for Merch
//Miguel Salvador | Program #1 | October 8, 2025
#include "MerchList.h"

//Default Constructor
C_list::C_list() : rear(nullptr)
{}
//copy constructor
C_list::C_list(const C_list & a_list) : rear(nullptr) {
    
    if(a_list.rear)
        copy_all(rear, a_list.rear->get_next(), a_list.rear);

}
//Assignment Operator
C_list& C_list::operator=(const C_list & a_list) {
   
   //this checks to see if memory address is same if so can returns either pointer
    if(this == &a_list)
        return *this;
//
    remove_all(rear);

    copy_all(rear, a_list.rear->get_next(), a_list.rear);

    return *this;
}
//Destructor will remove all the nodes so NO MEMORY LEAK
C_list::~C_list() {

    if(rear) {
    remove_all(rear->get_next());
    }
}
//Copys every node to a new list. First arguemt: New empty list, 
//Second argument is first item in source list (rear->next)
//Third argument is source last node(rear) used as base case to know when reached end of list
int C_list::copy_all(MerchNode *& dest, MerchNode * src, MerchNode * rear) {
    if(src == rear) {
        dest = new MerchNode(*src);
        dest->set_next(this->rear);
        this->rear = dest;
        return 1;
    }
    dest = new MerchNode(*src);

    return copy_all(dest->get_next(), src->get_next(), rear);
}
//This will recursively remove all the nodes
int C_list::remove_all(MerchNode *& head) {
    if(head == this->rear) {
        delete head;
        head = nullptr;
        this->rear = nullptr;
        return 1;
    }
    MerchNode* hold = head->get_next();
    delete head;
    head = hold;

    return remove_all(head);
}
//wrapper display function
int C_list::display() const {

    if(!rear) return -1; //empty list

    return display(rear->get_next());

}
//This will recursively display every node
int C_list::display(MerchNode * head) const{
    if(head == this->rear) {
       head->Merch::display();
       return 1;
        }
    head->Merch::display();

    return display(head->get_next());


}
//This function will add a node O(1) at the end of the list(rear)
int C_list::enqueue(const Merch & a_merch) {

    if(!rear) {
        rear = new MerchNode(a_merch);
        rear->set_next(rear);
        return 1;
    }

    MerchNode* newNode = new MerchNode(a_merch);     
    newNode->set_next(rear->get_next());

    rear->set_next(newNode);

    rear = newNode;//sets rear to the last pointer in the list

    return 1;

}

//This function will remove the node at the beginning of the list(rear->next)
int C_list::dequeue( Merch & a_merch) {
    if(!rear) {
        cout<< "Cannot Remove because the list is empty! " << endl;
        return -1;
    }
    if(rear == rear->get_next()) {

        a_merch = *rear->get_next();
        delete rear;
        rear = nullptr;
        return 1;
    }
    //We are allowed to dereferenced rear twice since it is a CLL
    MerchNode* hold = rear->get_next()->get_next();    
    a_merch = *rear->get_next();
    delete rear->get_next();
    rear->set_next(hold);

    return 1;
}
//Wrapper function
//This function will find a match if true then copies the contents to the provided match
bool C_list::find_match(const char* a_title, Merch & a_merch) {
    if(!rear) {
        cout << "List is empty " << endl;
        return false;
    }
    
    return find_match(rear->get_next(), a_title, a_merch);    
}
//this is the recursive call to find the match
bool C_list::find_match(MerchNode* head, const char* a_title, Merch & a_merch) {

    if(head == this->rear) {
        
    if(head->compare_title(a_title)) {
        cout << "Match Found: " << endl;
        head->Merch::display();//try with Merch::display()
        a_merch = *head;
        return true;
    }
        cout << "No match found! " << endl;
        return false;
    }
    if(head->compare_title(a_title)){
        cout << "Match Found: " << endl;
        head->Merch::display();//try with Merch::display()
        a_merch = *head;
        return true;
    }

    return find_match(head->get_next(), a_title, a_merch);
}

//this copies the data into the argument, the first item
int C_list::peek( Merch & a_merch) {
    if(!rear) {
        cout << "List is Empty! " << endl;
        return -1;
    }
    a_merch = *rear->get_next();

    return 1;
}



//Wrapper removes all the list
int C_list::remove_all() {
    if(!rear) {
        cout << "Can't Remove empty list" << endl;
        return -1;
    }
    return remove_all(rear->get_next());
}
//This is the wrapper to remove by title
int C_list::remove_by_title(const char* a_title) {
   
   if(!rear) {
        cout << "List is empty " << endl;
        return -1;
   }
   if(rear->get_next() == rear) {
        delete rear;
        rear = nullptr;
        cout << "Successfully deleted the node " << endl;
        return 1;

   }

    return remove_by_title(rear->get_next(), a_title);
}
//Recursive call to make to recursive through list and remove the node by title
int C_list::remove_by_title(MerchNode*& head, const char* a_title) {
   
   if(head->get_next() == this->rear) {
        
        if(head->compare_title(a_title)) {
            
            MerchNode* hold = head->get_next();
            delete head;
            head = hold;
            cout << "Succesfully delete the node! " << endl;
            return 1;
        }
        if(head->get_next()->compare_title(a_title)) {
            
            MerchNode* hold = head->get_next()->get_next();
            this->rear = head;
            delete head->get_next();
            head->set_next(hold);

            cout <<"Succesfully deleted the node! " << endl;
            return 1;


        }
        cout << "Could not find match! " << endl;
        return -1;

   }
   if(head->compare_title(a_title)) {
        MerchNode* hold = head->get_next();
        delete head;
        head = hold;
        cout << "Succesfully delete the node! " << endl;
        return 1;
   }
    
    return remove_by_title(head->get_next(), a_title);
}



