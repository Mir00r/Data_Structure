#include <bits/stdc++.h>

using namespace std;

#define LI long int
#define LLI long long int
#define LL __int64
#define ULL unsigned long long
#define LLU long long unsigned
#define row 205
#define col 205
#define MAX 1006
#define jora pair <int, int>
#define memo(array, value) memset(array, value, sizeof(array))
#define pb push_back
#define NL puts ("")
#define inf (1 << 28)
#define eps 1e9
#define mod 7477777
#define PI 3.1415926535897932384626433832795


struct Tree_node{
    int data;
    struct Tree_node *left, *right;
};
  
// A utility function to create a new BST node
struct Tree_node *NewNode(int val){
    struct Tree_node *tmp =  (struct Tree_node *)malloc(sizeof (struct Tree_node));
    tmp->data = val;
    tmp->left = tmp->right = NULL;
    return tmp;
}
  
// A utility function to do inorder traversal of BST
void inorder(struct Tree_node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
  
/* A utility function to insert a new node with given key in BST */
struct Tree_node* Insertion (struct Tree_node* node, int value){
    /* If the tree is empty, return a new node */
    if (node == NULL) 
		return NewNode( value );
 
    /* Otherwise, recur down the tree */
    if ( value < node->data )
        node->left  = Insertion ( node->left, value );
    else if ( value > node->data )
        node->right = Insertion ( node->right, value );   
 
    /* return the (unchanged) node pointer */
    return node;
}
  
// Driver Program to test above functions
int main(){
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
       
    struct Tree_node *root = NULL;
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
    return 0;
}


/*
// A binary tree node has data, pointer to left child and pointer to right child

struct Tree_Node{
	int data;
	struct Tree_Node *left;
	struct Tree_Node *right;
};


// this method allocate a new Tree_Node with the given data with NULL left and right pointer

struct Tree_Node* NewNode(int val){
	struct Tree_Node *node = (struct Tree_Node*)malloc ( sizeof (struct Tree_Node) ); // Creating a new Tree_Node 
	
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}

// method for print the data Inorder Traversal in BST

void inorder ( struct Tree_Node *root){
	if (root != NULL){
		inorder ( root->left );
		printf ("%d ", root->data );
		inorder ( root->right );
	}
}


 //A method to insert a new node with given data in BST 
struct Tree_Node *Insertion ( struct Tree_Node *node, int data){
	
	// if there is empty return a new node
	if (node == NULL)
		NewNode ( data );
		
	if ( data < node->data)
		node->left = Insertion ( node->left, data );
	else if ( data > node->data)
		node->right = Insertion ( node->right, data );
	
	return node;
}

int main (){
	struct Tree_Node *root = NULL;
	
	  Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 

    root = Insertion ( root, 50);
    Insertion ( root, 30 );
    Insertion ( root, 20 );
    Insertion ( root, 40 );
    Insertion ( root, 70 );
    Insertion ( root, 60 );
    Insertion ( root, 80 );
  
    // print inoder traversal of the BST
    inorder(root);
	
	NL;
	
	return 0;
}
*/
