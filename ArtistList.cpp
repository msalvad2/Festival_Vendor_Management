//
//Miguel Salvador | Program #1 | October 8, 2025

#include "ArtistList.h"

List::List() : head(nullptr)
{}
List::List(const List & old_list) : head(nullptr) {
    
     copy_list(head, old_list.head);
    
}
//This function will handle operator assignment
List& List::operator=(const List & old_list) {
    
    if(this == &old_list)
        return *this;

    delete_all(head);//Deallocates all memory
    copy_list(head, old_list.head);//copies all the information over

    return *this;

}
//This will deallocate everything
List::~List(){

   delete_all(head); 

}
//This is the recursive call to copy everything from one LLL to another
int List::copy_list(ArtistNode*& dest, ArtistNode* src) {
   if(!src) {
       dest = nullptr;//finalizes the end of the new list
       return 1;
   }
   dest = new ArtistNode(*src);

   return copy_list(dest->get_next(), src->get_next() );
}
//This will delete all the dynamic mememory in the list
int List::delete_all(ArtistNode*& head) {
    if(!head) return 1;

    delete_all(head->get_next());
    delete head;
    head = nullptr;
    return 1;
}
int List::insert(const Artist & a_artist) {
    
    return insert(head, a_artist);

}
//This function will traverse to the end of the list then will add to the end
int List::insert(ArtistNode *& head, const Artist & a_artist) {

    if(!head) {
        head = new ArtistNode(a_artist);
        return 1;
    }
    return insert(head->get_next(), a_artist);
}

int List::remove_title(const char * a_title) {
    
    return remove_title(head, a_title);
}
//This functionw will compare a title passed in to every node in the list until
//it finds it then it will remove it, if no mach returns -1
int List::remove_title(ArtistNode *& head, const char * a_title) {
    
    if(!head) {
        cout << "NO MATCH!  " << endl;
        return -1;
    }
    if(head->compare_title(a_title)) {
       ArtistNode* hold = head->get_next();
       //ArtistNode* hold = head->next;
       delete head;
       head = hold;
       return 1;//succesfully deleted the node
    }
    return remove_title(head->get_next(), a_title);
}

//Wrapper to display all
int List::display() const{
    return display(head);
}
//Recursive call to display all
int List::display(ArtistNode * head) const {
    
    if(!head) return 1;

    display(head->get_next());
    
    head->display();

    return 1;
}
//This will find a mach wrapper 
bool List::find(const char * a_title, Artist & a_artist) const {

    return find(head, a_title, a_artist);
}
//This will find a mach recursive call by comparing title
bool List::find(ArtistNode* head, const char * a_title, Artist & a_artist) const {
    if(!head){
        cout << "Could not find the artis: " << a_title << endl;
        return false; //No Match
        }

    if(head->compare_title(a_title)) {
        cout << "There was a match" << endl;
        
        a_artist = *head;
        return true;
    }
    return find(head->get_next(), a_title, a_artist);
}
//This is the wrapper to delete all the nodes manually
int List::remove_all() {
    if(!head){
        cout <<"Empty List can't remove! " << endl;
        return -1;
    }

return delete_all( head);
}





/*j
//Functions to find the specific node then perform the node functions

int List::meet_greet_title(int payment) {
    if(!head) {
        cout << "List is Empty! " << endl;
        return -1;
    }
    char name[100];

    cout <<"Title of Artist: ";
    cin.get(name, 100, '\n');
    cin.ignore(100, '\n');

    return meet_greet_title(head, name, payment);


}
int List::meet_greet_title(ArtistNode* head, const char* title, int payment) {
    
    if(!head) {
            cout << "No Match" << endl;
            return -1;
    }
    if(head->compare_title(title)) {
            head->meet_greet(payment);
            return 1;
    }

    return meet_greet_title(head->get_next(), title, payment);
}
*/
