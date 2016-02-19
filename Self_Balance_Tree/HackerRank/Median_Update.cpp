#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1000002
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795

void Print_Median ( multiset <int> &choto, multiset <int> &boro ){
	if ( boro.size() == 0 ){
		puts ("Wrong!");
		return ;
	}
	
	// Even must do avarage 
	if ( choto.size () == boro.size() ){
		int big = *boro.begin();
		int small = *( --choto.end() );
		
		double medi = ( double ) big / 2 + ( double ) small/ 2;
		
		double whole;
        if ( modf ( medi, &whole ) == 0.0) {
            cout << (int) medi << endl;
        } 
        else {
			cout << setprecision(1) << fixed << medi << endl;
        }
        return;
	}
	
	//odd, simply first in greater set
	printf ("%d\n", *boro.begin () );
}

void Remove_Koro ( multiset <int> &choto, multiset <int> &boro, int num ){
	multiset <int> :: iterator it;
	
	if ( num < *boro.begin() ){
		it = choto.find( num );
		if ( it == choto.end()){
			puts ("Wrong!");
			return ;
		}
		choto.erase ( it );
	}
	else{
		it = boro.find( num );
		if ( it == boro.end()){
			puts ("Wrong!");
			return ;
		}
		boro.erase ( it );
	}
	
	// Rebalance korlam 
	if ( choto.size() - 1 == boro.size() ){
		int Move_Num = *( --choto.end() );
		//printf ("Rem_Moved_Num_1 = %d\n", Move_Num);
		choto.erase ( (--choto.end() ) );
		boro.insert ( Move_Num );
	}
	else if ( choto.size() + 2 == boro.size() ){
		int Move_Num = *boro.begin();
		//printf ("Rem_Moved_Num_2 = %d\n", Move_Num);
		//boro.erase ( Move_Num );
		boro.erase ( boro.begin() );
		choto.insert ( Move_Num );  
	}
	
	Print_Median ( choto, boro );
}


void Add_Koro ( multiset <int> &choto, multiset <int> &boro, int num ){
	multiset <int> :: iterator it;
	// value insert korlam
	if ( num < *boro.begin() ){
		choto.insert ( num );
		//it = choto.insert ( num );
		//printf ("Choto = %d\n", *it);
	}
	else{
		boro.insert ( num );
		//it = boro.insert ( num );
		//printf ("Boro = %d\n", *it);
	}
	// Rebalance korlam 
	if ( choto.size() - 1 == boro.size() ){
		int Move_Num = *( --choto.end() );
		//printf ("Add_Moved_Num_1 = %d\n", Move_Num);
		choto.erase ( (--choto.end() ) );
		boro.insert ( Move_Num );
	}
	else if ( choto.size() + 2 == boro.size() ){
		int Move_Num = *boro.begin();
		//printf ("Add_Moved_Num_2 = %d\n", Move_Num);
		//boro.erase ( Move_Num );
		boro.erase ( boro.begin() );
		choto.insert ( Move_Num );  
	}
	
	Print_Median ( choto, boro );
}


int main (){
	int n, val, i;
	multiset <int> boro;
	multiset <int> choto;
	
	char ch[2];
	
	scanf ("%d", &n);
	
	for ( i = 0; i < n; i++){
		scanf ("%s %d", ch, &val);
		
		if ( ch[0] == 'a')
			Add_Koro ( choto, boro, val );
		else
			Remove_Koro ( choto, boro, val );
	}
	return 0;	
}


/*
int main(){
	multiset <int> st;
	multiset <int> :: iterator it;
	
	st.insert (1);
	st.insert (2);
	st.insert (2);
	st.insert (4);
	st.insert (5);
	
	
	//cout << st.size();
	for ( it = st.begin(); it != st.end(); it++)
		printf ("%d\n", *it );
	return 0;
}
*/
