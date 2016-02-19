#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 100002
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795

vector <int> graph[MAX];
int level[MAX];
int sparse_table[MAX][22];
int parent[MAX];


void DFS (int from, int u, int dep){
	int i;
	parent[ u ] = from;
	level[ u ] = dep;
	
	for ( i = 0; i < graph[ u ].size(); i++ ){
		int v = graph[ u ][ i ];
		if ( v == from )
			continue;
		DFS ( u, v, dep + 1 );
	}
}

int LCA_Query ( int n, int p, int q){ // where n is number of node
	int tmp, log, i;
	
	if ( level[ p ] < level[ q ] ){
		tmp = p;
		p = q;
		q = tmp;
	}
	
	// Confusing part 
	log = 1;
	while (1){
		int next = log + 1;
		if ( (1 << next) > level[ p ] )
			break;	
		log++;
	}
	
	
	// p এর লেভেল থেকে ২ এর পাওয়ার বিয়োগ করতে থাকবো এবং একই সাথে স্পার্স টেবিল ব্যবহার করে উপরে উঠাতে থাকবো যতক্ষণনা q এর লেভেলের সমান হয়।
	for ( i = log; i >= 0; i-- ){
		if ( level[ p ] - (1 << i) >= level[ q ] )
			p = sparse_table[ p ][ i ];
	}
	
	if ( p == q )
		return p;
	
	// এবার কাজ হবে দুইটা নোডকেও টেনে একসাথে উপরে উঠানো যতক্ষনা নোড দুটির প্যারেন্ট একসাথে এসে মিলে:
    for (i = log; i >= 0; i--)
		if ( sparse_table[ p ][ i ] != -1 && sparse_table[ p ][ i ] != sparse_table[ q ][ i ]){
              p = sparse_table[ p ][ i ];
              q = sparse_table[ q ][ i ];
         }

      return parent[ p ];
}


void LCA_init (int n){
	memo ( sparse_table, -1 ); // initially every index is -1
	int i , j;
	
	// এবার আমরা কলাম–বাই–কলাম টেবিলটা ভরাট করবো। প্রথমেই প্রথম কলাম ভরাট করবো যেটা আসলে T অ্যারের সমান।

	// টেবিলটা নাম P হলে প্রথম কলাম ভরাট করবো এভাবে
	for (i = 0; i < n; i++)
		sparse_table[ i ][ 0 ] = parent[ i ];
	
	
	//একটা নোডের ২^৪=১৬ তম প্যারেন্ট হলো নোডটার ২^৩=৮ম প্যারেন্টের ২^৩=৮ম প্যারেন্ট। তাহলে কোন নোডের 2^j তম প্যারেন্ট হবে 
	//নোডটার 2^(j-1) তম প্যারেন্টের 2^(j-1) তম প্যারেন্ট! তাহলে যেকোন নোড i এর জন্য:
	//P[i][j]=P[P[i][j – 1]][j – 1] যেখানে P[i][j – 1] হলো j-1 তম প্যারেন্ট।
	//তাহলে পুরো টেবিলটা ভরাট করে ফেলতে পারি এভাবে:	
	for (j = 1; (1 << j) < n; j++)
		for (i = 0; i < n; i++)
			if ( sparse_table[ i ][ j - 1 ] != -1)
				sparse_table[ i ][ j ] = sparse_table[ sparse_table[ i ][ j - 1 ] ][ j - 1 ];
}


int main (){
	graph[0].pb(1);
	graph[0].pb(2);
	graph[2].pb(3);
	graph[2].pb(4);
	
	DFS (0, 0, 0);
	LCA_init (5);
	printf ("%d\n", LCA_Query ( 5, 3, 4) );
	return 0;
}

