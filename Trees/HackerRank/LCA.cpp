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

// Method 1 (By Storing root to n1 and root to n2 paths):
// Time Complexity: Time complexity of the above solution is O(n). The tree is traversed twice, and then path arrays are compared.

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

// Finds the path from root node to given root of the tree, Stores the
// path in a vector path[], returns true if path exists otherwise false

bool Find_Path ( Tree_node *root, vector <int> &path, int val ){
	
	// Base Case
	if ( root == NULL )
		return false;
	// Store this node in path vector, the node will be removed if not in path from 'root' to 'val'
	path.pb( root->data );
	
	// Check if the 'val' is same as roots data
	if ( root->data == val )
		return true;
		
	// Check if the 'val' is found in left or right subtree
	if ( ( root->left && Find_Path ( root->left, path, val ) ) || ( root->right && Find_Path ( root->right, path, val ) ) )
		return true;
		
	// if not present in subtree rooted with root then remove root from path vector and return false
	path.pop_back();
	return false;
}

// Returns LCA if node n1, n2 are present in the given binary tree,
// otherwise return -1

int Find_LCA ( Tree_node *root, int n1, int n2 ){
	int i;
	// Create two vector to store path from root to n1 and n2
	vector <int> path_1, path_2;
	
	// Find paths from root to n1 and root to n1. If either n1 or n2
    // is not present, return -1
    
    if ( Find_Path (root, path_1, n1) == false || Find_Path ( root, path_2, n2 ) == false )
		return -1;
	
	// Compare the paths to get the first different value	
	for (i = 0; i < path_1.size() && i < path_2.size(); i++){
		if ( path_1[i] != path_2[i] )
			break;
	} 
	
	return path_1[ i - 1 ];
}



// Method 2 (Using Single Traversal)
// Time Complexity: Time complexity of the above solution is O(n) as the method does a simple tree traversal in bottom up fashion.

// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
Tree_node *Find_lca (Tree_node *root, int v1, int v2){
			
	if ( root == NULL )
		return root;
	// If either n1 or n2 matches with root's data, report
    // the presence by returning root (Note that if a data is
    // ancestor of other, then the ancestor key becomes LCA

	if ( root->data == v1 || root->data == v2 )
		return root;

	// look for data in left and right subtree
	Tree_node *left_lca = Find_lca ( root->left, v1, v2 );
	Tree_node *right_lca = Find_lca ( root->right, v1, v2 );

	// If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    
    if ( left_lca && right_lca )
		return root;
	
	// otherwisw check left or right subtree
	
	if ( left_lca != NULL )
		return left_lca;
	else
		return right_lca;
}


// Driver Program to test above function	s
int main(){
    
    struct Tree_node *root = NULL;
    /*
    root = Insertion (root, 50);
    Insertion ( root, 30 );
    Insertion ( root, 20 );
    Insertion ( root, 40 );
    Insertion ( root, 70 );
    Insertion ( root, 60 );
    Insertion ( root, 80 );
    printf ("LCA (20, 40) = %d\n", Find_LCA (root, 20, 40) );
    printf ("LCA (20, 60) = %d\n", Find_LCA (root, 20, 60) );
    printf ("LCA (70, 20) = %d\n", Find_LCA (root, 70, 20) );
    printf ("LCA (30, 20) = %d\n", Find_LCA (root, 30, 20) );
    */
    
    root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);
    
    printf ("LCA (4, 5) = %d\n", Find_LCA (root, 4, 5) );
    printf ("LCA (4, 6) = %d\n", Find_LCA (root, 4, 6) );
    printf ("LCA (3, 4) = %d\n", Find_LCA (root, 3, 4) );
    printf ("LCA (2, 4) = %d\n", Find_LCA (root, 2, 4) );
    
    printf ("LCA (4, 5) = %d\n", Find_lca (root, 4, 5)->data );
    printf ("LCA (4, 6) = %d\n", Find_lca (root, 4, 6)->data );
    printf ("LCA (3, 4) = %d\n", Find_lca (root, 3, 4)->data );
    printf ("LCA (2, 4) = %d\n", Find_lca (root, 2, 4)->data );
    
    return 0;
}


