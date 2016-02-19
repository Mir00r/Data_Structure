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
};


struct Tree_Node *New_Node (int val){
	Tree_Node *node = new Tree_Node; // creatting a new node using C++
	node->data = val;
	node->left = node->right = NULL;
	return node;
}

void swap (int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Print_Inorder ( Tree_Node *root ){
	if ( root != NULL ){
		Print_Inorder ( root->left );
		printf ("%d ", root->data);
		Print_Inorder ( root->right );
	}
}


// This function does inorder traversal to find out the two swapped nodes.
// It sets three pointers, first, middle and last.  If the swapped nodes are
// adjacent to each other, then first and middle contain the resultant nodes
// Else, first and last contain the resultant nodes

void Correct_BST_Util ( Tree_Node *root, Tree_Node **first, Tree_Node **middle, Tree_Node **last, Tree_Node **prev ){
	if ( root ){
		// Recure for the left Subtree
		Correct_BST_Util ( root->left, first, middle, last, prev );
		
		// if this node is smaller then the previous node, is violating the BST Rule 
		if ( *prev && root->data < (*prev)->data ){
			// if the first violation then mark this node as a 'first' and 'middle'
			if ( !*first ){
				*first = *prev;
				*middle = root;
			}
			// if this is sseconf violation then mark this node as a 'last'
			else
				*last = root;
		}
		// Mark this node as a Previous 
		*prev = root;
		
		// then recure the right Subtree
		Correct_BST_Util ( root->right, first, middle, last, prev );
		
	}
}


// A function to fix a given BST where two nodes are swapped.  This
// function uses Correct_BST_Util() to find out two nodes and swaps the
// nodes to fix the BST

void Fix_BST ( Tree_Node *root ){
	Tree_Node *first, *middle, *last, *prev;
	first = middle = last = prev = NULL; // Initialize all pointer
	
	// Set the Pointers to find out the nodes
	Correct_BST_Util (root, &first, &middle, &last, &prev);
	
	// Fix the tree 
	if ( first && last )
		swap ( &( first->data ), &( last->data ) );
	else if ( first && middle ) // for Adjecent node SWAP
		swap ( &( first->data ), &( middle->data ) );
}


int main (){

	/*      6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

	
    Tree_Node *root = New_Node(6);
    root->left        = New_Node(10);
    root->right       = New_Node(2);
    root->left->left  = New_Node(1);
    root->left->right = New_Node(3);
    root->right->right = New_Node(12);
    root->right->left = New_Node(7);
 
    printf("Inorder Traversal of the original tree \n");
    Print_Inorder ( root );
 
    Fix_BST ( root );
 
    printf("\nInorder Traversal of the fixed tree \n");
    Print_Inorder ( root );
	return 0;
}
