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
	node->height = 1;	// New node is initially added at leaf
	return node;
}

int Height (Tree_Node *node){
	if ( node == NULL )
		return 0;	
	return node->height;
}

int cal_height( Tree_Node *n) {
    return max ( Height ( n->left ), Height ( n->right ) ) + 1;
}

int Balance_Factor ( Tree_Node *node ){
	if ( node == NULL )
		return 0;
	return Height ( node->left ) - Height ( node->right ) ;
}


struct Tree_Node *Right_Rotate ( Tree_Node *y ){
	Tree_Node *x = y->left;
	Tree_Node *T2 = x->right;
	
	// Perform Rotation
	x->right = y;
	y->left = T2;
	
	// Update Heights
	//x->height = max ( Height ( x->left ), Height ( x->right ) ) + 1;
	//y->height = max ( Height ( y->left ), Height ( y->right ) ) + 1;
	
	x->height = cal_height ( x );
	y->height = cal_height ( y );
	
	return x;
}


struct Tree_Node *Left_Rotate ( Tree_Node *x ){
	Tree_Node *y = x->right;
	Tree_Node *T2 = y->left;
	
	// Perform Rotation
	y->left = x;
	x->right = T2;
	
	// Update Heights
	//y->height = max ( Height ( y->left ), Height ( y->right ) ) + 1;
	//x->height = max ( Height ( x->left ), Height ( x->right ) ) + 1;
	
	x->height = cal_height ( x );
	y->height = cal_height ( y );

	return y;
}



struct Tree_Node *insert ( Tree_Node *root, int val ){
	if ( root == NULL )
		return New_Node ( val );
	
	if ( val < root->data )
		root->left = insert ( root->left, val );
	else
		root->right = insert ( root->right, val );

	// Update height of this ancestor node
	root->height = cal_height ( root );

	// Get the Balance Factor of this ancestor node and check whether this node become unbalanced
	int balance = Balance_Factor ( root );

	// if the node is unbalanced then there ar four cases to perform 
	
	// Left Left Cases
	if ( balance > 1 && val < root->left->data )
		return Right_Rotate ( root );
	// Right Right Cases 
	if ( balance < -1 && val > root->right->data )
		return Left_Rotate ( root );
	// Left Right Cases
	if ( balance > 1 && val > root->left->data ){
		root->left = Left_Rotate ( root->left );
		return Right_Rotate ( root );
	}	
	// Right Left Cases
	if ( balance < -1 && val < root->right->data ){
		root->right = Right_Rotate ( root->right );
		return Left_Rotate ( root );
	}
	
	return root;
}


void Print_Preorder ( Tree_Node *root ){
	if (root == NULL)
		return;
			
	printf ("%d ", root->data );
	Print_Preorder ( root->left );
	Print_Preorder ( root->right );
}


int main (){
	Tree_Node *root = NULL;
	
	// Constructing tree 
	/*
	root = insert ( root, 10 );
	root = insert ( root, 20 );
	root = insert ( root, 30 );
	root = insert ( root, 40 );
	root = insert ( root, 50 );
	root = insert ( root, 25 );
	*/
	root = insert ( root, 3 );
	root = insert ( root, 2 );
	root = insert ( root, 4 );
	root = insert ( root, 5 );
	root = insert ( root, 6 );

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */
 
	printf("Pre order traversal of the constructed AVL tree is \n");
	Print_Preorder ( root );
	return 0;
}
