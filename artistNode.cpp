
//Miguel Salvador | Program #1 | October 8, 2025
//Node for the child artist
#include "artistNode.h"

//default constructor
ArtistNode::ArtistNode() : Artist(), next(nullptr)
{}

ArtistNode::ArtistNode(const Artist & a_artist) : Artist(a_artist), next(nullptr)
{}
ArtistNode::ArtistNode(const ArtistNode & source) 
    :Artist(source), next(nullptr)
{}
//this will set the local node to point to the node passed in
void ArtistNode::set_next( ArtistNode *& next) {

    this -> next = next;
    
}
//This function will return the next pointer and you will be able to use it for 
//copy constructor because your are returning a reference &
//don't use const at the end out of the function because you may modify it
ArtistNode*& ArtistNode::get_next() {

    return next;
}

