//https://threads-iiith.quora.com/Treaps-One-Tree-to-Rule-em-all-Part-1
//https://en.wikipedia.org/wiki/Splay_tree

#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 100000l
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define PI 3.1415926535897932384626433832795

struct node {
    LLI value, size;
    int prev;
    node *left, *right;
}nodes[MAX];

LLI values[ MAX ];

//    Get Tree Size
LLI Height(node *p){
    //return p ? p->Height : 0;
	if ( p == NULL)
		return 0;
	return p->size;
}

LLI cal_height ( node *n) {
    return ( Height ( n->left ) + Height ( n->right )  + 1 );
}

//    Tree Operations
node *Merge ( node *l, node *r){
	
    if ( l == NULL ) return r;
    if ( r == NULL ) return l;

    if (l->prev > r->prev){
        l->right = Merge(l->right, r);
        l->size = cal_height (l);
        return l;
    }

    //    l is on left of r: append l to r's left
    r->left = Merge(l, r->left);
    r->size = cal_height (r);
    return r;
}

//    split tree p by inx, to l and r
void Split ( node *p, LLI inx, node *&l, node *&r ){
	
    if ( p == NULL ){
        l = r = NULL;
        return;
    }
    LLI cur = Height ( p->left ) + 1;
    
    if ( cur <= inx ){
        Split ( p->right, inx - cur, p->right, r );
        l = p;
    }
    else{
        Split ( p->left, inx, l, p->left );
        r = p;
    }
	p->size = cal_height ( p );
}

 
node *Extract ( node *&p, LLI from, LLI to ){
    node *l, *m, *r;

    Split ( p, from, l, m );
    Split ( m, to - from, m, r );
    p = Merge ( l, r );
    return m;
}

//    Traversal
LLI Preorder(node *p, LLI indx) {
	
    if ( p == NULL ) return indx;

    indx = Preorder ( p->left, indx );
    values[indx++] = p->value;
    return Preorder ( p->right, indx );
}

int main() {
	LLI i, n, m, opa, l, r;
	node *tree = NULL;
	
    for ( i = 0; i != MAX; i++) {
        //nodes[i].prev = rand();
        nodes[i].size = 1;
    }
	scanf ("%lld %lld", &n, &m);
    
    for ( i = 0; i != n; i++) {
        cin >> nodes[i].value;
        tree = Merge ( tree, nodes + i );
    }

    for ( i = 0; i != m; i++) {       
        
		scanf ("%lld %lld %lld", &opa, &l, &r);
        node *sub = Extract ( tree, l - 1, r );
        if ( opa == 1)
            tree = Merge ( sub, tree );
        else
            tree = Merge ( tree, sub );
    }

    //    Serialize tree
    Preorder ( tree, 0 );
    
    printf ("%lld\n", abs ( values[0] - values[n -1] ) );
    for ( i = 0; i < n; i++)
		printf ("%lld ", values[i] );
    NL;
    
    return 0;
}
