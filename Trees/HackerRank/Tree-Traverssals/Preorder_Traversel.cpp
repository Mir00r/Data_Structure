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


// A binary tree node has data, pointer to left child and pointer to right child

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};


// this method allocate a new Node with the given data with NULL left and right pointer

struct Node* NewNode(int value){
	struct Node *node = (struct Node*)malloc ( sizeof (struct Node) ); // Creating a new Node 
	
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}


// Givern a binary tree, print it's node's in Preorder
void Print_Preorder (struct Node *node){
	if (node == NULL)
		return;
		
	// first print root node 
	printf ("%d ", node->data);
	
	// recure the laft child node subtree 
	Print_Preorder (node->left);
	
	// recure the right child node subtree
	Print_Preorder (node->right);
}

int main (){
	struct Node *root;
	
	root = NewNode (1);
	root->left = NewNode (2);
	root->right = NewNode (3);
	root->left->left = NewNode (4);
	root->left->right = NewNode (5);
	
	Print_Preorder (root);
	
	return 0;
}



