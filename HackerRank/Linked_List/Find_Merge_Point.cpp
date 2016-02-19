#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define row 100
#define col 100

struct Node{
	int data;
	struct Node* next;
};

struct Node *head, *hA, *hB;

Node* Insert (Node* head, int n){
	
	struct Node* tmp = (Node*)malloc( sizeof (struct Node) ); 
	tmp->data = n;
	tmp->next = NULL;
	if (head == NULL){ 
        //tmp->next = head;
	    return tmp;
    }
    
    struct Node* temp = head;
	while (temp->next != NULL) {
	   temp = temp->next;
	}
	temp->next = tmp;
	return head;
}

void Print (Node* head){
	//struct Node* tmp = head;
	
	//printf ("The List is: ");
	
	while ( head != NULL ){
		printf (" %d", head->data );
		head = head->next;	
	}
	puts ("");
}


int FindMergeNode(Node *matha_A, Node *matha_B) {
    Node *curr_A = matha_A;
    Node *curr_B = matha_B;


    while(curr_A != curr_B){
       
        if(curr_A->next == NULL){
            curr_A = matha_B;
        }
        else{
            curr_A = curr_A->next;
        }
        
        if(curr_B->next == NULL){
            curr_B = matha_A;
        }
        else{
            curr_B = curr_B->next;
        }
    }
    return curr_B->data;
}

int main(){
	int n, m, i, num_A, num_B;
	head = NULL;
	hA = NULL;
	hB = NULL;
	
	printf ("Enter the size of List A\n");
	scanf ("%d", &n);
	puts ("");
	
	printf ("Enter %d Numbers in head A: ", n);
	for (i = 0; i < n; i++){
		scanf ("%d", &num_A);
		hA = Insert (hA, num_A);
	}
	puts ("");
	
	printf ("Enter the size of List B\n");
	scanf ("%d", &m);
	puts ("");
	
	printf ("Enter %d Numbers in head A: ", m);
	for (i = 0; i < m; i++){
		scanf ("%d", &num_B);
		hB = Insert (hB, num_B);
	}
	puts ("");
	
	//int res = FindMergeNode (hA, hB);
	
	//printf ("The Marging Point value is: %d\n",  res);
	
	//head = RemoveDuplicates ( head );
	//Print (hB);

	return 0;
}


