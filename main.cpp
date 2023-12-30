
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



  std::set<int> combinations = {1};
  int iter_nr=1; 
  while (!all_elements_nonzero(result)) {
    std::set<int> new_combinations; 
    for ( auto i : combinations ) { 
        for ( auto j:  combinations ) {

            int k = i+j;
            new_combinations.insert( k );
            if (result[k]==0) { 
                result[k] = iter_nr;
            }
        }
    }

    combinations.insert( new_combinations.begin(), new_combinations.end() );

  }

}


int main( int argc, char * argv[] ) {

    std::vector<int> data;
    

    min_multiplications( 15, data );

    return 0;
}