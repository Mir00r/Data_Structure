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

struct Tree_Node{
	int data;
	struct Tree_Node *left, *right;
	int height;
};

struct Tree_Node *New_Node (int val){
	Tree_Node *node = new Tree_Node; // creatting a new node using C++
	node->data = val;
	node->left = node->right = NULL;
	node->height = 0;	// New node is initially added at leaf
	return node;
}

int Height (Tree_Node *node){
	if ( node == NULL )
		return -1;	
	return node->height;
}

int Weight ( Tree_Node *node ){
	if ( node == NULL )
		return 0;
	return  Height ( node->left ) - Height ( node->right )  ;
}

int cal_height( Tree_Node *n) {
    return max ( Height ( n->left ), Height ( n->right ) ) + 1;
}


struct Tree_Node *Left_Rotate ( Tree_Node *root ){
	Tree_Node *Old_Root = root;
	root = Old_Root->right;
	
	// Perform Rotation
	Old_Root->right = root->left;
	root->left = Old_Root;
	
	// Update Heights
	Old_Root->height = cal_height ( Old_Root );
	root->height = cal_height ( root );

	return root;
}

struct Tree_Node *Right_Rotate ( Tree_Node *root ){
	Tree_Node *Old_Root = root;
	root = Old_Root->left;
	
	// Perform Rotation
	Old_Root->left = root->right;
	root->right = Old_Root;
	
	// Update Heights
	Old_Root->height = cal_height ( Old_Root );
	root->height = cal_height ( root );

	return root;
}

struct Tree_Node *Balance_Factor ( Tree_Node *node ){
	int w = Weight ( node );
	
	if ( node == NULL || abs (w) <= 1 )
		return node;
		
	if ( w > 0 ){
		int wl = Weight ( node->left );
		// Left Right Cases
		if ( wl < 0 ){
			node->left = Left_Rotate ( node->left );
		}
		// only left left case
		return Right_Rotate ( node );
	}
	
	else{	
		int wr = Weight ( node->right );
		// Right Left Cases
		if ( wr > 0 ){
			node->right = Right_Rotate ( node->right );
		}
		// only for right right case
		return Left_Rotate ( node );
	} 
}

struct Tree_Node *insert( Tree_Node *root, int val) {
    
    if ( val < root->data ) {
        if (root->left == NULL) {
            root->left = New_Node ( val );
        } 
        else {
            root->left = insert ( root->left, val );
        }
    } 
    else if ( val > root->data ) {
		if ( root->right == NULL ) {
            root->right = New_Node ( val );
        } 
        else {
			root->right = insert ( root->right, val );
        }
    }
    root->height = cal_height ( root );
    
    return Balance_Factor ( root );
}


void Print_Preorder ( Tree_Node *root ){
	if (root == NULL)
		return;
			
	printf ("%d ", root->data );
	Print_Preorder ( root->left );
	Print_Preorder ( root->right );
}

bool trees_equal ( Tree_Node *n1, Tree_Node *n2 ){
	
    if ( n1 == NULL && n2 == NULL ) {
        return true;
    } 
    else if ( n1 == NULL || n2 == NULL || n1->data != n2->data ) {
        return false;
    }

    return trees_equal ( n1->left, n2->left ) && trees_equal ( n1->right, n2->right );
}



int main (){
	Tree_Node *root = NULL;
	
	root = New_Node ( 3 );	
	
	root = insert ( root, 2 );
	root = insert ( root, 4 );
	root = insert ( root, 5 );
	root = insert ( root, 6 );
 
	printf("Pre order traversal of the constructed AVL tree is \n");
	Print_Preorder ( root );
	
	NL;
	// Make a tree to compare against to ensure the balancing works correctly.
    Tree_Node *three = New_Node ( 3 );
    three->left = New_Node ( 2 );

    Tree_Node *five = New_Node ( 5 );
    five->left = New_Node ( 4 );
    five->right = New_Node ( 6 );

    three->right = five;

    if ( trees_equal ( root, three ) ) {
		puts ("AVL tree is balanced!");
    } 
    else {
		puts ("AVL tree is not balanced!");
    }
	
	return 0;
}
