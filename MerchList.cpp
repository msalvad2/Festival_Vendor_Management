//
#include "MerchList.h"

//Default Constructor
C_list::C_list() : rear(nullptr)
{}
//copy constructor
C_list::C_list(const C_list & a_list) : rear(nullptr) {

    copy_all(rear, a_list.rear->get_next(), rear);

}
//Assignment Operator
C_list& C_list::operator=(const C_list & a_list) {
   
   //this checks to see if memory address is same if so can returns either pointer
    if(this == &a_list)
        return *this;

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
        dest->set_next(this->rear);
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

bool C_list::find_match(const char* a_title) {
    
    return find_match(rear->get_next(), a_title);    
}

bool C_list::find_match(MerchNode* head, const char* a_title) {

    if(head == this->rear) {
        
    if(head->compare_title(a_title)) {
        cout << "Match Found: " << endl;
        head->Merch::display();//try with Merch::display()
        return true;
    }
        cout << "No match found! " << endl;
        return false;
    }
    if(head->compare_title(a_title)){
        cout << "Match Found: " << endl;
        head->Merch::display();//try with Merch::display()
        return true;
    }

    return find_match(head->get_next(), a_title);
}


int C_list::peek( Merch & a_merch) {
    if(!rear) {
        cout << "List is Empty! " << endl;
        return -1;
    }
    a_merch = *rear->get_next();

    return 1;
}




