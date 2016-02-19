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


// Iterative method to find the height of binary tree

int Tree_Height (Node *rot){
	// Base case
	if (rot == NULL)
		return 0;
		
	// Create an empty queue for level order tarversal
	queue <Node *> Q;
	
	 // Enqueue Root and initialize height
	Q.push (rot);
	int height = 0;
	
	while (1){
		
		// nodeCount (queue size) indicates number of nodes
        // at current lelvel.
		int node_cnt = Q.size();
		if (node_cnt == 0)
			return height;
		else
			height++;
		
		// Dequeue all nodes of current level and Enqueue all
        // nodes of next level	
		while (node_cnt > 0){
			Node *node = Q.front();
			Q.pop();
			
			if (node->left != NULL)
				Q.push (node->left);
			if (node->right != NULL)
				Q.push (node->right);
			node_cnt--;
		}
	}
}

// Recursive method to find the Height of the tree
int cal_Tree_Height ( Node *rot ){
	if (rot == NULL)
		return 0;
	
	return max ( cal_Tree_Height (rot->left ), cal_Tree_Height (rot->right) ) + 1;
}

int main (){
	struct Node *root;
	
	root = NewNode (1);
	root->left = NewNode (2);
	root->right = NewNode (3);
	root->left->left = NewNode (4);
	root->left->right = NewNode (5);	
	
	printf ("The height of the Binary Tree is: %d", Tree_Height(root)  );
	NL;
	printf ("The height of the Binary Tree using recursive way which is: %d", cal_Tree_Height (root)  );
	
	return 0;
}


