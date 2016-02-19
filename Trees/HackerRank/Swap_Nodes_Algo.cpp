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


void Print_Inorder ( Tree_Node *root, int dep, int k ){
	if (root == NULL)
		return;
	if ( dep % k == 0)
		swap ( root->right, root->left );
	
	Print_Inorder (root->left, dep + 1, k);
	printf ("%d ", root->data);
	Print_Inorder (root->right, dep + 1, k);
}


int main (){
	
	Tree_Node *root = New_Node (1);
	int N, a, b, i;
	int T, K;
	
	queue <Tree_Node*> Q;
	Q.push (root);
	
	scanf ("%d", &N);
	while ( Q.empty() == false && N-- ){
		Tree_Node *tmp1 = NULL, *tmp2 = NULL;
		Tree_Node *tmp = Q.front();
		Q.pop ();
		
		scanf ("%d %d", &a, &b);
		if ( a != -1)
			tmp1 = New_Node (a);
		if ( b != -1)
			tmp2 = New_Node (b);
			
		tmp->left = tmp1;
		tmp->right = tmp2;
		
		if (tmp1)
			Q.push (tmp1);
		if (tmp2)
			Q.push (tmp2);
	}
	
	scanf ("%d", &T);
	for (i = 1; i <= T; i++){
		scanf ("%d", &K);
		Print_Inorder (root, 1, K);
		NL;
	}
	
	return 0;
}
