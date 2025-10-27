//
//Miguel Salvador | Program #1 | October 8, 2025

#include "merchNode.h"

//Default constructor
MerchNode::MerchNode() : Merch(), next(nullptr) 
{}

//Argument constructor
MerchNode::MerchNode(const Merch & a_merch) 
    :Merch(a_merch), next(nullptr)
{}
//copy constructor
MerchNode::MerchNode(const MerchNode & merch_node) :Merch(merch_node), next(nullptr)
{}
//sets the local next pointer to the node passed in
void MerchNode::set_next( MerchNode * next) {

    this->next = next;
}
//returns the next pointer
MerchNode*& MerchNode::get_next() {
    return next;
}
