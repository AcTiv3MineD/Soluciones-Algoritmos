#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int por_par( set<int> parejas );
int por_ad( set<int> parejas );

int main() {
	int n;
	
	while( cin >> n ){
		
		set<int>parejas;
		
		int res = 0;
		while( n-- ){
			int k;
			cin >> k;
			
			if( parejas.count( k ) )
				parejas.erase( k );
			else
				parejas.insert( k );
		}
		
		cout << min( por_par( parejas ), por_ad( parejas ) ) << endl;
	}
	return 0;
}


int por_par( set<int> parejas ){
	int res = 0;
	while( parejas.size() ){
		set<int>::iterator i = parejas.begin();
		set<int>::iterator j = parejas.begin();
		j++;
	
		int x = *i,y=*j;
		
		parejas.erase( *i );
		parejas.erase( *j );
		
		return min(  abs( x - y ), 24 - abs( x - y ) ) + min( por_par( parejas ), por_ad( parejas ) );
	}
	
	return res;
}

int por_ad( set<int> parejas ){
	int res = 0;
	while( parejas.size() ){
		set<int>::iterator i = parejas.begin();
		set<int>::reverse_iterator j = parejas.rbegin();
		int x = *i,y=*j;
		
		
		parejas.erase( *i );
		parejas.erase( *j );
		
		return  min( abs( x - y ), 24 - abs( x - y ) ) + min( por_ad( parejas ), por_par( parejas ) );
	}
	
	return res;
}