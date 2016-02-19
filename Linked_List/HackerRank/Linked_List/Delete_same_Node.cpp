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


Node* RemoveDuplicates(Node *matha){
	
	if (matha == NULL)
		return NULL;
		
	Node *NextItem = matha->next;
	
	while ( NextItem != NULL && matha->data == NextItem->data ){
		NextItem = NextItem->next;
	}
	
	matha->next = RemoveDuplicates (NextItem);
	
	return matha;
}



int main(){
	int n, i, num_A;
	head = NULL;
	
	
	printf ("Enter the size of array A\n");
	scanf ("%d", &n);
	puts ("");
	
	printf ("Enter %d Numbers in head A: ", n);
	for (i = 0; i < n; i++){
		scanf ("%d", &num_A);
		head = Insert (head, num_A);
	}
	puts ("");
	printf ("After deleting the same number: ");
	
	head = RemoveDuplicates ( head );
	Print (head);

	return 0;
}


