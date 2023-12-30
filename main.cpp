
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
    std::set<Node *> leafs; 
};

class ParentsNumbers { 
    public: 

    void processNode( const Node & node ) { 
        numbers.push_back( node.number );
    } 
    std::vector<int> numbers; 
};




void visit_all( Node & root, std::function<void(Node &)> action ){
    action(root);
    for ( auto n :  root.children ) {
        visit_all( *n, action );
    }
}; 

void visit_parents( const Node & root, std::function<void(const Node&)> action) { 
    action(root); 
    if (root.parent) { 
        visit_parents(*root.parent, action);
    }
}



bool all_elements_nonzero( std::vector<int> & array ) {
 
    for ( const auto & i: array ) { 
        if (i==0) { 
            return false;
        }
    }
    return true;
}


void min_multiplications( int max, std::vector<int> & result ){ 
  // identify the minimal number of multiplications to calculate exponential a^n 

  result.resize(max+1); 
  for( auto & i : result ) {
    i=0; 
  }

  result[0] = 1;
  result[1] = 1;



  Node root(nullptr, 1);

  int iter_nr = 1;
  while ( !all_elements_nonzero(result)) { 
    LeafCollector a; 
    visit_all(root, [&a] (Node & node ) { a.processNode(node); } ); 

    for ( auto leaf: a.leafs ) { 
        ParentsNumbers parents; 
        visit_parents( *leaf , [&parents](const Node & node) { parents.processNode(node); } );

        int n1 = parents.numbers[0];
        for ( auto n: parents.numbers) { 

            int new_number = n*n1;
            Node * iter = new Node( leaf, new_number );
            if  ( new_number<=max) { 
                result[new_number] = iter_nr;
            }

        }

    }

    iter_nr++; 

  }
  

  


  



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