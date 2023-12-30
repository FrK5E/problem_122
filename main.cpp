
#include <vector>
#include <set>

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



  std::vector<int> combinations = {1}; 
  while (!all_elements_nonzero(result)) {

    std::map<int> new_combinations; 

    for ( std::size_t i=0; i<combinations.size(); i++ ) { 
        for ( std::size_t j=i; j<combinations.size(); j++ ) {

            int k = combinations[i]+combinations[j];

            


            
        }
    }



  }


}


int main( int argc, char * argv[] ) {

    std::vector<int> data;
    

    min_multiplications( 15, data );

    return 0;
}