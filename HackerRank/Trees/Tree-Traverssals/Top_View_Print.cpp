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

void Traverse_left (Tree_Node *rot){
	if (rot == NULL)
		return;
		
	Traverse_left (rot->left);
	printf ("%d ", rot->data);
}

void Traverse_right (Tree_Node *rot){
	if (rot == NULL)
		return;
		
	printf ("%d ", rot->data);
	Traverse_right (rot->right);
}

void Print_Top_View (Tree_Node *rot){
	if (rot == NULL)
		return;
		
	Traverse_left (rot->left);
	printf ("%d ", rot->data);
	Traverse_right (rot->right);
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
	Print_Top_View(root);
	NL;
	
	return 0;
}


/*
void topview(Node root)
 {
     if(root==null)
      return;
     Stack<Integer> s=new Stack<Integer>();
     s.push(root.data);
     Node root2=root;
     while(root.left!=null)
     {
      s.push(root.left.data);
      root=root.left;
     }
     while(s.size()!=0)
      System.out.print(s.pop()+" ");

     Queue<Integer> q=new LinkedList<Integer>(); 
     q.add(root2.right.data);
     root2=root2.right;     
     while(root2.right!=null)
     {
      q.add(root2.right.data);
      root2=root2.right;
     }
     while(q.size()!=0)
      System.out.print(q.poll()+" ");
 }
*/
