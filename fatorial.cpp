#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <boost/algorithm/string.hpp>
// g++ -o b b.cpp

using std::string;
using std::getline;
using namespace std;
//using namespace boost;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main() {

	int iterador= 1;
	int n, i;
    int fat;
	char result;
	stringstream ss;

	while(scanf("%d",&n)!=EOF){ 

		fat = 1;
		for (i=1; i<=n; i++) {
			fat = fat * i;
		}
		cout << "Instancia " << iterador << endl;
		//cout << "FAT :" << fat << endl;
		std::string a = patch::to_string(fat);
		if(a != "inf"){
			for(i=a.size()-1; i>=0; i--){
				if(a[i] != '0'){
					result = a[i];
					break;
				}
			}
			cout << result << endl;
		}
		iterador++;
		cout << endl;
	}
	return 0;
}