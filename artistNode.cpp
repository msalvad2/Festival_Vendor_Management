

#include "artistNode.h"

ArtistNode::ArtistNode() : Artist(), next(nullptr)
{}

ArtistNode::ArtistNode(const Artist & a_artist) : Artist(a_artist), next(nullptr)
{}

ArtistNode::ArtistNode(const ArtistNode & source) 
    :Artist(source), next(nullptr)
{}
void ArtistNode::set_next( ArtistNode *& next) {

    this -> next = next;
    
}
//This function will return the next pointer and you will be able to use it for 
//copy constructor because your are returning a reference &
//don't use const at the end out of the function because you may modify it
ArtistNode*& ArtistNode::get_next() {

    return next;
}

