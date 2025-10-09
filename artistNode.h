//The node of Artist
//Miguel Salvador | Program #1 | October 8, 2025
//This will declare the MerchArtist class which  inherets the Artist class.
//It will be used in the Linear Linked List
#pragma once

#include "artist.h"

class ArtistNode : public Artist{
   
   public:
    ArtistNode();
    ArtistNode(const Artist & a_artist);//copy constructor

    //This function will set the locals nodes next pointer to the node that gets passed
    void set_next(const ArtistNode*& next);

    //This function will return the next pointers, essentially gives you access to it
    ArtistNode* get_next() const;

    void display();//Displays the nodes information
    


   private:

    ArtistNode * next;

};
