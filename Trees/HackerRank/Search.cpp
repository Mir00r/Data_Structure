#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 5
#define col 5
#define MAX 100000
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define MOD 7477777
#define PI 3.1415926535897932384626433832795
#define PrimeRange 1000000
#define CharRange 255


struct node {
    int data;
    struct node *lc, *rc;
};


struct node *NewNode ( int value ) {
    struct node *tmp = (struct node*) malloc( sizeof ( struct node) );

    tmp->data = value;
    tmp->lc = tmp->rc = NULL;

    return tmp;
}

struct node *Insertion ( struct node *n, int value ) {

    if ( n == NULL )
        return NewNode( value );

    if ( n->data > value ) {
        n->lc = Insertion( n->lc, value );
    }
    else {
        n->rc = Insertion ( n->rc, value );
    }

    return n;
}

struct node *Search ( struct node *n, int value ) {
    struct node *curr = n;
    printf ("Visiting element: ");

    while ( curr->data != value ) {
        if ( curr != NULL )
            printf ("%d\n", curr->data );

        if ( curr->data > value )
            curr = curr->lc;
        else
            curr = curr->rc;

        if ( curr == NULL )
            return NULL;
    }

    return curr;
}

void inorder(struct node *root){
    if (root != NULL){

        inorder( root->lc );
        printf("%d ", root->data );
        inorder( root->rc );
    }
}



int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    struct node *root = NULL;
    root = Insertion (root, 50);
    Insertion ( root, 30 );
    Insertion ( root, 20 );
    Insertion ( root, 40 );
    Insertion ( root, 70 );
    Insertion ( root, 60 );
    Insertion ( root, 80 );

    // print inoder traversal of the BST
    inorder ( root );
	NL;

    struct node *tmp = NULL;

	tmp =  Search( root , 20 );

    if ( tmp != NULL )
        printf ("Element Found -> %d\n", tmp->data);
    else
        puts ("Element Not Found");
    return 0;
}
