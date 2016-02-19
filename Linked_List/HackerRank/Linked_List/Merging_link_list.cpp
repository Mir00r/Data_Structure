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

Node* MergeLists(Node *tmpA, Node *tmpB) { 
	
	/*	
	if(tmpB == NULL){ 
		return tmpA; 
	} 
	if(tmpA == NULL){ 
		return tmpB; 
	} 
	*/
	
	if(tmpA->next == NULL && tmpB->next == NULL){
    
		Node *matha = NULL;
		
		if(tmpA->data < tmpB->data){
			tmpA->next = tmpB;
			matha = tmpA;
		}
		else{
			tmpB->next = tmpA;
			matha = tmpB;
		}
		return matha;
	}
	
	Node *mainNode = new Node(); 
	Node *headC = mainNode;
	
	while(tmpA != NULL && tmpB != NULL){
		if(tmpA->data < tmpB->data){
			mainNode->next = tmpA;
			mainNode = mainNode->next;
			tmpA = tmpA->next;
		}
		else {
			mainNode->next = tmpB;
			mainNode = mainNode->next;
			tmpB = tmpB->next;
		}
	}
	
	if(tmpA != NULL) {
		mainNode->next = tmpA;
	}
	if(tmpB != NULL) {
		mainNode->next = tmpB;
	}
	headC = headC->next;

	return headC;
}


int main(){
	int n, m, i, num_A, num_B;
	head = NULL;
	hA = NULL;
	hB = NULL;
	
	printf ("Enter the size of array A\n");
	scanf ("%d", &n);
	puts ("");
	
	printf ("Enter %d Numbers in head A: ", n);
	for (i = 0; i < n; i++){
		scanf ("%d", &num_A);
		hA = Insert (hA, num_A);
	}
	puts ("");
	
	printf ("Enter the size of array B\n");
	scanf ("%d", &m);
	puts ("");
	
	printf ("Enter %d Numbers in head B: ", m);
	for (i = 0; i < m; i++){
		scanf ("%d", &num_B);
		hB = Insert (hB, num_B);
		
	}
	
	printf ("After Merging the list is: ");	
	head = MergeLists (hA, hB);
	Print (head);
	
	return 0;
}

