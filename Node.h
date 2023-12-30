#include <set>

#pragma once 

struct Node { 
    
    Node( const Node * parent, int number  ): parent(parent), number(number) { };
    int number;
    const Node * parent;
    std::set<Node *> children;

};

