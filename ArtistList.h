//

#include "artistNode.h"


class List {
    

    public:
    //Default constructor
    List();
    //This is the copy constructor, it will take in an already existing list
    //Then it will copy everything to the local list
    List(const List & old_list);
    //Assignment operateor
    //This will copy data from an artist node to an already existing artist node
    List& operator=(const List & old_list);
    //Deallocate the entire LLL
    ~List();
    //Will add an artist node the the LLL, always at beginning
    int insert(const Artist & a_artist);
    int remove_title(const char * a_title);
    int display() const;
    bool find(const char * a_title) const;


    private:
    ArtistNode* head;
    //This function will be called by the copy constructor it is what will recursively
    //copy everything from the list provided to the local list
    int copy_list(ArtistNode*& dest, ArtistNode* src);
    int delete_all(ArtistNode*& head);
    int insert(ArtistNode *& head, const Artist & a_artist);
    int remove_title(ArtistNode *& head, const char * a_title);
    int display(ArtistNode * head) const;
    bool find(ArtistNode* head, const char * a_title) const;


};


