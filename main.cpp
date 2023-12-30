
#include <vector>
#include <set>
#include <iostream>
#include <functional>

#include "Node.h"



class LeafCollector { 
    public:

    void processNode( Node &  node ) { 
        if (node.children.empty()) { 
            leafs.insert( &node );
        }
    }

    private: 
    std::set<Node *> leafs; 
};


void visit_all( Node & root, std::function<void(Node &)> action ){

    for ( auto n :  root.children ) {
        action( *n );
        visit_all( *n, action );
    }
}; 


void min_multiplications( int max, std::vector<int> & result ){ 
  // identify the minimal number of multiplications to calculate exponential a^n 

  result.resize(max+1); 
  for( auto & i : result ) {
    i=0; 
  }

  result[0] = 1;
  result[1] = 1;



  Node root(nullptr);

  LeafCollector a; 
  visit_all(root, [&a] (Node & node ) { a.processNode(node); } ); 

  ;
  

  



}


int main( int argc, char * argv[] ) {

    std::vector<int> data;
    

    min_multiplications( 15, data );
    
    size_t idx=0;
    for ( auto i: data ) { 
        std::cout<< idx << "  " << i << std::endl;
        idx++;
    }

    return 0;
}