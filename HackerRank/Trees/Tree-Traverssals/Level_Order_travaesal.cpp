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

struct Tree_Node{
	int data;
	struct Tree_Node *left;
	struct Tree_Node *right;
};


// this method allocate a new Tree_Node with the given data with NULL left and right pointer

struct Tree_Node* NewNode(int value){
	struct Tree_Node *node = (struct Tree_Node*)malloc ( sizeof (struct Tree_Node) ); // Creating a new Tree_Node 
	
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}

// Using single Queue
void Print_level_Order (Tree_Node *root){
	if (root == NULL)
		return;
		
	queue <Tree_Node*> Q;
	int nodes_in_curr_level = 1;
	int nodes_in_next_level = 0;
	
	Q.push (root);
	
	while ( Q.empty () == false){
		Tree_Node *curr_node = Q.front();
		Q.pop();
		nodes_in_curr_level--;
		
		if ( curr_node ){
			printf ("%d ", curr_node->data);
			Q.push (curr_node->left);
			Q.push (curr_node->right);
			nodes_in_next_level += 2;
		}
		
		if (nodes_in_curr_level == 0){
			// puts ("");
			//printf (" ");
			nodes_in_curr_level = nodes_in_next_level;
			nodes_in_next_level = 0;
		}
	}
}

// Using 2 Queue
void printLevelOrder(Tree_Node *root) {
  if ( root == NULL) 
	return;
  
  queue <Tree_Node*> currentLevel, nextLevel;
  currentLevel.push(root);
  
  while ( !currentLevel.empty() ) {
    Tree_Node *currNode = currentLevel.front();
    currentLevel.pop();
    
    if (currNode) {
      printf ("%d ", currNode->data);
      nextLevel.push(currNode->left);
      nextLevel.push(currNode->right);
    }
    
    if (currentLevel.empty()) {
      //puts ();
      swap(currentLevel, nextLevel);
    }
  }
}


// Using two method to print the binary tree by level order


/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
    
int height_cal (Tree_Node *node){
	int l_height, r_height;
	
	if (node == NULL)
		return 0;
	else{
		// compute the height of each subtree
		l_height = height_cal (node->left);
		r_height = height_cal (node->right);
		
		// compute longer one
		if (l_height > r_height)
			return ( l_height + 1 );
		else
			return ( r_height + 1 );
	}	
}


// method 2
void Print_Given_level (Tree_Node *rot, int level){
	if (rot == NULL)
		return;
	if ( level == 1)
		printf ("%d ", rot->data);
	else {
		Print_Given_level ( rot->left,  level - 1);
		Print_Given_level ( rot->right, level - 1 );
	}
}

// methode 1

void dekhao_level_order (Tree_Node *root){
	int h, i;
	h = height_cal (root);
	
	for (i = 1; i <= h; i++)
		Print_Given_level (root, i);
}

int main (){
	struct Tree_Node *root;
	
	root = NewNode (1);
	root->left = NewNode (2);
	root->right = NewNode (3);
	root->left->left = NewNode (4);
	root->left->right = NewNode (5);
	root->right->left = NewNode (6);
	root->right->right = NewNode (7);	
	
	printf ("The Top View of the Binary Tree is: ");
	//Print_level_Order(root);
	//printLevelOrder (root);
	dekhao_level_order (root);
	NL;
	
	return 0;
}
